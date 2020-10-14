#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <sstream>

int main()
{
    std::cout << "Enter the list values separated by spaces: " << std::endl;
    std::string line, val;
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::queue<int> listaA;
    std::stack<int> listaB;
    while(std::getline(ss,val, ' '))
    {
        listaA.push(atoi(val.c_str()));
        listaB.push(atoi(val.c_str()));
    }
    
    std::vector<int> output;
    while(!listaA.empty() && !listaB.empty())
    {
        std::cout << "A has: " << listaA.front() << " and B has: " << listaB.top() << std::endl;
        if(listaA.front() > listaB.top())
        {
            std::cout << "\tAdding 1 to output\n";
            output.push_back(1);
            listaB.pop();
        }
        else if(listaA.front() < listaB.top())
        {
            std::cout << "\tAdding 2 to output\n";
            output.push_back(2);
            listaA.pop();
        }
        else
        {
            std::cout << "\tAdding 0 to output\n";
            output.push_back(0);
            listaA.pop();
            listaB.pop();
        }
        
    }

    for(size_t i = 0; i < output.size(); i++)
    {
        std::cout << output.at(i) << " ";
    }

    return 0;
}