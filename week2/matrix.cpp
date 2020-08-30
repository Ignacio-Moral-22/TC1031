//Ignacio Moral
//A01028470

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int m_plus_n(int arr[5][6], int valor);
int m_log_n(int arr[5][6], int valor);
int busqueda_binaria(vector<int>, int inicio, int final, int valor);

int main(){
    int arr[5][6]={{1, 1, 1, 0, 1, 1},
                   {1, 1, 0, 0, 0, 1},
                   {0, 1, 0, 0, 0, 1},
                   {0, 1, 0, 0, 0, 1},
                   {0, 0, 0, 0, 0, 1}};
    int columna1, columna2;
    columna1=m_plus_n(arr, 0);
    columna2=m_log_n(arr, 0);
    cout << "La columna es: " << columna1 << endl;
    cout << "La columna es: " << columna2 << endl;
    return 0;
}

int m_plus_n(int arr[5][6], int valor){ //O(m+n)
    int columnav=0, fila=0;
    bool columna=false;
    while(columna==false){ //O(1) -> while booleano para que no afecte a los otros
        for(int i=0;i<6;i++){  //O(m) -> checa todas las columnas de la fila "fila"
            if(arr[fila][i]==valor){
                columnav=i;
                continue;
            }
        }
        for(int j=0; j<5; j++){ //O(n) -> checa todas las filas de la columna "columnav"
            if(arr[j][columnav]==valor){
                columna=true; // Si toda la columna es el valor, se vuelve true
            }else{
                columna=false; //
                break;
            }
        }
        fila=fila+1;
    }
    if (fila<5) return columnav;
    return -1;
}

int m_log_n(int arr[5][6], int valor){//O(m log(n)), pues es un O(log(n)) en un O(m)
    int filas=5;
    int i=0;
    int regreso;
    while(i<filas){ //O(m)
        vector<int> vector_log_n; //Genera un vector con los valores de cada fila
        for(int valor=0;valor<6;valor++){
            vector_log_n.push_back(arr[i][valor]); //Mete los valores de cada fila en un vector
        }
        sort(vector_log_n.begin(), vector_log_n.end()); //Organiza para que podamos usar busqueda binaria 
        regreso=busqueda_binaria(vector_log_n, vector_log_n.front(), vector_log_n.back(), valor); //O(log_n)
        if(regreso!=-1){
            i=i+1; //Si no lo encuentra, baja a la siguiente fila
        } else {
            break; //Si si lo encuentra, se sale del ciclo
        }
    }
    return regreso; //regresa columna, o -1 si no existe
}

int busqueda_binaria(vector<int> v, int inicio, int final, int valor){//O(log(n)) es busqueda binaria
    int medio=ceil((inicio+final)/2);//ceil para que si es 9, cheque 5 y haya 4 y 4 de cada lado, mas el 5to
    if(v[medio]==valor){
        return medio; //el valor que buscas esta en el medio
    } else if (v[medio]<valor){
        return busqueda_binaria(v, medio, final, valor);//el valor que se busca es mayor que el medio
    } else {
        return busqueda_binaria(v, inicio, medio, valor);//el valor que se busca es menor que el medio 
    }
    return -1;//el valor no se encuentra
}