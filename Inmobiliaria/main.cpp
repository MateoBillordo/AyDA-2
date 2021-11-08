#include <iostream>
#include <limits>
#include <Inmueble.h>
#include <Coleccion_Inmuebles.h>

using namespace std;

bool Menu(Coleccion_Inmuebles & Conjunto_Inmobiliaria);
void Cargar_datos_inmueble (Inmueble & A);
void Mostrar_coleccion(Coleccion_Inmuebles & Conjunto_Inmobiliaria);
void IgnorarLinea();

int main()
{
    Coleccion_Inmuebles Conjunto_Inmobiliaria;
    cout << "Bienvenido a la inmobiliaria" << '\n';
    while (Menu(Conjunto_Inmobiliaria)){};
    return 0;
}

bool Menu(Coleccion_Inmuebles & Conjunto_Inmobiliaria){
    cout << "" << '\n';
    cout << "Elija una opcion:" << '\n';
    cout << "1)Agregar inmueble" << '\n';
    cout << "2)Eliminar inmueble" << '\n';
    cout << "3)Determinar si existe un inmueble en la lista" << '\n';
    cout << "4)Determinar si existen inmuebles para un determinado barrio" << '\n';
    cout << "5)Filtrar los inmuebles disponibles con un precio menor o igual al dado" << '\n';
    cout << "6)Ver contenido de la coleccion" << '\n';
    cout << "0)Salir" << '\n';
    int opcion;
    cin >> opcion;
    switch (opcion){
        case 1:{
            Inmueble A;
            Cargar_datos_inmueble(A);
            Conjunto_Inmobiliaria.agregar(A);
            break;
        }
        case 2:{
            string id;
            cout << "Ingrese la id del inmueble que desea eliminar: " << '\n';
            cin >> id;
            if (Conjunto_Inmobiliaria.eliminar(id)){
                cout << "Se ha eliminado el inmueble correctamente" << '\n';
            }else{
                cout << "El inmueble indicado no se encuentra cargado" << '\n';
            }
            break;
        }
        case 3:{
            string id;
            cout << "Ingrese la id del inmueble para saber si se encuentra cargado: " << '\n';
            cin >> id;
            if (Conjunto_Inmobiliaria.existe(id)){
                cout << "Se encuentra cargado" << '\n';
            }else{
                cout << "No se encuentra cargado" << '\n';
            }
            break;
        }
        case 4:{
            string barrio;
            cout << "Ingrese el barrio para saber si hay inmuebles disponibles: " << '\n';
            IgnorarLinea();
            getline(cin,barrio);
            if (Conjunto_Inmobiliaria.existe_barrio(barrio)){
                cout << "Hay inmuebles disponibles para el barrio indicado" << '\n';
            }else{
                cout << "No hay inmuebles disponibles para el barrio indicado" << '\n';
            }
            break;
        }
        case 5:{
            float precio;
            Coleccion_Inmuebles resultado;
            cout << "Ingrese un precio maximo para filtrar los inmuebles disponibles:" << '\n';
            cin >> precio;
            Conjunto_Inmobiliaria.filtrar_por_precio(precio,resultado);
            cout << "" << '\n';
            cout << "Los resultados de la busqueda son:" << '\n';
            Mostrar_coleccion(resultado);
            break;
        }
        case 6:{
            cout << "" << '\n';
            cout << "La coleccion contiene: " << '\n';
            Mostrar_coleccion(Conjunto_Inmobiliaria);
            break;
        }
        case 0:{
            return false;
            break;
        }
    }
    return true;
}

void Cargar_datos_inmueble (Inmueble & A){
    string id, barrio, descripcion;
    float precio;
    cout << "A continuacion ingrese los siguientes datos para el inmueble:" << '\n';
    cout << "id - precio - barrio - descripcion" << '\n';
    cin >> id;
    cin >> precio;
    IgnorarLinea();
    getline(cin,barrio);
    getline(cin,descripcion);
    A.cambiar_identificador(id);
    A.cambiar_precio(precio);
    A.cambiar_barrio(barrio);
    A.cambiar_descripcion(descripcion);
}

void Mostrar_coleccion(Coleccion_Inmuebles & Conjunto_Inmobiliaria){
    Coleccion_Inmuebles::Iterador It=Conjunto_Inmobiliaria.iniciar_iterador();
    Inmueble A;
    while (!It.es_final()){
        A=It.obtener_elemento();
        cout << A.obtener_identificador() << "|" << A.obtener_precio() << "|" << A.obtener_barrio() << "|" << A.obtener_descripcion() << '\n';
        It.avanzar();
    }
}

void IgnorarLinea()
{
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}
