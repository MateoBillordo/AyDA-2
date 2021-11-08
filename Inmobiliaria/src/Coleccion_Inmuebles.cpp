#include "Coleccion_Inmuebles.h"
#include <cassert>
#include <iostream>

using namespace std;


Coleccion_Inmuebles::Coleccion_Inmuebles()
{
}

Coleccion_Inmuebles::~Coleccion_Inmuebles()
{
}

void Coleccion_Inmuebles::agregar(const Inmueble & inmueble)
{
    string id=inmueble.obtener_identificador();
    ConjuntoInmuebles[id]=inmueble;
}

bool Coleccion_Inmuebles::eliminar(string id)
{
    map<string,Inmueble>::iterator it = ConjuntoInmuebles.find(id);
    if (it!=ConjuntoInmuebles.end()){
        ConjuntoInmuebles.erase(it);
        return true;
    }
    return false;
}

bool Coleccion_Inmuebles::existe_barrio(string barrio) const
{
    map<string,Inmueble>::const_iterator it =ConjuntoInmuebles.begin();
    while (it!=ConjuntoInmuebles.end()){
        if (it->second.obtener_barrio()==barrio){
            return true;
        }
        it++;
    }
    return false;
}

void Coleccion_Inmuebles::filtrar_por_precio(float precio, Coleccion_Inmuebles & resultado) const
{
    map<string,Inmueble>::const_iterator it =ConjuntoInmuebles.begin();
    while (it!=ConjuntoInmuebles.end()){
        if (it->second.obtener_precio()<=precio){
            resultado.agregar(it->second);
        }
        it++;
    }
}

bool Coleccion_Inmuebles::existe(string id) const
{
   map<string,Inmueble>::const_iterator it = ConjuntoInmuebles.find(id);
    if (it!=ConjuntoInmuebles.end()){
        return true;
    }
   return false;
}

Coleccion_Inmuebles::Iterador Coleccion_Inmuebles::iniciar_iterador(){
    return Iterador(ConjuntoInmuebles.begin(),ConjuntoInmuebles.end());
}
//-----------------------ITERADOR----------------------
Coleccion_Inmuebles::Iterador::Iterador(map<string,Inmueble>::const_iterator inicio,map<string,Inmueble>::const_iterator fin){
    ItInmuebles=inicio;
    ItFinal=fin;
}

Coleccion_Inmuebles::Iterador::~Iterador()
{
}

void Coleccion_Inmuebles::Iterador::avanzar(){
    ItInmuebles++;
}

const Inmueble & Coleccion_Inmuebles::Iterador::obtener_elemento() const{
    return ItInmuebles->second;
}

bool Coleccion_Inmuebles::Iterador::es_final(){
    return (ItInmuebles==ItFinal);
}
