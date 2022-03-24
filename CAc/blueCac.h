
/*Programm Name: blueCac.h
* Author: Raphael Comesanha
* Fonte: 
* Functionality: 
* Date: 
* Last Update:
* Daea Update:
* Author Update:
*/

#ifndef BLUECAC_H
	#define BLUECAC_H

#include "blueComd.h"


class BlueCac : public BlueComd {
public:
	BlueCac ();
    void setComando(char);// Atualisa valor do atributo comando
    void sendComando();// Envia o valor de comando através da interface bluetooth.
    void closeComn();// Finaliza interface bluetooth
};
#endif //BLUECAC_H