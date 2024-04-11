#include <iostream>
#include <limits>

using namespace std;

template <typename T> class RegAst{
    private:
        unsigned int quant;
        T* elements;
    
    public:
        RegAst(){
            this->quant = 0;
            this->elements = new T[0];
        }

        void addE(T ast){
            T* novoArray = new T[quant+1];

            for(int i=0;i<this->quant;i++){
                novoArray[i] = this->elements[i];
            }

            novoArray[this->quant] = ast;

            delete this->elements;
            this->elements = novoArray;

            this->quant++;
        }

		T getAst(unsigned int pos){
			return this->elements[pos];
		}

		int getQuant(){
			return this->quant;
		}

		~RegAst(){
			delete[] elements;
		}
};

class Astronauta{
    private:
        int idade;
        string cpf;
        string nome;

    public:
    	Astronauta(int idade = 0, string cpf = "00000000000", string nome = "Pedro"){
			this->idade = idade;
			this->cpf = cpf;
			this->nome = nome;
		}

		int getIdade(){
			return this->idade;
		}

		string getCPF(){
			return this->cpf;
		}

		string getNome(){
			return this->nome;
		}


};

int main(){
    RegAst<Astronauta*> RegistroAstronautas;
	int ans = 0;
	int t_idade;
	string t_cpf, t_nome;

	cout << "Quer adicionar um astronauta? (1-SIM / 0-NÃO)" << endl;
	cin >> ans;

	while(ans == 1){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Qual o nome do astronauta?" << endl;
		getline(cin, t_nome);

		cout << "Qual o CPF do astronauta?" << endl;
		getline(cin, t_cpf);

		cout << "Qual a idade do astronauta?" << endl;
		cin >> t_idade;

		Astronauta* ast = new Astronauta(t_idade, t_cpf, t_nome);
		RegistroAstronautas.addE(ast);

		cout << "Ainda quer adicionar? (1-SIM / 0-NÃO)" << endl;
		cin >> ans;
	}

	for(int i=0;i<RegistroAstronautas.getQuant();i++){
		cout << "Nome: " << RegistroAstronautas.getAst(i)->getNome() << endl;
		cout << "CPF: " << RegistroAstronautas.getAst(i)->getCPF() << endl;
		cout << "Idade: " << RegistroAstronautas.getAst(i)->getIdade() << endl;
	}

    return 0;
}
