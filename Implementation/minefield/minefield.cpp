#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define INF 200000000

// Clase Dupla para almacenar los puntos seguros
class Dupla
{
public:
	int index; // Posicion en el monticulo
	float x;   // Posicion x
	float y;
	float d; // Distancia desde el camino mas corto hacia esta dupla
	Dupla();
	Dupla(float,float);
};

class PriorityQueueMinHeap
{
	public:
	vector<Dupla*> priorityQueue;
	void adjust(int);
	void decreaseKey(Dupla*);
	void push(Dupla*);
	Dupla* pop();
	bool empty();
	int size();
	Dupla* at(int);
};

Dupla::Dupla(){}

Dupla::Dupla(float x,float y){
	this->x = x;
	this->y = y;
}
/*
Ajusta el monticulo solo si los hijos del elemento de la posicion i son monticulos
*/
void PriorityQueueMinHeap::adjust(int i){
	int n = priorityQueue.size()-1;
	int j = 2*i+1;
	Dupla *item = priorityQueue[i];
	while(j <= n){
		if((j < n) && (priorityQueue[j]->d > priorityQueue[j+1]->d)) // > : Heap-Min --- < : Heap-Max
			j++;
		if(item->d <= priorityQueue[j]->d)
			break;
		priorityQueue[ceil((double)j/2)-1] = priorityQueue[j];
		priorityQueue[ceil((double)j/2)-1]->index = ceil((double)j/2)-1;
		j = 2*j+1;
	}
	priorityQueue[ceil((double)j/2)-1] = item;
	priorityQueue[ceil((double)j/2)-1]->index = ceil((double)j/2)-1;
}

//Se utiliza cuando se relaja reubicar dentro del monticulo el punto que fue relajado
void PriorityQueueMinHeap::decreaseKey(Dupla *dupla){
	int i = dupla->index;
	Dupla *item = dupla;
	while((i > 0) && (priorityQueue[ceil((double)i/2)-1]->d > item->d)){
		priorityQueue[i] = priorityQueue[ceil((double)i/2)-1];
		priorityQueue[i]->index = i;
		i = ceil((double)i/2)-1;
	}
	priorityQueue[i] = item;
	priorityQueue[i]->index = i;
}

//Insertar dentro del monticulo
void PriorityQueueMinHeap::push(Dupla *newDupla){
	priorityQueue.push_back(newDupla);
	int n = priorityQueue.size()-1;
	int i = n;
	Dupla *item = priorityQueue[n];
	while((i > 0)&& (priorityQueue[ceil((double)i/2)-1]->d > item->d)){
		priorityQueue[i] = priorityQueue[ceil((double)i/2)-1];
		priorityQueue[i]->index = i;
		i = ceil((double)i/2)-1;
	}
	priorityQueue[i] = item;
	priorityQueue[i]->index = i;
}

//Sacar el tope del monticulo y eliminar el elemento luego 
Dupla* PriorityQueueMinHeap::pop(){
	Dupla *min = priorityQueue[0];
	int n = priorityQueue.size() - 1;
	priorityQueue[0] = priorityQueue[n];
	priorityQueue.erase(priorityQueue.begin()+n); // Eliminar ultimo elemento
	adjust(0);
	return min;
}

//Saber si esta vacio el monticulo 
bool PriorityQueueMinHeap::empty(){
	if(priorityQueue.size() == 0)
		return true;
	else
		return false;
}

//Retorna tamaño del monticulo
int PriorityQueueMinHeap::size(){
	return priorityQueue.size();
}

//Retorna el elemento del monticulo que se encuentra en el indice indicado
Dupla* PriorityQueueMinHeap::at(int indice){
	return priorityQueue[indice];
}
//FIN METODOS PROPIOS DE LA PRIORITY QUEUE 

//Calcula la distancia entre dos puntos seguros
float distance(Dupla d1, Dupla d2){
	return sqrt(pow((d2.x - d1.x), 2)+ pow((d2.y - d1.y), 2));
}

//Hace la relajacion
bool Relax(Dupla &u,Dupla &v,float distancia){
	if(v.d > u.d + distancia){
		v.d = u.d+distancia;
		return true;
	}
	else
		return false;
}

//Inicializa las duplas en infinito, menos el origen que se inicializa con 0
void initializeSingleSource(vector<Dupla> &duplas){
	for(int i = 0; i < duplas.size(); i++){
		duplas[i].d = INF;
	}
	duplas[0].d = 0;
}

//Funcion que se encarga de realizar el algoritmo de Dijkstra aplicado al Minefield
void minefield(vector<Dupla> duplas, Dupla meta, float d){
	bool state = true;
	initializeSingleSource(duplas);
	PriorityQueueMinHeap Q;
	for(int i = 0; i < duplas.size(); i++)
		Q.push(&duplas[i]); // La cola de prioridad guarda la posicion de memoria de los puntos seguros
	Dupla *u = NULL;	
	while(!Q.empty()){
		u = Q.pop();
		//Si la distancia que se ha recorrido hasta el momento es mayor que d
		//entonces ya no hay solucion y explota el campo de minas
		if(u->d > d){
			state = false;
			break;
		}
		// Si ya ha llegado al punto destino (w,h) entonces el algoritmo termina
		if(u->x == meta.x && u->y == meta.y){
			state = true;
			break;
		}

		for(int i = 0; i < Q.size(); i++){		
			float dis = distance(*u, *Q.at(i)); //Calcula la distancia entre dos puntos seguros
			if(dis <= 1.5){ //Si la distancia no supera 1.5 es posible relajar y pasar de ese punto seguro al otro
				if(Relax(*u, *Q.at(i), dis))
					Q.decreaseKey(Q.at(i));
			}
		}	
	}

	//La variable state es true cuando fue posible cruzar el campo minado
	//Y false cuando se supero la distancia o cuando no fue posible llegar al punto destino
	if(state)
		cout << "I am lucky!" << endl;
	else
		cout << "Boom!" << endl;
}

int main(){
	int width, height;
	while(scanf("%d %d", &width, &height)){
		int n;
		cin >> n;  //Numero de puntos seguros 	
		vector<Dupla> duplas;
		Dupla first(0.00, 0.00); //Punto origen
		duplas.push_back(first);
		float x,y;
		int i = 1;
		while(i <= n){
			cin >> x >> y;  //Se reciben el X y Y de cada punto seguro
			Dupla dupla(x,y);
			duplas.push_back(dupla);  //Se guarda cada punto seguro en el vector de Duplas
			i++;
		}
		Dupla last((float)width, (float)height); //Dupla que guarda el punto destino que es (w,h)
		duplas.push_back(last);
		float d;
		cin >> d;  //Distancia maxima que se puede recorrer
		minefield(duplas, duplas.back(), d);
	}
	return 0;
}