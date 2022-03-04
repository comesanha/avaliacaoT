/********************************************************************************************
  * File:   serial_uart.cpp
 * Author: Raphael Comesanha
 * Adapted from //Adaptado de https://aticleworld.com/serial-port-programming-using-win32-api/
 * Function: Configurar, abrir e executar transmissão e recepção de dados da UART.
 * Created on Fevereiro de 2022.
 * Last Modification:
 * Author Modification: 
 * Modified on
 * 
 * # Compilado no windows 10 PowerShell
 * # Linha de comando: g++ -o test Node.h
 **********************************************************************************************/

#ifndef SERIAL_UART_CPP
      #define SERIAL_UART_CPP

#include "serial_uart.h"
#include <iostream>

Serial::Serial()
{
  dcbSerialParams = { 0 };    // Initializing DCB structure
  timeouts = { 0 };           //Initializing timeouts structure
  SerialBufferR[64] = { 0 };  // Buffer pata receber dados
  SerialBufferT[4] = { 0 };  //Buffer para enviar comando de carregamento de log
  BytesWritten = 0;           // No of bytes written to the port
  loop = 0;
  pcCommPort = "COM5";
}

Serial::~Serial()
{
  CloseHandle(hComm);//Closing the Serial Port
  std::cout << "\nPorta Fechada!\n" << std::endl;
}

void Serial::OpenSerial()
{
  //Abre a porta serial definida em pcCommPort e implementa algumas configurações iniciais.

    hComm = CreateFile(pcCommPort,                        //friendly name
                       GENERIC_READ | GENERIC_WRITE,      // Read/Write Access
                       0,                                 // No Sharing, ports cant be shared
                       NULL,                              // No Security
                       OPEN_EXISTING,                     // Open existing port only
                       0,                                 // Non Overlapped I/O
                       NULL);                             // Null for Comm Devices
    if (hComm == INVALID_HANDLE_VALUE)
    {
        std::cout << "\n Porta COM5 sem acesso!" << std::endl;
        CloseHandle(hComm);
    }
}

void Serial::SetSerialParameter()
{
  //Configura os parâmetros de comunicação da UART na porta serial

  dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
  Status = GetCommState(hComm, &dcbSerialParams); //retreives  the current settings
  if (Status == FALSE)
  {
    std::cout << "\n Erro ao verificar estado da COM5" << std::endl;
    CloseHandle(hComm);
  }
  dcbSerialParams.BaudRate = CBR_115200;      //BaudRate = 115200
  dcbSerialParams.ByteSize = 8;               //ByteSize = 8
  dcbSerialParams.StopBits = ONESTOPBIT;      //StopBits = 1
  dcbSerialParams.Parity = NOPARITY;          //Parity = None
  Status = SetCommState(hComm, &dcbSerialParams);
  if (Status == FALSE)
  {
    std::cout << "\n Erro ao configurar a estrutura DCB (parametros da porta)" << std::endl;
    CloseHandle(hComm);
  }else
  {
    std::cout << "\n Porta serial " << pcCommPort << " configurada com sucesso.\n" << std::endl;
    std::cout << " Taxa de transferencia = " << dcbSerialParams.BaudRate << " bps." << std::endl;
    std::cout << " Tamanho de dado por pacote = " << dcbSerialParams.ByteSize << " bits." << std::endl;
    std::cout << " Quantidade de bits de parada = ";
    if(dcbSerialParams.StopBits == ONESTOPBIT) std::cout << " 1 Bit" << std::endl;
    if(dcbSerialParams.StopBits == ONE5STOPBITS) std::cout << " 1,5 Bits" << std::endl;
    if(dcbSerialParams.StopBits == TWOSTOPBITS) std::cout << " 2 Bits" << std::endl;
  }
  //`Configurando Timeouts
  timeouts.ReadIntervalTimeout = 50;
  timeouts.ReadTotalTimeoutConstant = 50;
  timeouts.ReadTotalTimeoutMultiplier = 10;
  timeouts.WriteTotalTimeoutConstant = 50;
  timeouts.WriteTotalTimeoutMultiplier = 10;
  if (SetCommTimeouts(hComm, &timeouts) == FALSE)
  {
      std::cout << "\n Erro ao configurar os timeouts de leitura e escrita!" << std::endl;
      CloseHandle(hComm);
  }
  
}

char Serial::SerialWrite()
{
  //Escrevendo dados na porta serial
  std::cout << "\nSOLICITAR CARREGAMENTO DE LOG? <l>." << std::endl;
  std::cout << "\nSOLICITAR TEMPO DE APARELHO LIGADO <c>." << std::endl;
  std::cin >> SerialBufferT[1];
  Status = WriteFile(hComm,                   // Handle to the Serialport
                     SerialBufferT,           // Data to be written to the port
                     sizeof(SerialBufferT),   // No of bytes to write into the port
                     &BytesWritten,           // No of bytes written to the port
                     NULL);
  if (Status == FALSE)
  {
    std::cout << "\n Escrita na porta COM5 Falhou!" << std::endl;
    CloseHandle(hComm);
  }else 
  //Mostra a quantidade de bytes escritos na porta serial
  std::cout << "\n Quantidade de bytes escritos na porta serial = " << BytesWritten - 3 << std::endl << std::endl;
  if(SerialBufferT[1] == 'l') return 'l';// comando de rotina de recebimento de log
  if(SerialBufferT[1] == 'c') return 'c';// comando de rotina da variável tempoLigado.
}

char* Serial::SerialRead()
{
  //Configurando máscara de recepção
  Status = SetCommMask(hComm, EV_RXCHAR);// Um novo caracter foi recebido e está no buffer de entrada.
  if (Status == FALSE)
  {
      printf("\nError to in Setting CommMask\n\n");
      CloseHandle(hComm);
  }

  //Configurando espera por evento de recepção
  Status = WaitCommEvent(hComm, &dwEventMask, NULL); //Wait for the character to be received
  if (Status == FALSE)
  {
      printf("\nError! in Setting WaitCommEvent()\n\n");
      CloseHandle(hComm);
  }
  //Read data and store in a buffer * Construir a fila aki
    do
    {
        Status = ReadFile(hComm, &ReadData, sizeof(ReadData), &NoBytesRead, NULL);
        if (Status == FALSE)
    {
        printf("\nError! in ReadFile()\n\n");
        CloseHandle(hComm);
    }
        SerialBufferR[loop] = ReadData;// leirura byte a byte
        ++loop;
    }
    while (NoBytesRead > 0);// atá finalização dos bytes do buffer de recepção
    --loop; //Get Actual length of received data
    printf("\nNumber of bytes received = %d\n\n", loop);
    char *pR = SerialBufferR;
    //print receive data on console
    printf("\n\n");
    int index = 0;
    for (index = 0; index < sizeof(SerialBufferR); ++index)
    {
        printf("%c", SerialBufferR[index]);
    }
    printf("\n\n");
    return pR;
}

void Serial::CloseSerial()
{
  CloseHandle(hComm);//Closing the Serial Port
  std::cout << "\nPorta Fechada!\n" << std::endl;
}






#endif //SERIAL_UART_CCP