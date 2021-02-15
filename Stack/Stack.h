#ifndef _STACK_H_
#define _STACK_H_
#include<iostream>
using namespace std;
template<class T>
struct node
{
    node(){
        previous = NULL;
    }
    T data;
    node<T>* previous;
};
template<class  T>
class Stack{
    private:
        node<T> *Top;
        int Size = 0;
    public:
        void pop(){

            if(isEmpyt()){

                cout << "Exception: Stack is empty." << "\n";
                exit(1);
            }
            else{

                node<T> *tmp = Top;
                Top = Top->previous;
                delete tmp;
                Size--;
                 
            }
        }
        T top(){
            
            if(isEmpyt()){

                cout << "Exception: Stack is empty." << "\n";
                exit(1);
            }
            else{

                return Top->data;
            }
        }
        void push(T pushData){

            if(isEmpyt()){

                Top = new node<T>;
                Top->data = pushData;

            }
            else{

                node<T> *tmp = Top;
                Top = new node<T>;
                Top->data = pushData;
                Top->previous = tmp;
            }
            Size++;
        }
        bool isEmpyt(){

            return Top == NULL;
        }
        int size(){

            return Size;
        }
        
};




#endif