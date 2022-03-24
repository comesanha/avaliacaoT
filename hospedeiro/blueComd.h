/*
 * blueComd.h
 *
 *  Created on: 
 *      Author: 
 */

#ifndef BLUECOMD_H
      #define BLUECOMD_H

class BlueComd {
      protected:
            char comando;
      public:
            BlueComd()
            {
                  comando = 0;
            }
            virtual void setComando(char) = 0;// Atualisa valor do atributo comando
            virtual void sendComando() = 0;// Envia o valor de comando através da interface bluetooth.
            virtual void closeComn() = 0;// Finaliza interface bluetooth 
};
#endif //BLUECOMD_H

