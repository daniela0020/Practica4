#include <iostream>
#include "enrutador.h"
#include "red.h"
using namespace std;

int main()
{
    // El programa solo recibe valores de rutas entre 0 y 65536 porque lo puse como unsigned short int.

    unsigned short int validar = 0,num=0, origen = 0, destino = 0, nombre = 0;
    red ListEnrutadores;
    while (true) {
        cout << "Quiere agregar un enrutador ingrese 1"<< endl;
        cout << "Quiere eliminar un enrutador ingrese 2 " << endl;
        cout << "Quiere saber cuanto cuesta enviar un paquete desde un enrutador origen a un destino ingrese 3" << endl;
        cin >> validar;
        if (validar == 1){
            nombre = ListEnrutadores.AsignaTablaR();
            ListEnrutadores.ActualizarTablaR(nombre);
            cout << "Quiere volve a repetir el menu ingrese 0 de lo contrario ingrese otro numero ";
            cin >> validar;
            if (validar != 0){
                break;
            }
        }
        else {
            if(validar == 2){
                cout << "Numero del enrutador que quiere eliminar ";
                cin >> num;
                ListEnrutadores.EliminarEnrutador(num);
                cout << "Quiere volve a repetir el menu ingrese 0 de lo contrario ingrese otro numero ";
                cin >> validar;
                if (validar != 0){
                    break;
                }
            }
            else {
                if (validar == 3){
                    cout << "Ingrese numero del enrutador origen ";
                    cin >> origen;
                    cout << "Ingrese numero del enrutador destino ";
                    cin >> destino;
                    if (origen == destino){
                        cout << "Enviar un paquete desde el enrutador " << origen << " Al enrutador " << destino << " cuesta "<<0;
                    }
                    else {
                       ListEnrutadores.CostoCaminos(origen,destino);
                    }
                    cout << "Quiere volve a repetir el menu ingrese 0 de lo contrario ingrese otro numero ";
                    cin >> validar;
                    if (validar != 0){
                        break;
                    }
                }
                else {
                    cout << "Quiere volve a repetir el menu ingrese 0 de lo contrario ingrese otro numero ";
                    cin >> validar;
                    if (validar != 0){
                        break;
                    }
                }
            }
        }

    }
    return 0;
}

