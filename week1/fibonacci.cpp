#include <iostream>
#include <map>
using namespace std;

int fibonacci(int n);
int fibonacci_v2(int n, map<int, int> &cache);
int fibonacci_v3(int n);

int main(){
    int ans, ans2, ans3, number;
    cout << "Write the position number in the Fibonacci sequence you want." << endl;
    cin >> number;
    map<int, int> cache;
    cache = {};
    ans = fibonacci(number);
    ans2 = fibonacci_v2(number, cache);
    ans3 = fibonacci_v3(number);
    cout << "The number " << number << " of Fibonacci sequence is " << ans << endl;
    cout << "The number " << number << " of Fibonacci sequence is " << ans2 << endl;
    cout << "The number " << number << " of Fibonacci sequence is " << ans3 << endl;
    return 0;
}

int fibonacci(int n){                     //O(n), porque la linea 28 es (n-1)+(n-2)=2n-3 -> O(n) 
    if (n<2){
        return n;                         //O(1)
    }
    return fibonacci(n-1)+fibonacci(n-2); //(n-1)+(n-2)=2n-3
}

int fibonacci_v2(int n, map<int, int> &cache){ //O(n), porque la linea 35 esta revisando el mapa de forma lineal, por ende es O(n)
    if (n<2){
        return n;                              //O(1)
    }
    if (cache.find(n)!=cache.end()){           //O(n)
        return cache[n];                       //O(1)
    }

    int val = fibonacci_v2(n-2, cache) + fibonacci_v2(n-1, cache); //O(1)
    cache.insert(pair<int,int>(n,val));        //O(1)
    return val;                                //O(1)
}

int fibonacci_v3(int n){    //O(n) total, porque la linea 46 vale O(n)
    int a=0, b=1, fib, i=0; //O(1)
    while(i<n-1){           //n-1 -> O(n)
        fib=a+b;            //O(1)
        a=b;                //O(1)
        b=fib;              //O(1)
        i++;
    }
    return fib;             //O(1)
} 