#include "linked_lists.hpp"
int main(){
    LinkedList<int> list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(6);
    list.push(9);
    list.print();
    list.insert_item(145673, 6);
    // list.delete_item(4);
    list.reverse();
    list.print();
    list.removeDuplicates();
    list.print();
    Node<int> newnode(7, NULL);
    list.sortedInsert(newnode);
    int item;
    list.get_nth(5, item);
    std::cout << item << std::endl;
    list.deleteList();
    list.push(1);
    list.print();

    list.count(5);
    return 0;
}