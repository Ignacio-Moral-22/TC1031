#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "sorter_and_finder.hpp"
#include "mytimer.h"

int main(){
    DECLARE_TIMING(t);
    srand(time(0));
    std::vector<int> valores;
    int elementos, numero, ordena, busca, posicion;
    std::cout << "Cuantos elementos quieres?" << std::endl;
    std::cin >> elementos;
    for(int i=0; i<elementos;i++){
        valores.push_back(rand()%elementos);
    }
    std::cout <<"Que numero quieres buscar?" << std::endl;
    std::cin >> numero;
    std::cout <<"Que metodo de busqueda quieres? 1 para secuencial, 2 para Binaria" <<std::endl;
    std::cin >> busca;
    try{
    if(busca>2 || busca<1) throw 91;}
    catch(int n){std::cout << "Illegal number"; busca=2;};

    Busqueda<int> b;
    if(busca==1){
        START_TIMING(t);
        posicion = b.busqSecuencial(valores, numero);
        STOP_TIMING(t);
    } else {
        
        std::cout << "Que metodo de ordenamiento?" << std::endl;
        std::cout <<"1. Burbuja\n2. Insercion\n3. Quick" << std::endl;
        std::cin >> ordena;
        
        if (ordena==1){
            Bubble<int> bur;
            START_TIMING(t);
            bur.ordenaBurbuja(valores);
            posicion=b.busqBinaria(0, elementos, valores, numero);
            STOP_TIMING(t);
        }else if (ordena==2){
            Insertion<int> i;
            START_TIMING(t);
            i.ordenaIncersion(valores);
            posicion=b.busqBinaria(0, elementos, valores, numero);
            STOP_TIMING(t);
        } else {
            START_TIMING(t);
            Quick_Sort<int> q;
            q.ordenaQuick(valores);
            posicion=b.busqBinaria(0, elementos, valores, numero);
            STOP_TIMING(t);
        }
    }
    std::cout << "El valor se encuentra en la posicion " << posicion << std::endl;
    SHOW_TIMING(t, "Busqueda Binaria Burbuja");
    return 0;
}