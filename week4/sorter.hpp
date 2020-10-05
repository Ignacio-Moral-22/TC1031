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
class Selection: public Sorter<T>{
    public:
    Selection(){};
    ~Selection(){};
    void sort(std::vector<T> &S)
    {
        for (size_t i = 0; i < S.size() - 1; i++)
        {
            size_t min = i;
            for (size_t j = i+1; j < S.size(); j++)
            {
                if (S.at(j) < S.at(min))
                    min = j;
            }
            Sorter<T>::swap(i, min, S);
        }      
    };
};

template<class T>
class Bubble: public Sorter<T>{
    public:
    Bubble(){};
    ~Bubble(){};
    void sort(std::vector<T> &B){
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

    void sort(std::vector<T> &I){
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

template<class T>
class MergeSort: public Sorter<T>{
    public:
    MergeSort(){};
    ~MergeSort(){};
    void sort(std::vector<T> &M){
        mergesort(M, 0, M.size()-1);
    }

    void mergesort(std::vector<T> &arreglo, int l, int r){
        if (l < r) {
            int m = l + (r-l) / 2;
            mergesort(arreglo, l, m);
            mergesort(arreglo, m+1, r);

            merge(arreglo, l, m, r);
        }
    }

    void merge(std::vector<T> &arreglo, int l, int m, int r){
        int i=l, j=m+1, k=l;
        int temp[arreglo.size()];
        while(i<=m && j<=r){
            if(arreglo[i]<=arreglo.at(j)){
                temp[k]=arreglo.at(i);
                i++, k++;
            } else {
                temp[k]=arreglo.at(j);
                j++, k++;
            }
        }

        while (i<=m){
            temp[k]=arreglo.at(i);
            i++, k++;
        }
        while (j<=r){
            temp[k]=arreglo.at(j);
            j++, k++;
        }
        for(size_t p=l; p<=r; p++){
            arreglo.at(p)=temp[p];
        }
    }
};

#endif