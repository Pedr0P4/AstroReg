#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

//Classe para armazenar elementos de qualquer tipo (nesse caso do tipo "Astronauta").
template <typename T> class Registros{
    private:
        unsigned int quant; //Variável de quantidade de elementos.
        T* elements; //Variável para os elementos.
    
    public:
		//Construtor.
        Registros(){
            this->quant = 0; //A classe começa com 0 em quant.
            this->elements = new T[0]; //A classe começa com um ponteiro de um array com 0 elementos.
        }

		//Função para adicionar elementos.
        void addE(T elem){
            T* novoArray = new T[quant+1]; //Criação de um ponteiro para um array do tamanho da quantidade de elementos atuais +1.

            for(int i=0;i<this->quant;i++){
                novoArray[i] = this->elements[i]; //Copia todos os elementos de elements da classe para esse novo array.
            }

            novoArray[this->quant] = elem; //No fim do array adiciona o elemento novo. 

            delete this->elements; //Deleta o ponteiro dos elementos da classe.
            this->elements = novoArray; //Os elementos da classe agora recebem o novo array com o novo elemento e os anteriores.

            this->quant++; //Quantidade de elementos é incrementado em 1.
        }

		//Função para mostrar o elemento na posição recebida no parâmetro (pos).
		T getE(unsigned int pos){
			return this->elements[pos];
		}

		//Função para retornar o valor da quantidade de elementos.
		int getQuant(){
			return this->quant;
		}

		//Destrutor.
		~Registros(){
			delete[] elements;
		}
};

//Classe com as informações de um astronauta.
class Astronauta{
    private:
        int idade; //Idade do astronauta.
		bool vivo; //Se ele está vivo.
        string cpf; //CPF do astronauta.
        string nome; //Nome do astronauta.

    public:
		//Construtor.
    	Astronauta(int idade, string cpf, string nome = "Pedro"){
			this->idade = idade; //idade da classe recebe idade (parâmetro).
			this->vivo = true; //vivo recebe true (NÃO é parâmetro).
			this->cpf = cpf; //cpf da classe recebe cpf (parâmetro).
			this->nome = nome; //nome da classe recebe nome (parâmetro).
		}

		//Função que retorna o valor da variável idade da classe.
		int getIdade(){
			return this->idade;
		}

		//Função que retorna se está vivo ou não.
		bool getVivo(){
			return this->vivo;
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

class Voo{
	private:
		int codigo;
		Registros<Astronauta*> RegistroTripulantes;

	public:
		Voo(int codigo){
			this->codigo = codigo;
		}

		int getCode(){
			return this->codigo;
		}

		unsigned int getQTripul(){
			return this->RegistroTripulantes.getQuant();
		}

		void addTripul(Astronauta* ast){
			this->RegistroTripulantes.addE(ast);
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
	string nome; //Variável para receber o nome do astronauta.
	string cpf; //Variável para receber o CPF do astronauta.
	int idade; // Variável para receber a idade do astronauta.

	//Limpar o buffer.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//Coleta do nome do astronauta.
	cout << "Qual o nome do astronauta?" << endl;
	getline(cin, nome);

	//Coleta do CPF do astronauta.
	cout << "Qual o CPF de " << nome << endl;
	getline(cin, cpf);

	//Coleta da idade do astronauta.
	cout << "Qual a idade de " << nome << endl;
	cin >> idade;

	//Ponteiro para criar um astronauta com os valores fornecidos pelo usuário.
	Astronauta* astro = new Astronauta(idade, cpf, nome);
	return astro; //Retorna o ponteiro.
}

Voo* addVoo(){
	int code_voo;

	cout << "Qual o código do voo?" << endl;
	cin >> code_voo;

	Voo* voo = new Voo(code_voo);
	return voo;
}

int main(){
	//Criação do vetor de ponteiros de Astronautas.
    Registros<Astronauta*> RegistroAstronautas;
	//Criação do vetor de ponteiros de Voos.
	Registros<Voo*> RegistroVoos;

	int ans = -1; //Variável para as escolhas do usuário.

	//Loop while para fazer o programa funcionar enquanto o usuário não quiser sair.
	while(ans != 0){
		//Impressão na tela para o "cardápio" de comandos.
		cout << "Escolha uma das opções:" << endl;
		cout << "1 - Cadastrar astronauta.\n"
			 << "2 - Exibir astronautas.\n"
			 << "3 - Cadastrar voo.\n"
			 << "4 - Exibit voos.\n"
			 << "0 - Sair.\n";
		cin >> ans; //Resposta do usuário.
		if(ans == 1){ //Se for 1.
			//Chama a função addE (adiciona um elemento no vetor) e, como parâmetro, recebe a função addAstro (cria um ponteiro de Astronauta).
			RegistroAstronautas.addE(addAstro());
		} else if(ans == 2){ //Se não for 1, mas 2.
			cout << "\nAstronautas:\n" << endl;

			unsigned int qtastro = RegistroAstronautas.getQuant(); //Variável que carrega a quantidade de astronautas no vetor.
													//^^^^^^^^^^^------> Função da classe do vetor que retorna a quantidade de elementos (astronautas).
			//Caso não haja elementos no vetor (astronautas), imprime uma mensagem de erro.
			if(qtastro == 0){
				cout << "Não há astronautas cadastrados!" << endl;
			} else{ //Caso haja elementos no vetor (astronautas).
				
				string text = RegistroAstronautas.getE(0)->getNome(); //Variável que pegará o nome de cada astronauta.
				unsigned int tamax = text.length(); //Variável para armazenar o maior tamanho de nome, começará com o tamanho do nome do primeiro astronauta do vetor.
				unsigned int temptam; //Variável que carregará um tamanho temporário para que haja a comparação.

				//Loop para que haja a comparação entre os tamanhos de cada elemento do vetor, pra no fim "tamax" carregar o tamanho do maior nome.
				for(int i=0;i<qtastro;i++){
					text = RegistroAstronautas.getE(i)->getNome();
					temptam = text.length();
					if(tamax < temptam){
						tamax = temptam;
					}
				}

				int cpftamanho = 14; //Variável que carrega o tamanho máximo de um CPF já formatado.
				int tampadrao = 16; //Variável que carrega o tamanho padrão (tamanho do cpf + 2 para que haja um pequeno espaçamento (2)).
				int tamtotal = (tamax-2) + tamax + cpftamanho + (cpftamanho/2) + 3*tampadrao; //Tamanho total da largura da tabela.

				//Nomes das colunas.
				cout << setw(tamax-2) << left << ""
					<< setw(tamax+cpftamanho) << left << "Nome"
					<< setw(tampadrao+(cpftamanho/2)) << left << "CPF"
					<< setw(tampadrao) << left << "Idade"
					<< setw(tampadrao) << left << "Situação"
					<< endl;

				//Linha para separar.
				cout << setfill('-') << setw(tamtotal) << "-" << endl;
				cout << setfill(' ');

				//Print dos valores de cada astronauta.
				for(int i=0;i<qtastro;i++){
					string t_cpf = RegistroAstronautas.getE(i)->getCPF();
					bool t_vivo = RegistroAstronautas.getE(i)->getVivo();
					cout << setw(tamax/2) << left << ""
						<< setw(tamax+(tamax/2)) << left << RegistroAstronautas.getE(i)->getNome()
						<< setw((tampadrao/2)) << left << "||"
						<< setw(cpftamanho+(tampadrao/2)) << left << formatCPF(t_cpf)
						<< setw((tampadrao/2)) << left << "||"
						<< setw((tampadrao/2)) << left << RegistroAstronautas.getE(i)->getIdade()
						<< setw((tampadrao/2)) << left << "||";

					//Se o astronauta estiver vivo, imprime que ele está vivo na coluna "Situação".
					if(t_vivo){
						cout << setw((tampadrao/2)+3) << left << "Vivo(a)"
							 << setw((tampadrao/2)) << left << "||"
							 << endl;
					} else{ //Caso esteja morto (vivo = false), imprime que ele está morto na coluna "Situação".
						cout << setw((tampadrao/2)+3) << left << "Morto(a)"
							 << setw((tampadrao/2)) << right << "||"
							 << endl;
					}
				}
			}
			cout << endl; //Pula linha
		} else if(ans == 3){
			RegistroVoos.addE(addVoo());	
		} else if(ans == 4){
			unsigned int qt_voos = RegistroVoos.getQuant();
	
			cout << "\nVoos:\n" << endl;

			for(int i=0;i<qt_voos;i++){
				cout << "Código do voo " << i+1 << ": "
					 << RegistroVoos.getE(i)->getCode()
					 << endl;
			}

			cout << endl;
		}
	}

    return 0;
}
