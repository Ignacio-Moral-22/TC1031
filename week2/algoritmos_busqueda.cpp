#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

template<class T> 
class Busqueda{
private:
    std::vector<T> elementos;

    T valor;

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
        for(int i=0; i<elementos.size(); i++){
            if(elementos[i]==valor){
                return i;
            } else if (elementos[i]>valor){
                return -1;
            }
        }
        return -1;
    }

    T busqueda_ordenada_2(T paso, T inicio, T final){
        if(inicio==0 && final==100000) std::sort(elementos.begin(), elementos.end());
        for(int i=inicio; i<=final; i+=paso){
            if(elementos[i]==valor){
                return i;
            }
            if(elementos[i]>valor){
                return busqueda_ordenada_2(paso/4, i-paso, i);
            }
        }
        return -1;
    }
    T busqueda_binaria(T valor, T inicio, T final){
        if(inicio==0 && final==100000) std::sort(elementos.begin(), elementos.end());
        int i=(final-inicio)/2;
        if()
    }
};

int main(){
    srand(time(NULL));
    int numero, p1, p2, p3, p4, paso;
    std::cout << "Dame un numero para buscar." << std::endl;
    std::cin >> numero;
    Busqueda<int> b(numero);
    p1 = b.busqueda_secuencial();
    std::cout << "El valor se encuentra en la posicion " << p1 << std::endl;
    p2 = b.busqueda_ordenada_1();
    std::cout << "El valor se encuentra en la posicion " << p2 << std::endl;
    std::cout << "Dame un numero para cada paso" << std::endl;
    std::cin >> paso;
    p3 = b.busqueda_ordenada_2(paso, 0, 100000);
    std::cout << "El valor se encuentra en la posicion " << p3 << std::endl;
    return 0;
}