#include "Inmueble.h"

Inmueble::Inmueble() : id(""), precio(0), barrio(""), descripcion("")
{
}

Inmueble::Inmueble(string id, float precio, string barrio, string descripcion)
{
    this->id = id;
    this->precio = precio;
    this->barrio = barrio;
    this->descripcion = descripcion;
}

Inmueble::~Inmueble()
{
}

string Inmueble::obtener_identificador() const
{
    return id;
}

float Inmueble::obtener_precio() const
{
    return precio;
}

string Inmueble::obtener_barrio() const
{
    return barrio;
}

string Inmueble::obtener_descripcion() const
{
    return descripcion;
}

void Inmueble::cambiar_identificador(string id)
{
    this->id = id;
}

void Inmueble::cambiar_precio(float precio)
{
    this->precio = precio;
}

void Inmueble::cambiar_barrio(string barrio)
{
    this->barrio = barrio;
}

void Inmueble::cambiar_descripcion(string descripcion)
{
    this->descripcion = descripcion;
}
