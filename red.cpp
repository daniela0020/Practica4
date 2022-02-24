#include "red.h"
#include "enrutador.h"
#include <map>
#include <iostream>
red::red()
{

}
unsigned short int red::AsignaTablaR(){
    unsigned short int nombre  = Enrutadores.size()+1;
    Enrutadores[nombre];
    Enrutadores[nombre].AsignaTabla(nombre);
}
void red::ActualizarTablaR(unsigned short int nombre){
    if (Enrutadores.size()==0){
        nombre = Enrutadores.size()+1;
    }
    else{
        nombre = Enrutadores.size();
    }
    map <unsigned short int,Enrutador>::iterator llave;
    if (Enrutadores.size()>1){
        for (llave = Enrutadores.begin(); llave!= Enrutadores.end(); llave++){
           Enrutadores[llave->first].ActualizarTablas(nombre,Enrutadores[nombre],llave->first);
        }

    }
}
void red::EliminarEnrutador(unsigned short int num) {
    map <unsigned short int,Enrutador>::iterator llave;
    Enrutadores.erase(num);
    for (llave = Enrutadores.begin(); llave!= Enrutadores.end(); llave++){
       Enrutadores[llave->first].EliminarEnrutador(num);
    }
}
void red::CostoCaminos(unsigned short int origen, unsigned short int destino){
    unsigned short int cuantosVan = 0, nombre = 1, valoRuta = 0;
    bool encontrado = false;
    if (Enrutadores[origen].TablaDeEnrutamiento[destino] != 0){
        cout << "Enviar un paquete desde el enrutador " << origen << " Al enrutador " << destino << " cuesta "<<Enrutadores[origen].TablaDeEnrutamiento[destino];
    }
    else {
        while (nombre != 0){
             nombre = Enrutadores[origen].ElementosEnTabla(origen,destino,&cuantosVan,&valoRuta);
             if (Enrutadores[nombre].TablaDeEnrutamiento[destino] != 0){
                 cout << "Enviar un paquete desde el enrutador " << origen << " Al enrutador " << destino << " cuesta "<<Enrutadores[nombre].TablaDeEnrutamiento[destino] + valoRuta << endl;
                 encontrado = true;
                 break;
             }
        }
        if (encontrado == false) {
            cout << "No existe una ruta entre el enrutador " << origen << " y el enrutador " << destino << endl;
        }
    }
}
