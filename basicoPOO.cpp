#include<iostream>
using namespace std;

class Animal{
    //atributos
    public: //identificador de acceso
    string nombreAnimal;
    int edad;
    //metodos modificador de acceso,valor de retorno, nombre (parametro)
    public:
    void crearAnimal(){
        cout<<"Por favor registre el nombre del animal";
        cin>>nombreAnimal;
    }
    void consultarAnimal(){
        cout<<"El nombre del animal es: "<<nombreAnimal;
    }
};
class Carro{
    public:
    string motor;
    string modelo;
    int anio;
    Carro(string x,string y,int z){
        motor=x;
        modelo=y;
        anio=z;
    }
}
int main(){

    //instancia de clase->Objeto , nombre de la clase nombre del objeto
    Animal oso;
    Animal tigre;
    //acceder a los atributos: nombre del objeto.nombre_atributo
    oso.nombreAnimal="Tonny";
    //o
    cout<<"Por favor registre el nombre del animal";
    cin>>oso.nombreAnimal;
    //acceder a metodos nombre_objeto.nombre_metodo
    oso.crearAnimal();
}
