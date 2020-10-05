#ifndef _STACKS_HPP
#define _STACKS_HPP
#include "linked_lists.hpp"


template<class T>
class Stack: public LinkedList<T>
{
    public:
        ~Stack(){};
        Stack(){};
        
        T pop(int &flag){
          //devolver el valor en top 
          //eliminar el valor en top
          if(this->is_empty()){
              flag = 0;
              return T();
          }

          T res = this->head->get_val();
          this->delete_item(0);
          return res;  
        };

        T peek(){
          if(this->is_empty()){
              throw "Error, Stack is empty";
          }
            return this->head->get_val();
        }

protected:
    using LinkedList<T>::insert_item;
    using LinkedList<T>::append;
    using LinkedList<T>::delete_item;
    using LinkedList<T>::get_nth;
};

#endif