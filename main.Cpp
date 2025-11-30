#include <string>
#include <iostream>

using namespace std;

class Pokemon {
    protected: 
    string nome;
    int level;
    float pv;
    float ataqueBase;
    float defesaBase;

    public:
    virtual void exibirDetalhes() {
        cout << "Pokemon: " << nome << " | PV: " << pv << endl;
    }

    virtual float calcularAtaque() {
        return ataqueBase;
    }

    virtual void receberDano(float valor){
        if(valor < pv){
            pv -= valor;
        } else {
            pv = 0; // Morreu
        }
    }

    virtual void curar(int quantidade){
        pv += quantidade;
        cout << nome << " recuperou " << quantidade << " de vida!" << endl;
    }
};

class PokemonFogo : public Pokemon {
    protected: 
    float bonusFogo = 0.3; //lembrar de colocar algo de 1 a 10%!
    public:
    PokemonFogo(string nomeRecebido, int pontosVida, float atk,  float def) {
        this->nome = nomeRecebido;
        this->pv = pontosVida;
        this->ataqueBase = atk;
        this->defesaBase = def;
    }

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

class PokemonAgua : public Pokemon {
    protected:
    float resistenciaAgua; // Atributo ÚNICO de água

    public:
    PokemonAgua(string nome, float pv, float ataqueBase, float defesaBase) {
        // Preenchendo a classe pai
        this->nome = nome;
        this->pv = pv;
        this->ataqueBase = ataqueBase;
        this->defesaBase = defesaBase;
        
        this->resistenciaAgua = 0.15; // 15% de resistência a dano
        this->level = 1;
    }

    // Sobrescreve receberDano para aplicar a resistência
    void receberDano(float valor) override {
        float danoReduzido = valor - (valor * resistenciaAgua);
        
        cout << nome << " usou sua resistencia de agua! Dano reduzido de " << valor << " para " << danoReduzido << endl;
        
        // Chama a lógica padrão da classe pai para descontar a vida
        Pokemon::receberDano(danoReduzido);
    }

    void exibirDetalhes() override {
        cout << "[AGUA] " << nome << " (Lvl " << level << ")"
             << "\nPV: " << pv 
             << "\nAtaque: " << ataqueBase 
             << "\nResistencia: " << (resistenciaAgua * 100) << "%" << endl;
    }
};

class PokemonPlanta : public Pokemon {
    protected:
    float regeneracaoExtra; // Atributo ÚNICO de planta

    public:
    PokemonPlanta(string nome, float pv, float ataqueBase, float defesaBase) {
        // Preenchendo a classe pai
        this->nome = nome;
        this->pv = pv;
        this->ataqueBase = ataqueBase;
        this->defesaBase = defesaBase;
        
        this->regeneracaoExtra = 10.0; // Cura 10 a mais
        this->level = 1;
    }

    // (1.15x)
    float calcularAtaque() override {
        return ataqueBase * 1.15;
    }

    // Sobrescreve curar para adicionar o bônus de planta
    void curar(int quantidade) override {
        float curaTotal = quantidade + regeneracaoExtra;
        pv += curaTotal;
        cout << nome << " absorveu luz solar! Recuperou " << curaTotal << " PV (Bonus de +" << regeneracaoExtra << ")" << endl;
    }

    void exibirDetalhes() override {
        cout << "[PLANTA] " << nome << " (Lvl " << level << ")"
             << "\nPV: " << pv 
             << "\nAtaque: " << calcularAtaque()
             << "\nRegeneracao Bonus: " << regeneracaoExtra << endl;
    }
};


void exibirMenu() {
    cout << "\n=== Sistema de Gestão de Pokémon ===" << endl;
    cout << "1. Capturar Pokémon do Tipo Fogo" << endl;   
    cout << "2. Capturar Pokémon do Tipo Água" << endl;   
    cout << "3. Capturar Pokémon do Tipo Planta" << endl; 
    cout << "4. Listar todos os Pokémon" << endl;         
    cout << "5. Curar um Pokémon" << endl;                
    cout << "6. Simular batalha entre dois Pokémon" << endl;
    cout << "0. Sair" << endl;                            
    cout << "Escolha uma opção: ";
}

Pokemon* capturarPokemonFogo(){
    ;
};

int main(){
    Pokemon* vetorTime[10];
    string nome;
    int level;
    float pv;
    float ataqueBase;
    float defesaBase;
    int opcao;
    int flag = 1;
    do
    {
        exibirMenu();
        cin >> opcao;
        switch(opcao)
        {
            case 1:
                // Lógica para criar Fogo (Opções 1 a 3 - Cadastro) [cite: 39, 40]
                
                cout << ">> Capturando Pokémon de Fogo..." << endl;
                cin.ignore();
                cout << "Insira o nome do pokemon!" << endl;
                getline(cin, nome);
                cout << "Insira o ataque do pokemon!" << endl;
                cin >> ataqueBase;
                cout << "Insira a defesa do pobre coitado!" << endl;
                cin >> defesaBase;
                cin >> pv;
                vetorTime[0] = new PokemonFogo(nome, pv, ataqueBase, defesaBase);
                break;
            case 2:
                // Lógica para criar Água
                cout << ">> Capturando Pokémon de Água..." << endl;
                break;
            case 3:
                // Lógica para criar Planta
                cout << ">> Capturando Pokémon de Planta..." << endl;
                break;
            case 4:
                // Percorrer vetor e chamar exibirDetalhes() [cite: 45]
                cout << ">> Listando equipe..." << endl;
                break;
            case 5:
                // Escolher pelo índice e aplicar curar() [cite: 48, 50]
                cout << ">> Menu de Cura..." << endl;
                break;
            case 6:
                // Escolher atacante/defensor e simular [cite: 54]
                cout << ">> Simulador de Batalha..." << endl;
                break;
            case 0:
                cout << "Saindo do sistema..." << endl;
                flag = 0;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }
    } while (flag == 1);
    

    return 0;
}
