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

    public:
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

class PokemonFogo : Pokemon {
    protected: 
    float bonusFogo; //lembrar de colocar algo de 1 a 10%!

    public:
    float calcularAtaque() override {
        return ataqueBase + (ataqueBase * bonusFogo);
    }

    void receberDano(float valor) override {
        if((valor + (valor * bonusFogo)) < pv){
            pv -= valor + (valor * bonusFogo);
        }
        else pv -= pv;
    }
    
};

class PokemonAgua : Pokemon {
    protected:
    float resistenciaAgua; //novamente, de 1 a 5%!

    public:
    void receberDano(float valor) override {
        if ((valor - (valor * resistenciaAgua)) < pv){
            pv -= (valor - (valor * resistenciaAgua));
        }
        else pv -= pv;
    }
};

class PokemonPlanta : Pokemon {
    protected:
    float regeneracao;

    float calcularAtaque() override {
        return ataqueBase * 1.15;
    }


};



int main(){


    return 0;
}
