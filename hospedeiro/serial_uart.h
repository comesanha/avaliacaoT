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

#include "serial.h"
#include <Windows.h>

class Serial: public Serial {

  HANDLE hComm;             // Handle to the Serial port
  BOOL   Status;            // Status
  DCB dcbSerialParams;      // Initializing DCB structure
  COMMTIMEOUTS timeouts;    //Initializing timeouts structure
  char SerialBufferR[9];    // Buffer pata receber dados
  char SerialBufferT[1];    //Buffer para enviar dados
  DWORD BytesWritten;       // No of bytes written to the port
  DWORD dwEventMask;        // Event mask to trigger
  char  ReadData;           //temperory Character
  DWORD NoBytesRead;        // Bytes read by ReadFile()
  unsigned int loop;
  const char *pcCommPort;

public:
  Serial();
  ~Serial();
  void OpenSerial();
  void SetSerialParameter();
  void SerialWrite(char &T);
  void SerialRead(unsigned char *pR);
  void CloseSerial();
};



#endif //SERIAL_UART_H