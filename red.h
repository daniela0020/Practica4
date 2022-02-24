#ifndef RED_H
#define RED_H
#include "enrutador.h"

class red
{
public:
    red();
    map< unsigned short int,Enrutador >Enrutadores;
    unsigned short int AsignaTablaR();
    void ActualizarTablaR(unsigned short int nombre);
    void EliminarEnrutador(unsigned short int num);
    void CostoCaminos(unsigned short int origen, unsigned short int destino);
};

#endif // RED_H
