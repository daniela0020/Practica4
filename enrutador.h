#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <map>

using namespace std;

class Enrutador
{

public:
    Enrutador();
    map <unsigned short int,unsigned short int>TablaDeEnrutamiento;
    void AsignaTabla(unsigned short int nombre);
    void ActualizarTablas(unsigned short int nombre,Enrutador nuevoEnrut, unsigned short int llave);
    void EliminarEnrutador(unsigned short int enrut);
    unsigned short int ElementosEnTabla(unsigned short int origen, unsigned short int destino, unsigned short int* cuantosVan, unsigned short int* valorRuta);
};

#endif // ENRUTADOR_H
