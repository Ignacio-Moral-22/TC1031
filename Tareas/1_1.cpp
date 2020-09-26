#include <iostream>

int suma_directa(int numero);
int suma_iterativa(int numero);
int suma_recursiva(int numero);

int main(){
    int numero, suma1, suma2, suma3;
    std::cout << "Hasta que numero quieres sumar?" << std::endl;
    std::cin >> numero;
    suma1 = suma_directa(numero);
    suma2 = suma_iterativa(numero);
    suma3 = suma_recursiva(numero);
    std::cout << "La suma directa es: " << suma1 << std::endl;
    std::cout << "La suma iterativa es: " << suma2 << std::endl;
    std::cout << "La suma recursiva es: " << suma3 << std::endl;
    return 0;
}

int suma_directa(int numero){
    return (numero*(numero+1))/2;//O(1)
}

int suma_iterativa(int numero){
    int suma=0;
    for(int i=1; i<=numero;i++){//O(n)
        suma+=i;
    }
    return suma;
}

int suma_recursiva(int numero){
    if(numero==1){
        return 1;//O(1)
    }
    return numero+suma_recursiva(numero-1);//O(1)
}