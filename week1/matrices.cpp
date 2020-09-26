#include <iostream>
using namespace std;

int suma_matrices(int f, int c, int *pf, int *pc, int arr[][]);

int main(){
    int f, c, *pf, *pc, suma;
    cout << "Numero de filas: " << endl;
    cin >> f;
    pf=&f;
    cout << "Numero de columnas: " << endl;
    cin >> c;
    pc=&c;
    int matriz[f][c];
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            cout << "Dame el siguiente valor en la matriz." << endl;
            cin >> matriz[i][j];
        }
    }
    suma=suma_matrices(f, c, pf, pc, matriz);

}