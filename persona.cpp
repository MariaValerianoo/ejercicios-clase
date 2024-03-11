#include<iostream>
using namespace std;


class Persona{

    private:
    int tipoDoc;
    int documento;
    string nombre;
    string apellido;
    double estatura;
    int edad;
    int sexo;
    double peso;
    //Accesores set para modificar y get para mostrar 

    void settipoDoc(int _tipoDoc){

        tipoDoc = _tipoDoc;

    }

    int gettipoDoc(){

        return tipoDoc;

    }
    void setdocumento(int _documento){

        documento = _documento;

    }

    int getdocumento(){

        return documento;

    }
    void setestatura(double _estatura){

        estatura = _estatura;

    }

    double getestatura(){

        return estatura;

    }
    void setpeso(double _peso){

        peso = _peso;

    }

    double getpeso(){

        return peso ;

    }
    void setedad(int _edad){

        edad = _edad;

    }

    int getedad(){

        return edad;

    }
    void setsexo(int _sexo){

         sexo= _sexo;

    }

    int getsexo(){

        return sexo;

    }
    void setnombre(string _nombre){

        nombre = _nombre;

    }

    string getnombre(){

        return nombre;

    }
    void set(string _apellido){

         apellido = _apellido;

    }

    string getapellido(){

        return apellido;

    }



    

    public:
    void pedirDatos(){
        cout<<"Ingresa tu tipo de documento\n 1)Cedula \n 2)Tarjeta de identidad \n 3)cedula extranjeria"<<endl;
        cin>>tipoDoc;
        cout<<"Cual es tu documento: \n";
        cin>>documento;
        cout<<"Cual es tu nombre: \n";
        cin>>nombre;
        cout<<"Cual es tu apellido: \n";
        cin>>apellido;
        cout<<"Cual es tu estatura: \n";
        cin>>estatura;
        cout<<"Cual es tu peso: \n";
        cin>>peso;
        cout<<"Cual es tu edad: \n";
        cin>>edad;
        cout<<"Cual es tu sexo \n1)femenino\n 2)masculino: \n";
        cin>>sexo;

    };

    void mostrarPersonal(){
        cout<<"Tus datos son:\n";
        if(tipoDoc==1){
            cout<<"Tu tipo de documento es: cedula\n";
        }else if(tipoDoc==2){
            cout<<"Tu tipo de documento es: Tarjeta de identidad \n";
        }else if(tipoDoc==3){
            cout<<"Tu tipo de documento es: Cedula de extranjeria \n";
        }
        cout<<"Tu documento es: "<<documento<<endl;
        cout<<"Tu nombre es: "<<nombre<<endl;
        cout<<"Tu apellido es: "<<apellido<<endl;
        cout<<"Tu estatura es: "<<estatura<<endl;
        cout<<"Tu peso es: "<<peso<<endl;
        cout<<"Tu edad es: "<<edad<<endl;
        if(sexo==1){
            cout<<"Tu sexo es: Femenino"<<endl;
        }else if(sexo==2){
            cout<<"Tu sexo es: Masculino "<<endl;
        }

    };
    void calcularmc(){
        double pesoActual = (peso/estatura)*(peso/estatura);
        if (pesoActual<20.5){
            cout<<"El peso esta por debajo de lo ideal:("<<endl;
        }else if(pesoActual>=20.0 && pesoActual<=25.0){
            cout<<"El peso es el ideal :)"<<endl;
        }else if(pesoActual>25.0){
            cout<<"Tienes sobrepeso:("<<endl;
        };

    }
    void mayorEdad(){

        if (edad>=18){
            cout<<"Eres mayor de edad:)";
        }else{
            cout<<"Eres menos de edad:("<<endl;
            if(tipoDoc==1){
                cout<<"Tu documento seria Tarjeta de identidad "<<endl;
            }
        }
    }
};
int main(){
    Persona persona1;
    persona1.pedirDatos();
    persona1.mostrarPersonal();
    persona1.calcularmc();
    persona1.mayorEdad();
}