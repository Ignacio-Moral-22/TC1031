#ifndef linked_lists_hpp
#define linked_lists_hpp

#include <stddef.h>
#include <iostream>

template <class T>
class Node{
    private:
        T val;
        Node<T> *next;
    public:
        ~Node<T>();
        Node<T>(T pVal, Node<T> *pNext){
            val = pVal;
            next = pNext;
        };

        T get_val(){
            return val;
        };

        void set_val(T pVal){
            val = pVal;
        };

        Node<T> *get_next(){
            return next;
        };

        void set_next(Node<T> *pNext){
            next = pNext;
        };

};


template <class T>
class LinkedList{
    private:
        Node<T> *head;
        // Node<T> *tail;

    public:
        ~LinkedList(){
            //To be implemented
        };
        LinkedList(){
            head = NULL;
            /*
            head = nullptr;
            Tanto NULL en stddef.h como nullptr es lo mismo
            */
        };

        int length(){
            Node<T> *ptr = head;
            int length=0;
            while(ptr != NULL){
                length++;
                ptr = ptr->get_next();
            }
            return length;
        };

        void push(T pVal){
            Node<T> *node = new Node<T>(pVal, head);
            head = node;
        };

        void append(T pVal){
            Node<T> *ptr = head;
            while(ptr->get_next() != NULL){
                ptr = ptr->get_next();
            }

            Node<T> *node = new Node<T>(pVal, NULL);
            ptr->set_next(node);

        };

        void print(){
            Node<T> *ptr = head;
            while (ptr != NULL)
            {
                std::cout << ptr->get_val() << ", " ;
                ptr=ptr->get_next();
            }
            std::cout << std::endl;
        }

        int insert_item(T pVal, int index){
            if(index>length()){
                return -1;
            };
            if(index<0){
                return -2;
            }

            if(index==0){
                push(pVal);
                return 1;
            }
            
            int i=0;
            Node<T> *ptr = head;
            Node<T> *pre = NULL;
            while(ptr != NULL && index > i){
                pre = ptr;
                ptr = ptr->get_next();
                i++;
            }

            Node<T> *node = new Node<T>(pVal, ptr);
            pre->set_next(node);
            return 1;
        };

        int is_empty(){
            return head == NULL ? true : false;
            //return head == NULL
            /*
            if(head==NULL){
                return true;
            }
            return false;
            */
        }

        int delete_item(int index){
            if(index>=length()){
                return -1;
            };
            if(index<0){
                return -2;
            };
            if(is_empty()){
                return -3;
            };
            if(index==0){
                Node<T> *temp = head;
                head = head->get_next();
                delete temp;
                return 1;
            };

            int i=0;
            Node<T> *ptr = head;
            Node<T> *pre = NULL;
            while (ptr->get_next()!=NULL && index>i)
            {
                pre = ptr;
                ptr = ptr->get_next();
                i++;
            }
            pre->set_next(ptr->get_next());
            delete ptr;
            return 1;
        };

        int get_nth(int index, T &item){
            int i=0;
            Node<T> *ptr=head;
            while (ptr->get_next()!=NULL && index>i)
            {
                ptr = ptr->get_next();
                i++;
            }
            item = ptr->get_next();
            return 1;
        };
};

#endif