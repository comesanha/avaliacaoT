/*Programm Name: blueHosp.h
* Author: Raphael Comesanha
* Fonte: 
* Functionality: 
* Date: 
* Last Update:
* Daea Update:
* Author Update:
*/

#ifndef BLUEHOSP_H
	#define BLUEHOSP_H

#include "blueComd.h"


class BlueHosp : public BlueComd {
public:
	BlueHosp ();
    void setComando(char);// Atualisa valor do atributo comando
    void sendComando();// Envia o valor de comando através da interface bluetooth.
    void closeComn();// Finaliza interface bluetooth
};
#endif //BLUEHOSP_H