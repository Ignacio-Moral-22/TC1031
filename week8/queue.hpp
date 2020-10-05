#ifndef _QUEUE_HPP
#define _QUEUE_HPP
#include "linked_lists.hpp"

template<class T>
class Queue: public LinkedList<T>{
    public:
        ~Queue(){};
        Queue(){};

        void enqueue(T val){
            this->push(val);
        };

        T dequeue(){
            //devolver el elemento al inicio
            Node<T> *ptr = this->head;
            if(ptr == nullptr){
                throw "Error, Queue is empty";
            }

            if(ptr->get_next() == nullptr){
                T res = ptr->get_val();
                delete ptr;
                this->head == nullptr;
                return res;
            }

            Node<T> *pre = nullptr;
            while(ptr->get_next() != nullptr){
                pre = ptr;
                ptr = ptr->get_next();
            }

            T res = ptr->get_val();
            //eliminar el elemento al inicio
            delete ptr;
            pre->set_next(nullptr);
            return res;
        };

        

    protected:
        using LinkedList<T>::push;
        using LinkedList<T>::append;
        using LinkedList<T>::insert_item;
        using LinkedList<T>::delete_item;
        using LinkedList<T>::get_nth;
};

#endif