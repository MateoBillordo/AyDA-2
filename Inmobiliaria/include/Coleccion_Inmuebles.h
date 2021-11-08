#ifndef COLECCIONINMUEBLES_H
#define COLECCIONINMUEBLES_H

#include "Inmueble.h"
#include <map>

using namespace std;

class Coleccion_Inmuebles
{
    public:
        class Iterador{
            friend class Coleccion_Inmuebles;
        private:
            Iterador(map<string,Inmueble>::const_iterator inicio,map<string,Inmueble>::const_iterator fin);
        public:
            ~Iterador();
            void avanzar();
            const Inmueble & obtener_elemento() const;
            bool es_final();
        private:
            map<string,Inmueble>::const_iterator ItInmuebles;
            map<string,Inmueble>::const_iterator ItFinal;
        };
    public:
        Coleccion_Inmuebles();

        virtual ~Coleccion_Inmuebles();

        bool existe(string id) const;

        void filtrar_por_precio(float precio, Coleccion_Inmuebles & resultado) const;

        bool existe_barrio(string barrio) const;

        void agregar(const Inmueble & nuevo);

        bool eliminar(string id);

        Iterador iniciar_iterador();

    private:
        map<string,Inmueble> ConjuntoInmuebles;
};

#endif // COLECCIONINMUEBLES_H
