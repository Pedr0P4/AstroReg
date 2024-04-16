#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

//Classe para armazenar elementos de qualquer tipo (nesse caso do tipo "Astronauta").
template <typename T> class RegAst{
    private:
        unsigned int quant; //Variável de quantidade de elementos.
        T* elements; //Variável para os elementos.
    
    public:
		//Construtor.
        RegAst(){
            this->quant = 0; //A classe começa com 0 em quant.
            this->elements = new T[0]; //A classe começa com um ponteiro de um array com 0 elementos.
        }

		//Função para adicionar elementos.
        void addE(T ast){
            T* novoArray = new T[quant+1]; //Criação de um ponteiro para um array do tamanho da quantidade de elementos atuais +1.

            for(int i=0;i<this->quant;i++){
                novoArray[i] = this->elements[i]; //Copia todos os elementos de elements da classe para esse novo array.
            }

            novoArray[this->quant] = ast; //No fim do array adiciona o elemento novo. 

            delete this->elements; //Deleta o ponteiro dos elementos da classe.
            this->elements = novoArray; //Os elementos da classe agora recebem o novo array com o novo elemento e os anteriores.

            this->quant++; //Quantidade de elementos é incrementado em 1.
        }

		//Função para mostrar o elemento na posição recebida no parâmetro (pos).
		T getAst(unsigned int pos){
			return this->elements[pos];
		}

		//Função para retornar o valor da quantidade de elementos.
		int getQuant(){
			return this->quant;
		}

		//Destrutor.
		~RegAst(){
			delete[] elements;
		}
};

//Classe com as informações de um astronauta.
class Astronauta{
    private:
        int idade; //Idade do astronauta.
        string cpf; //CPF do astronauta.
        string nome; //Nome do astronauta.

    public:
		//Construtor.
    	Astronauta(int idade, string cpf, string nome = "Pedro"){
			this->idade = idade; //idade da classe recebe idade (parâmetro).
			this->cpf = cpf; //cpf da classe recebe cpf (parâmetro).
			this->nome = nome; //nome da classe recebe nome (parâmetro).
		}

		//Função que retorna o valor da variável idade da classe.
		int getIdade(){
			return this->idade;
		}

		//Função que retorna o conteúdo da variável cpf da classe.
		string getCPF(){
			return this->cpf;
		}

		//Função que retorna o conteúdo da variável nome da classe.
		string getNome(){
			return this->nome;
		}


};

char* formatCPF(string cpf){
	unsigned int stam = cpf.length(); // Para pegar o tamanho da string cpf.
	unsigned int j = 0; // Para controlar o índice de cpf_f.
	char* cpf_f = new char[15]; //criação de um ponteiro para um array de char de tamanho 15.

	//Adição de 0's para completar o cpf caso ele tenha menos de 11 de tamanho
	if(stam < 11){
		string temp(11 - stam, '0');
		cpf += temp;
		stam = cpf.length();
	} else{ //Limitando a string caso o cpf passe de 11 de tamanho
		stam = 11;
	}

	//Loop para formatação da string e inserção no array de char.
	for(int i=0;i<stam;i++){
		if((i+1)%3 == 0 && i <= 6){
			cpf_f[j++] = cpf[i];
			cpf_f[j++] = '.';
		} else if(i > 6 && (i+1)%3 == 0){
			cpf_f[j++] = cpf[i];
			cpf_f[j++] = '-';
		} else{
			cpf_f[j++] = cpf[i];
		}
	}
	cpf_f[j++] = '\0'; //Adição do caractere nulo ao fim do array.

	return cpf_f;
}

Astronauta* addAstro(){
	string nome;
	string cpf;
	int idade;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Qual o nome do astronauta?" << endl;
	getline(cin, nome);

	cout << "Qual o CPF de " << nome << endl;
	getline(cin, cpf);

	cout << "Qual a idade de " << nome << endl;
	cin >> idade;

	Astronauta* astro = new Astronauta(idade, cpf, nome);
	return astro;
}

int main(){
    RegAst<Astronauta*> RegistroAstronautas;
	int ans = -1;

	while(ans != 0){
		cout << "Escolha uma das opções:" << endl;
		cout << "1 - Adicionar astronauta.\n"
			 << "2 - Mostrar astronautas.\n"
			 << "0 - Sair.\n";
		cin >> ans;
		if(ans == 1){
			RegistroAstronautas.addE(addAstro());
		}
		if(ans == 2){
			cout << "\nAstronautas:\n" << endl;

			unsigned int qtastro = RegistroAstronautas.getQuant();

			if(RegistroAstronautas.getQuant() == 0){
				cout << "Não há astronautas cadastrados!" << endl;
			} else{
				unsigned int qt = RegistroAstronautas.getQuant();
				string text = RegistroAstronautas.getAst(0)->getNome();
				unsigned int tamax = text.length();
				unsigned int temptam;

				for(int i=0;i<qt;i++){
					text = RegistroAstronautas.getAst(i)->getNome();
					temptam = text.length();
					if(tamax < temptam){
						tamax = temptam;
					}
				}

				int cpftamanho = 14;
				int tampadrao = 16;
				int tamtotal = (tamax-2) + tamax + cpftamanho + tampadrao + (cpftamanho/2) + tampadrao;

				//Nomes das colunas.
				cout << setw(tamax-2) << left << ""
					<< setw(tamax+cpftamanho) << left << "Nome"
					<< setw(tampadrao+(cpftamanho/2)) << left << "CPF"
					<< setw(tampadrao) << left << "Idade"
					<< endl;

				//Linha para separar.
				cout << setfill('-') << setw(tamtotal) << "-" << endl;
				cout << setfill(' ');

				//Print dos valores de cada astronauta.
				for(int i=0;i<qtastro;i++){
					string t_cpf = RegistroAstronautas.getAst(i)->getCPF();
					cout << setw(tamax/2) << left << ""
						<< setw(tamax+(tamax/2)) << left << RegistroAstronautas.getAst(i)->getNome()
						<< setw((tampadrao/2)) << left << "||"
						<< setw(cpftamanho+(tampadrao/2)) << left << formatCPF(t_cpf)
						<< setw((tampadrao/2)) << left << "||"
						<< setw((tampadrao/2)) << left << RegistroAstronautas.getAst(i)->getIdade()
						<< setw((tampadrao/2)) << left << "||"
						<< endl;
				}
			}
			cout << endl;
		}
	}

    return 0;
}
