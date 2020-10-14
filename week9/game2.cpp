#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>

int main()
{
    srand (time(NULL));
    int numeros;
    std::cout << "Enter the amount of numbers you wish to include: " << std::endl;
    std::cin >> numeros;
    std::vector<int> listaA;
    std::vector<int> listaB;
    for(size_t i = 0; i < numeros; i++)
    {
        int a = rand()%100 + 1;
        listaA.push_back(a);
        listaB.push_back(a);
    }
    
    int iA = 0;
    int iB = listaB.size()-1;
    std::vector<int> output;
    while(iA<listaA.size() && iB>0)
    {
        std::cout << "A has: " << listaA.at(iA) << " and B has: " << listaB.at(iB) << std::endl;
        if(listaA.at(iA) > listaB.at(iB))
        {
            std::cout << "\tAdding 1 to output\n";
            output.push_back(1);
            iB--;
        }
        else if(listaA.at(iA) < listaB.at(iB))
        {
            std::cout << "\tAdding 2 to output\n";
            output.push_back(2);
            iA++;
        }
        else
        {
            std::cout << "\tAdding 0 to output\n";
            output.push_back(0);
            iA++;
            iB--;
        }
        
    }

    for(size_t i = 0; i < output.size(); i++)
    {
        std::cout << output.at(i) << "\n";
    }

    std::cout << std::endl;
    return 0;
}