#include <iostream>>
#include <vector>

using namespace std;

int encontrarMaximo(const vector<int> &lista){
    int maximo=lista[0];
    for (int i = 0; i < lista.size(); i++)
    {
        if(lista[i]>maximo){
            maximo= lista[i];
        }
    }
    return maximo;
    
}

int main(){
    vector<int> lista={5,12,9,7,3,15,8,10,6,4,18};

    int resultado=encontrarMaximo(lista);
    cout<<"El maximo elemento en la lista es: "<<resultado<<endl;
    return 0;
}
