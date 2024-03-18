#include<iostream>
#include<list>
using namespace std;
template <typename T>
class Nodo {
private:
T dato;
Nodo* next;

public:
Nodo(){
next=NULL;
}
Nodo (T d){
dato=d;
next=Null;
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

void set_next(Nodo<T>* n){
next=n;

}


};

template <typename T>
class Lista
{
    private:
    Nodo<T>* ptr;
    int size;

        /* data */
    public:
        Lista(){
        ptr=NULL;
        size=0;
        }
/*

struct dato {
 int i;
 dato *s;
 }*a, *i, *p, *e;
 
int da;
 
int buscar(int d);
void insertar(int dat);
void mostrar(void);
void borrar(void);
void menu(void);
void guardar(void);
void cargar(void);
}
list<int> Lista;
push_back(elemento)
nombredeLista.proceso*/



};

int main(){
list<string> frutas;
frutas.push_back("manzana");
frutas.push_back("pera");
frutas.push_back("uvas");
frutas.push_back("melon");
frutas.push_back("fresa");
for (const auto & elemento:frutas)
{
cout<< elemento<<"";
}
auto it=next(frutas.begin(),1);
frutas.insert(it,"arandanos");
for (const auto & elemento:frutas)
{
cout<< elemento<<"";
}
frutas.pop_front();

auto it1=next(frutas.begin(),2);
frutas.erase(it1);
frutas.remove("uvas");
frutas.front();
frutas.back();
auto it2=next(frutas.begin(),3);
cout<<*it2;
frutas.at(2);
frutas.clear();
frutas.resize(10);
frutas.empty();
frutas.size();
frutas.max_size();

return 0;
};
