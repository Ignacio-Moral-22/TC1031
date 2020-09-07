#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "sorter.hpp"
#include "mytimer.h"

template<typename T>
void printVector(std::vector<T> &arreglo, T count){
    for(size_t i=0; i<count;i++){
        if(i==count-1){
            std::cout << arreglo[i] << std::endl;
        }else{
            std::cout << arreglo[i] << ", ";
        }
    }
};

int main(){
    srand(time(NULL));
    std::vector<int> elementos_f, elementos_f_Selection, elementos_f_Bubble,
    elementos_f_Insertion, elementos_f_Merge;
    int count=10000;
    for(int i=0; i<count; i++){
        elementos_f.push_back(rand()%10000+1);
        elementos_f_Selection.push_back(elementos_f.at(i));
        elementos_f_Bubble.push_back(elementos_f.at(i));
        elementos_f_Insertion.push_back(elementos_f.at(i));
        elementos_f_Merge.push_back(elementos_f.at(i));
    }
    
    DECLARE_TIMING(t1);
    DECLARE_TIMING(t2);
    DECLARE_TIMING(t3);
    DECLARE_TIMING(t4);

    Selection<int> Selection_Sort;
    START_TIMING(t1);
    Selection_Sort.sort(elementos_f_Selection);
    STOP_TIMING(t1);
    printVector(elementos_f_Selection, 100);
    SHOW_TIMING(t1, "Selection Sort Timing");
    
    Bubble<int> Bubble_Sort;
    START_TIMING(t2);
    Bubble_Sort.sort(elementos_f_Bubble);
    STOP_TIMING(t2);
    printVector(elementos_f_Bubble, 100);
    SHOW_TIMING(t2, "Bubble Sort Timing");
    
    Insertion<int> Insertion_Sort;
    START_TIMING(t3);
    Insertion_Sort.sort(elementos_f_Insertion);
    STOP_TIMING(t3);
    printVector(elementos_f_Insertion, 100);
    SHOW_TIMING(t3, "Insertion Sort Timing");

    
    MergeSort<int> Merge_Sort;
    START_TIMING(t4);
    Merge_Sort.sort(elementos_f_Merge);
    STOP_TIMING(t4);
    printVector(elementos_f_Merge, 100);
    SHOW_TIMING(t4, "Merge Sort Timing");
    return 0;
}
