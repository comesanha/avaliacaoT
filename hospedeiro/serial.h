/*
 * serial.h
 *
 *  Created on: 13 de mar de 2022
 *      Author: rapha
 */

#ifndef SERIAL_H_
#define SERIAL_H_

class Serial {

public:
    Serial();
  ~Serial();
  virtual void OpenSerial() = 0;
  virtual void SetSerialParameter() = 0;
  virtual void SerialWrite(char &T) = 0;
  virtual void SerialRead(char *pR) = 0;
  virtual void CloseSerial() = 0;

};



#endif /* SERIAL_H_ */
