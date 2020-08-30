#include <iostream>
using namespace std;

int MCD(int m, int n);

int main(){
    int m, n, temp;
    cout << "Escribe el valor del primer numero: " << endl;
    cin >> m;
    cout << "Escribe el valor del segundo numero: " << endl;
    cin >> n;
    if (m<n){
        temp=m;
        m=n;
        n=temp;
    }
    cout << "El maximo comun divisor entre " << m << " y " << n << " es " << MCD(m, n) << endl;
    return 0;
}

int MCD(int m, int n){
    int r=m%n;
    if (r==0){
        return n;
    } else {
        return MCD(n, r);
    }
}