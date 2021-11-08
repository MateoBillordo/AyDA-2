#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <assert.h>

using namespace std;

template <typename C> class Grafo
{
public:
	class Arco
	{
	public:
		Arco();
		Arco(int adyacente, const C & costo);
		int devolver_adyacente() const;
		const C & devolver_costo() const;
		void modificar_costo(const C & costo);
	private:
		int vertice;
		C costo;
	}; // class Arco

public:
	// NOTA: Dependiendo de la implementación puede ser necesario incluir otras funciones constructuras
	Grafo();
	Grafo(const Grafo & otroGrafo);

	~Grafo();

	Grafo & operator = (const Grafo & otroGrafo);

	// Devuelve true si la cantidad de vértices es cero
	bool esta_vacio() const;

	// Indica la cantidad de vértices del grafo
	int devolver_longitud() const;

	bool existe_vertice(int vertice) const;

	bool existe_arco(int origen, int destino) const;

	// PRE CONDICION: existe_arco(origen, destino)
	const C & costo_arco(int origen, int destino) const;

	void devolver_vertices(list<int> & vertices) const;

	void devolver_adyacentes(int origen, list<Arco> & adyacentes) const;

	void agregar_vertice(int vertice);

	// POST CONDICION: Para todo vértice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
	void eliminar_vertice(int vertice);

	// PRE CONDICION: existeArco(origen, destino)
	void modificar_costo_arco(int origen, int destino, const C & costo);

	// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
	// POST CONDICION: existeArco(origen, destino)
	void agregar_arco(int origen, int destino, const C & costo);

	// POST CONDICION: !existeArco(origen, destino)
	void eliminar_arco(int origen, int destino);

	void vaciar();

private:
	map<int, list<Arco>> MapaVertices;

}; // class Grafo


/*
 * Arco
 */

template <typename C> Grafo<C>::Arco::Arco()
{

}

template <typename C> Grafo<C>::Arco::Arco(int adyacente, const C & costo)
{
    this->vertice=adyacente;
    this->costo=costo;
}

template <typename C> int Grafo<C>::Arco::devolver_adyacente() const
{
    return vertice;
}

template <typename C> const C & Grafo<C>::Arco::devolver_costo() const
{
    return costo;
}

template <typename C> void Grafo<C>::Arco::modificar_costo(const C & costo)
{
    this->costo = costo;
}

/*
 * Grafo
 */

template <typename C> Grafo<C>::Grafo()
{
}

template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo)
{
    this->operator = (otroGrafo);
}

template <typename C> Grafo<C>::~Grafo()
{

}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo)
{
    MapaVertices.clear();
    MapaVertices = otroGrafo.MapaVertices;
    return *this;
}

template <typename C> bool Grafo<C>::esta_vacio() const
{
    return MapaVertices.empty();
}

template <typename C> int Grafo<C>::devolver_longitud() const
{
    return MapaVertices.size();
}

template <typename C> bool Grafo<C>::existe_vertice(int vertice) const
{
    bool existe = false;
    typename map<int, list<Arco> >::const_iterator it = MapaVertices.find(vertice);
    if (it!=MapaVertices.end())
        existe = true;
    return existe;
}

template <typename C> bool Grafo<C>::existe_arco(int origen, int destino) const
{
    bool existe = false;
    typename map<int, list<Arco> >::const_iterator it = MapaVertices.find(origen);
    if (it!=MapaVertices.end()){
        typename list<Arco>::const_iterator ItArcos = it->second.begin();
        while(!existe && ItArcos!=it->second.end()){
            if (ItArcos->devolver_adyacente()==destino)
                existe = true;
            else
                ItArcos++;
        }
    }
    return existe;
}

template <typename C> const C & Grafo<C>::costo_arco(int origen, int destino) const
{
    assert(existe_arco(origen,destino));
    bool existe = false;
    typename map<int, list<Arco> >::const_iterator it = MapaVertices.find(origen);
    typename list<Arco>::const_iterator ItArcos = it->second.begin();
    while(!existe && ItArcos!=it->second.end()){
        if (ItArcos->devolver_adyacente()==destino){
            existe = true;
        }
        else
            ItArcos++;
    }
    return ItArcos->devolver_costo();
}

template <typename C> void Grafo<C>::devolver_vertices(list<int> & vertices) const
{
    typename map<int, list<Arco> >::const_iterator it = MapaVertices.begin();
    while (it!=MapaVertices.end()){
        vertices.push_back(it->first);
        it++;
    }
}

template <typename C> void Grafo<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const
{
    typename map<int, list<Arco> >::const_iterator it = MapaVertices.find(origen);
    adyacentes = it->second;
}

template <typename C> void Grafo<C>::agregar_vertice(int vertice)
{
    list<Arco> adyacentes;
    MapaVertices[vertice] = adyacentes;
}

template <typename C> void Grafo<C>::eliminar_vertice(int vertice)
{
    if (existe_vertice(vertice))
        MapaVertices.erase(vertice);
}

template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C & costo)
{
    bool existe = false;
    typename map<int, list<Arco> >::iterator it = MapaVertices.find(origen);
    if (it!=MapaVertices.end()){
        typename list<Arco>::iterator ItArcos = it->second.begin();
        while(!existe && ItArcos!=it->second.end()){
            if (ItArcos->devolver_adyacente()==destino){
                ItArcos->modificar_costo(costo);
                existe = true;
            }
            else
                ItArcos++;
        }
    }
}

template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C & costo)
{
    typename map<int, list<Arco> >::iterator it = MapaVertices.find(destino);
    if (it!=MapaVertices.end()){
        it = MapaVertices.find(origen);
        if (it!=MapaVertices.end() && !existe_arco(origen,destino))
            it->second.push_back(Arco(destino,costo));
    }
}

template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino)
{
    bool existe = false;
    typename map<int, list<Arco> >::iterator it = MapaVertices.find(origen);
    if (it!=MapaVertices.end()){
        typename list<Arco>::const_iterator ItArcos = it->second.begin();
        while(!existe && ItArcos!=it->second.end()){
            if (ItArcos->devolver_adyacente()==destino){
                it->second.erase(ItArcos);
                existe = true;
            }
            else
                ItArcos++;
        }
    }
}

template <typename C> void Grafo<C>::vaciar()
{
    MapaVertices.clear();
}

#endif /* GRAFO_H_ */
