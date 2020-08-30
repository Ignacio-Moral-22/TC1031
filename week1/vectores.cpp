#include <iostream>
#include <vector>
using namespace std;

int vectorsuma(int n, vector<int> v);

int main(){
    int value, l, suma;
    cout << "How long do you want the vector to be?" << endl;
    cin >> l;
    vector<int> v;
    for(int i=0; i<l; i++){
        cout << "Input the value in position " << i << endl;
        cin >> value;
        v.push_back(value);
    }
    suma=vectorsuma(l, v);
    cout << "La suma de todos los valores es: " << suma << endl;
    return 0;
}

int vectorsuma(int n, vector<int> v){
    if(n==1){
        return v[n-1];
    }
    
    return v[n-1] + vectorsuma(n-1, v);
}