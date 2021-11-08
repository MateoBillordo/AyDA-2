#include "Grafo.h"

#include "iostream"

using namespace std;

template <typename C>
ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
	// Recorremos todos los vertices
	list<int> vertices;
	grafo.devolver_vertices(vertices);
	list<int>::iterator v = vertices.begin();
	while (v != vertices.end()) {
		salida << "    " << *v << "\n";
		// Recorremos todos los adyacentes de cada vertice
		list<typename Grafo<C>::Arco> adyacentes;
		grafo.devolver_adyacentes(*v, adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator ady = adyacentes.begin();
		while (ady != adyacentes.end()) {
			salida << "    " << *v << "-> " << ady->devolver_adyacente() << " (" << ady->devolver_costo() << ")\n";
			ady++;
		}
		v++;
	}
	return salida;
}

int main(int argc, char **argv)
{
	Grafo<int> g;

	// Cargamos un grafo dirigido
	// Primero los vértices
	g.agregar_vertice(1);
	g.agregar_vertice(2);
	g.agregar_vertice(3);
	g.agregar_vertice(4);
	g.agregar_vertice(5);
	g.agregar_vertice(6);
	g.agregar_vertice(7);

	// Luego los arcos
	g.agregar_arco(1, 2, 1);
	g.agregar_arco(1, 3, 1);
	g.agregar_arco(1, 4, 1);
	g.agregar_arco(2, 6, 2);
	g.agregar_arco(3, 5, 3);
	g.agregar_arco(4, 7, 4);
	g.agregar_arco(5, 6, 5);

    //Pueba de métodos
    cout<<"Longitud "<<g.devolver_longitud()<<"\n";
    cout<<"Existe Vertice "<<g.existe_vertice(2)<<"\n";
    cout<<"Existe Arco entre 1 y 2 "<<g.existe_arco(1,2)<<"\n";
    cout<<"Costo Arco entre 1 y 2 "<<g.costo_arco(1,2)<<"\n";
    g.modificar_costo_arco(1,2,20);
    cout<<"Costo Arco entre 1 y 2 "<<g.costo_arco(1,2)<<"\n";
    g.eliminar_arco(1,2);
    cout<<"Existe Arco entre 1 y 2 "<<g.existe_arco(1,2)<<"\n";

	// Mostramos el grafo
	cout << "Estructura del grafo:\n" << g << "\n";

	return 0;
}
