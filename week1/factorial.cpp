#include <iostream>
using namespace std;

int factorial(int n);

int main(){
    int ans, number;
    cout << "Write the number you want the factorial of." << endl;
    cin >> number;
    ans = factorial(number);
    cout << "The factorial of " << number << " is " << ans << endl;
    return 0;
}

int factorial(int n){
    if (n<0){
        throw "Illegal negative number";
    }
    if (n==0 || n==1){
        return 1;
    }
    return n*factorial(n-1);
}