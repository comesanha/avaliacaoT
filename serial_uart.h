/********************************************************************************************
  * File:   serial_uart.h
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

#ifndef SERIAL_UART_H
      #define SERIAL_UART_H

#include <Windows.h>

class Serial {

  HANDLE hComm;  // Handle to the Serial port
  BOOL   Status; // Status
  DCB dcbSerialParams;  // Initializing DCB structure
  COMMTIMEOUTS timeouts;  //Initializing timeouts structure
  char SerialBufferR[64];// Buffer pata receber dados
  char SerialBufferT[4]; //Buffer para enviar dados
  DWORD BytesWritten;          // No of bytes written to the port
  DWORD dwEventMask;     // Event mask to trigger
  char  ReadData;        //temperory Character
  DWORD NoBytesRead;     // Bytes read by ReadFile()
  unsigned char loop;
  const char *pcCommPort;

public:
  Serial();
  ~Serial();
  void OpenSerial();
  void SetSerialParameter();
  char SerialWrite();
  char* SerialRead();
  void CloseSerial();
};



#endif //SERIAL_UART_H