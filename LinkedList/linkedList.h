// C++
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include<stdio.h>
#include<iostream>
#include <exception> 
using namespace std;

template<class T>
struct node{

    node(){
        next = NULL;
    }
    T data;
    node<T>* next;
};


template<class T>
class LinkedList{

    private:
        node<T> *first;
        node<T> *last;
        int Size = 0;
    public:
    
        LinkedList(){
            first = NULL;
            last = NULL;
        };
        void add(T data){

            if(isEmpty()){

                first = new node<T>;
                first->data = data;
                first->next = NULL;
                last = first;
            }
            else{

                if(first == last){

                    last = new node<T>;
                    last->data = data;
                    last->next = NULL;
                    first->next = last;
                }
                else{
                    
                    node<T>* tmp = new node<T>;
                    tmp->data = data;
                    tmp->next = NULL;
                    last->next = tmp;
                    last = tmp;
                }
                
            }
            Size++;
        }
        void remove(int index){

            if(isEmpty()){

                printf("Linkedlist is empty\n");
            }
            else if(index == 0 ){

                if( !first->next ){

                    delete first;
                }
                else{

                    node<T> *tmp = first;
                    first = first->next;
                    delete tmp;
                }
                Size--;
            }
            else{

                int count = 1;
                node<T> *tmp = first;
                for( ; (tmp != NULL) && (count++ != index); tmp = tmp->next );
               

                if( !tmp ){
                    
                    cout << "Exception: " << str << "\n";
                    exit(1);
                }
                if(tmp->next == last){
                    // last index 
                    delete last;
                    last = tmp;
                    last->next = NULL;
                }
                else{

                    node<T> *del= tmp->next;
                    tmp->next = tmp->next->next;
                    delete del;
                }
                Size--;
                  
            }
        };
        T get(int index){

            int count = 0;
            node<T> *tmp = first;
            for(; (tmp != NULL) && (count++ != index); tmp = tmp->next );
            try{

                string out_of_range = "Out of range";
                if(!tmp){

                    throw out_of_range;
                }
            }
            catch(string str){
                
                cerr << "Exception: " << str << "\n";
                exit (1);
            }
            return tmp->data;
            
        }
        bool isEmpty(){

            return first == NULL;
        };
        int size(){

            return Size;
        }
        void insert(int index, T insertData){

            if( isEmpty() && (index==0)){

                first = new node<T>;
                first->data = insertData;
                first->next = NULL;
                last = first;
            }
            else if (index == 0){

                node<T> *second = first;
                first = new node<T>;
                first->data = insertData;
                first->next = second;
            }
            else{

                int count = 1;
                node<T> *previous = first;
                for(; (count++ != index) && (previous != NULL); previous = previous->next);

                if( !previous ){

                    cout << "Exception: Out of range" << '\n';
                    exit(1);
                }
                else if(!previous->next){ // insert to last index

                    last = new node<T>;
                    last->data = insertData;
                    last->next = NULL;
                    previous->next = last;
                }
                else{

                    node<T>* tmp = new node<T>;
                    tmp->data = insertData;
                    tmp->next = previous->next;
                    previous->next = tmp; 
                }

            }
            
            Size++;
        }
        T getFirst(){
            return first->data;
        }
        T getLast(){
            return last->data;
        }
};





#endif