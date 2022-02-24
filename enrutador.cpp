#include "enrutador.h"
#include<map>
#include <iostream>

/*
void Enrutador::AsignaTabla(map <unsigned short int,Enrutador>* Enrutadores){
    map <unsigned short int,Enrutador>::iterator llave;
    unsigned short int valor = 0;
    for (llave = Enrutadores.begin(); llave!= Enrutadores.end(); llave++){
       cout << "Valor ruta hasta enrutador " << llave->first <<" ";
       cin >>  valor;
       TablaDeEnrutamiento[llave->first]=valor;
    }
}
*/
void Enrutador::AsignaTabla(unsigned short int nombre){

    unsigned short int valor = 0;
    for(unsigned short int i = 1; i<= nombre; i++){
        if (nombre == i){
            TablaDeEnrutamiento[i]=0;
        }
        else {
            cout << "Valor ruta del enrutador "<<nombre << " al enrutador " << i <<" un numero entero entre 0 y 65535 "; // El programa solo recibe valores de rutas entre 0 y 65536 porque lo puse como unsigned short int.
            cin >>  valor;
            TablaDeEnrutamiento[i]=valor;
        }
     }
}

void Enrutador::ActualizarTablas(unsigned short int nombre, Enrutador nuevoEnrut, unsigned short int llave){

    unsigned short int ruta = 0;
    ruta = nuevoEnrut.TablaDeEnrutamiento[llave];
    TablaDeEnrutamiento[nombre] = ruta;
}

void Enrutador::EliminarEnrutador(unsigned short int enrut){
    TablaDeEnrutamiento.erase(enrut);
}
unsigned short int Enrutador::ElementosEnTabla(unsigned short int origen, unsigned short int destino, unsigned short int* cuantosVan, unsigned short int* valorRuta){
    map <unsigned short int,unsigned short int>::iterator llave;
    unsigned short int con = 1;
    for (llave = TablaDeEnrutamiento.begin(); llave != TablaDeEnrutamiento.end(); llave++){
        if (con > *cuantosVan && llave->first != 0){
            *cuantosVan += 1;
            *valorRuta = llave->second;
            return llave->first;
        }
        con += 1;
    }
    return 0;



}

Enrutador::Enrutador()
{

}
