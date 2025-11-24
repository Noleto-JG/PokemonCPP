#include <string>
#include <iostream>

using namespace std;

class Pokemon {
    protected:
    string nome;
    int level;
    int pv;
    float ataqueBase;
    float defesaBase;

    
    virtual void exibirDetalhes(){};

    virtual float calcularAtaque(){};

    virtual void receberDano(float valor){
        if(valor < pv){
            pv -= valor;
        }
        else pv -= pv;
    };

    void curar(int quantidade){};

};


int main(){


    return 0;
}
