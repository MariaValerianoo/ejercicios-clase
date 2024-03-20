#include<iostream>
using namespace std;
template<typename T>
class Nodo{
    private:
    T dato;
    Nodo*next;


    public:
    Nodo(){
        next=NULL;
    }
    Nodo (T d){
        dato=d;
        next=NULL;
    }
    T get_dato(){
        return dato;
    }
    void set_dato(T d){
        dato=d;
    }
    Nodo<T>* get_next(){
        return next;
    }
    void set_next(Nodo<T>*next){
        this->next=next;

    }
};
template<typename T>
class Lista{
    private:
    Nodo<T>*ptr;
    int size;
    public:
    lista(){
        ptr=NULL;
        size=0;
    }
};