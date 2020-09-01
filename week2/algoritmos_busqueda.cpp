#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "mytimer.h"

/*
Ignacio Joaquin Moral
A01028470
*/

template<class T> 
class Busqueda{
private:
    std::vector<T> elementos;

    T valor;
    int paso=100000;

public:
    Busqueda(T _valor){
        valor = _valor;
        for(int i=0;i<100000;i++){
        elementos.push_back(rand()%100000);
        }
    }

    T busqueda_secuencial(){
        int count = 0;
        while(count<elementos.size()){
            if(elementos[count]==valor){
                break;
            }
            count+=1;
        }
        if(count==elementos.size()) return -1;
        
        return count;
    }

    T busqueda_ordenada_1(){
        std::sort(elementos.begin(), elementos.end());
        for(size_t i=0; i<elementos.size(); i++){
            if(elementos[i]==valor){
                return i;
            } else if (elementos[i]>valor){
                return -1;
            }
        }
        return -1;
    }

    T busqueda_ordenada_2(T inicio, T final){
        paso=paso/10;
        if(inicio==0 && final==100000) std::sort(elementos.begin(), elementos.end());
        for(size_t i=inicio; i<=final; i+=paso){
            if(elementos[i]==valor){
                return i;
            } else if(elementos[i]>valor){
                return busqueda_ordenada_2(i-paso, i);
            } else if(i==final){
                break;
            }
        }
        return -1;
    }

    T busqueda_binaria(T inicio, T final){
        if(inicio==0 && final==100000) std::sort(elementos.begin(), elementos.end());
        int i=(final+inicio)/2;
        if(elementos[i]==valor){
            return i;
        } else if (elementos[i]<valor){
            return busqueda_binaria(i, final);
        } else {
            return busqueda_binaria(inicio, i);
        }
        return -1;
    }
};

int main(){
    srand(time(NULL));
    int numero, p1, p2, p3, p4;
    std::cout << "Dame un numero para buscar." << std::endl;
    std::cin >> numero;
    Busqueda<int> b(numero);

    DECLARE_TIMING(t1);
    START_TIMING(t1);
    p1 = b.busqueda_secuencial();
    STOP_TIMING(t1);
    std::cout << "El valor se encuentra en la posicion " << p1 << std::endl;
    SHOW_TIMING(t1, "Busqueda Secuencial: ");

    DECLARE_TIMING(t2);
    START_TIMING(t2);
    p2 = b.busqueda_ordenada_1();
    STOP_TIMING(t2);
    std::cout << "El valor se encuentra en la posicion " << p2 << std::endl;
    SHOW_TIMING(t2, "Busqueda Ordenada 1: ");

    DECLARE_TIMING(t3);
    START_TIMING(t3);
    p3 = b.busqueda_ordenada_2(0, 100000);
    STOP_TIMING(t3);
    std::cout << "El valor se encuentra en la posicion " << p3 << std::endl;
    SHOW_TIMING(t3, "Busqueda Ordenada 2: ");

    DECLARE_TIMING(t4);
    START_TIMING(t4);
    p4 = b.busqueda_binaria(0, 100000);
    STOP_TIMING(t4);
    std::cout << "El valor se encuentra en la posicion " << p4 << std::endl;
    SHOW_TIMING(t4, "Busqueda Binaria: ");

    return 0;
}
