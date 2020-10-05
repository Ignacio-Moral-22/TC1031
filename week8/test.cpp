#include "linked_lists.hpp"
#include "stack.hpp"
#include "queue.hpp"

int main(){
    // Stack<int> stacks;
    // stacks.push(4);
    // stacks.push(32);
    // stacks.push(3);
    // stacks.push(56);
    // stacks.push(49);
    // int flag;
    // std::cout << stacks.pop(flag) << std::endl;
    // stacks.print();
    // std::cout << stacks.pop(flag) << std::endl;
    // stacks.print();
    // std::cout << stacks.pop(flag) << std::endl;
    // stacks.print();
    // std::cout << stacks.pop(flag) << std::endl;
    // stacks.print();
    // std::cout << stacks.pop(flag) << std::endl;

    // try{
    //     std::cout << stacks.peek() << std::endl;
    // } catch (const std::exception &e){
    //     std::cerr << e.what() << "\n";
    // }

    Queue<int> queues;
    queues.enqueue(4);
    queues.enqueue(32);
    queues.enqueue(7);
    queues.enqueue(9);
    queues.print();
    std::cout << queues.dequeue() << std::endl;
    std::cout << queues.dequeue() << std::endl;
    std::cout << queues.dequeue() << std::endl;
    std::cout << queues.dequeue() << std::endl;
    std::cout << queues.dequeue() << std::endl;
    return 0;
}