#include <iostream>

using namespace std;
int gsum, gtemp;
int capicua(int n);

int main(){
    int number, vuelta;
    cout << "Escribe el numero que quieras escribir al reves" << endl;
    cin >> number;
    vuelta=capicua(number);
    cout << vuelta << endl;
    return 0;
}

int capicua(int n){
    if (n>0){
        gtemp=n%10;
        gsum=gsum*10+gtemp;
        capicua(n/10);
    } else {
        return gsum;
    }
}