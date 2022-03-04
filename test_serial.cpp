/********************************************************************************************
  * File:   test_serial.cpp
 * Author: Raphael Comesanha. 
 * Adapted from 
 * Function: This file has the Test program for UART Class.
 * Created on Fevereiro de 2022.
 * Last Modification:
 * Author Modification: 
 * Modified on
 * 
 * # Compilado no windows 10 PowerShell
 * # Linha de comando: g++ -o test Node.h
 **********************************************************************************************/

#include "serial_uart.cpp"

int main()
{
  Serial uartPc;

  uartPc.OpenSerial();

  uartPc.SetSerialParameter();

  uartPc.SerialWrite(/*inseriri o que será escrito para a UART AQUI*/);

  uartPc.CloseSerial();
  return 0;
}

