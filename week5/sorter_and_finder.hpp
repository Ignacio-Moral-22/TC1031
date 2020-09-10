#ifndef sorter_hpp
#define sorter_hpp

#include <iostream>
#include <vector>
#include <cmath>

template<class T>
class Sorter{
    public:
    Sorter() {};
    ~Sorter() {};

    void swap(T primero, T segundo, std::vector<T> &arreglo){
        T temp;
        temp=arreglo.at(primero);
        arreglo.at(primero)=arreglo.at(segundo);
        arreglo.at(segundo)=temp;
    }
    virtual void sort(std::vector<T> &arreglo){}
};

template<class T>
class Bubble: public Sorter<T>{
    public:
    Bubble(){};
    ~Bubble(){};
    void ordenaBurbuja(std::vector<T> &B){
        for(size_t i=B.size()-1; i>=0; i--){
            bool noSwap = true;
            size_t min = i;
            for(size_t j = 0; j < i; j++){
                if(B.at(j) > B.at(j + 1)){
                    noSwap = false;
                    Sorter<T>::swap(j, j+1, B);
                }
            }
            if (noSwap==true) break;
        }
    };
};

template<class T>
class Insertion: public Sorter<T>{
    public:
    Insertion(){};
    ~Insertion(){};

    void ordenaIncersion(std::vector<T> &I){
        T key;
        for(size_t i=1; i<I.size()-1;i++){
            key = I.at(i);
            int j=i-1;
            while(j>=0 && I.at(j)>key){
                I.at(j+1)=I.at(j);
                j--;
            }
            I.at(j+1)=key;
        }
    };
};

template <class T>
class Quick_Sort: public Sorter<T>{
    public:
    Quick_Sort(){};
    ~Quick_Sort(){};
    
    void ordenaQuick(std::vector<T> &Q){
        quicksort(Q, 0, Q.size()-1);
    };

    void quicksort(std::vector<T> &Q, int low, int high){
        if(low<high){
            int pivot=partition(Q, low, high);
            quicksort(Q, low, pivot-1);
            quicksort(Q, pivot+1, high);
        }
    };

    int partition(std::vector<T> &Q, int low, int high){
        T pivot=Q.at(high);
        size_t i = low-1;
        for(size_t j=low; j<high; j++){
            if(Q.at(j)<pivot){
                i++;
                Sorter<T>::swap(i, j, Q);
            }
        }
        Sorter<T>::swap(i+1, high, Q);
        return (i+1);
    };
};

template <class T>
class Busqueda{
    public:
    Busqueda(){};
    ~Busqueda(){};
    T busqSecuencial(std::vector<T> &valores, int valor){
        int count = 0;
        while(count<valores.size()){
            if(valores.at(count)==valor){
                break;
            }
            count+=1;
        }
        if(count==valores.size()) return -1;
        return count;
    }

    T busqBinaria(T inicio, T final, std::vector<T> &valores, T valor){
        if(final>=inicio){
            int i=inicio + (final-inicio)/2;
            if(valores[i]==valor){
                return i;
            } 
            if (valores[i]>valor){
                return busqBinaria(inicio, i-1, valores, valor);
            }
            return busqBinaria(i+1, final, valores, valor);
        }
        return -1;
    }

};



#endif