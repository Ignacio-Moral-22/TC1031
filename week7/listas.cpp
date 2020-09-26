#include "linked_lists.hpp"
int main(){
    LinkedList<int> list;
    list.push(3);
    list.push(8);
    list.push(5);
    list.push(10);
    list.push(2);
    list.push(1);
    list.insert_item(145673, 6);
    list.delete_item(4);
    list.print();
    int item;
    list.get_nth(5, item);
    std::cout << item << std::endl;
    return 0;
}