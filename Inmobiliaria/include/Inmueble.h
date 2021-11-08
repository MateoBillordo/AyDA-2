#ifndef INMUEBLE_H
#define INMUEBLE_H

#include <iostream>

using namespace std;

class Inmueble
{
    public:
        Inmueble();
        Inmueble (string id, float precio, string barrio, string descripcion);
        virtual ~Inmueble();

        string obtener_identificador() const;
        float obtener_precio() const;
        string obtener_barrio() const;
        string obtener_descripcion() const;

        void cambiar_identificador(string id);
        void cambiar_precio(float precio);
        void cambiar_barrio(string barrio);
        void cambiar_descripcion(string descripcion);

    private:
        string id;
        float precio;
        string barrio;
        string descripcion;
};

#endif // INMUEBLE_H
