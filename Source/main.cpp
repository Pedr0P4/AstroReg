#include <iostream> //Biblioteca de entrada e saída (cout e cin).
#include <iomanip> //Formatação do cout.
#include <limits> //Para a função de limpar o buffer.
#include <string> //Biblioteca para manipulação de strings.

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

            delete[] this->elements; //Deleta o ponteiro dos elementos da classe.
            this->elements = novoArray; //Os elementos da classe agora recebem o novo array com o novo elemento e os anteriores.

            this->quant++; //Quantidade de elementos é incrementado em 1.
        }

		void delE(T elem){
			T* novoArray = new T[quant-1];
			unsigned int j = 0;

			for(int i=0;i<this->quant;i++){
				if(elem != elements[i]){
					novoArray[j++] = this->elements[i];
				}
			}

			delete[] this->elements;
			this->elements = novoArray;

			this->quant--;
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
    	Astronauta(int idade, string cpf, string nome){
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

//Classe com as informações de um voo.
class Voo{
	private:
		int codigo; //Código do voo
		unsigned int Tquant; //Quantidade de tripulantes cadastrados.

	public:
		//Construtor
		Voo(int codigo){
			this->codigo = codigo; //codigo da classe recebe codigo (parâmetro).
			this->Tquant = 0; //Quantidade de tripulantes recebe 0.
		}

		//Função que retorna o código do voo.
		int getCode(){
			return this->codigo;
		}

		//Função que retorna a quantidade de tripulantes cadastrados no voo.
		unsigned int getTQuant(){
			return this->Tquant;
		}

		//Função para incrementar em um a quantidade de tripulantes.
		void OneT(){
			Tquant++;
		}
};

//Classe com as informações de um tripulante
class Tripulante{
	private:
		int codigo; //Código do voo que o tripulante pertence.
		int idade; //Idade do tripulante.
		string nome; //Nome do tripulante.
		string cpf; //CPF do tripulante.

	public:
		//Contrutor.
		Tripulante(int codigo, int idade, string nome, string cpf){
			this->codigo = codigo; //Código da classe recebe codigo (parâmetro).
			this->idade = idade; //Idade da classe recebe idade (parâmetro).
			this->nome = nome; //Nome da classe recebe nome (parâmetro).
			this->cpf = cpf; //CPF da classe recebe cpf (parâmetro).
		}

		//Função para retornar o código do tripulante.
		int getTCode(){
			return this->codigo;
		}

		//Função para retornar o nome do tripulante.
		string getTNome(){
			return this->nome;
		}

		//Função para retornar a idade do tripulante.
		int getTIdade(){
			return this->idade;
		}

		//Função para retornar o CPF do tripulante.
		string getTCPF(){
			return this->cpf;
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

//Função que limpa o buffer.
void LimparBuffer(){
	//Limpar o buffer.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

Astronauta* addAstro(){
	string nome; //Variável para receber o nome do astronauta.
	string cpf; //Variável para receber o CPF do astronauta.
	int idade; // Variável para receber a idade do astronauta.

	LimparBuffer(); //Limpa o buffer.

	cout << "-----------------------------------" << endl;
	//Coleta do nome do astronauta.
	cout << "Qual o nome do astronauta?" << endl;
	getline(cin, nome);
	cout << "-----------------------------------" << endl;

	//Coleta do CPF do astronauta.
	cout << "Qual o CPF de " << nome << "?" << endl;
	getline(cin, cpf);
	cout << "-----------------------------------" << endl;

	//Coleta da idade do astronauta.
	cout << "Qual a idade de " << nome << "?" << endl;
	cin >> idade;
	cout << "-----------------------------------" << endl;

	//Ponteiro para criar um astronauta com os valores fornecidos pelo usuário.
	Astronauta* astro = new Astronauta(idade, cpf, nome);
	return astro; //Retorna o ponteiro.
}

//Função que pega o astronauta pelo CPF.
Astronauta* getAstroByCPF(string cpf, Registros<Astronauta*> &RegAst){
	unsigned int qtastro = RegAst.getQuant(); //Variável que recebe a quantidade de astronautas do vetor RegAst (parâmetro).

	//Loop para comparar os cpfs de cada astronauta do vetor para ver qual é igual.
	for(int i=0;i<qtastro;i++){
		string t_cpf = RegAst.getE(i)->getCPF();
		if(cpf == t_cpf){
			return RegAst.getE(i); //Retorna o astronauta.
		}
	}

	cout << "Não há um astronauta com o CPF fornecido!" << endl; //Mensagem de erro
	return NULL; //Retorna Vazio.
}

//Função que adiciona um voo no vetor de voos;
Voo* addVoo(){
	int code_voo; //Variável para o código do voo.

	cout << "-----------------------------------" << endl;
	//Coleta do código do voo.
	cout << "Qual o código do voo?" << endl;
	cin >> code_voo;
	cout << "-----------------------------------" << endl;

	//novo voo do tipo Voo* é criado (ponteiro).
	Voo* voo = new Voo(code_voo);
	return voo; //retorna voo,
}

//Função que retorna um voo com todas os dados preenchidos.
Voo* getVooByCode(int code, Registros<Voo*> &RegVoos){
	unsigned int qtvoo = RegVoos.getQuant(); //Variável que recebe a quantidade de voos do vetor RegVoos (parâmetro).

	//Loop para comparar os cpfs de cada astronauta do vetor para ver qual é igual.
	for(int i=0;i<qtvoo;i++){
		int t_code = RegVoos.getE(i)->getCode();
		if(t_code == code){
			return RegVoos.getE(i); //Retorna o voo.
		}
	}

	cout << "Não há um voo com o código fornecido!" << endl; //Mensagem de erro.
	return NULL; //Retorna Vazio.
}

//Função que retorna um tripulante com todos os dados preenchidos.
Tripulante* addTripul(Voo* voo, Astronauta* astronauta){
	int code_t = voo->getCode(); //Código do voo fornecido pelo usuário.
	int idade_t = astronauta->getIdade(); //Idade do astronauta fornecido pelo usuário.
	string nome_t = astronauta->getNome(); //Nome do astronauta fornecido pelo usuário.
	string cpf_t = astronauta->getCPF(); //CPF do astronauta fornecido pelo usuário.

	//Cria um tripulante com as variáveis do início da função.
	Tripulante* tripul = new Tripulante(code_t, idade_t, nome_t, cpf_t);
	return tripul; //Retorna esse tripulante.
}

//Função para imprimir na tela os tripulantes de um voo.
void showTripul(Voo* voo, Registros<Tripulante*> &RegTripul){
	unsigned int TQuant = voo->getTQuant(); //Variável que recebe a quantidade de tripulantes cadastrados em um voo.
	int voo_code = voo->getCode(); //Variável que recebe o código do voo.

	//Loop para imprimir os tripulantes.
	for(int i=0;i<TQuant;i++){
		int TripCode = RegTripul.getE(i)->getTCode();
		if(TripCode == voo_code){
			cout << "----------------------------------------------" << endl;
			Tripulante* tripulante = RegTripul.getE(i);
			cout << "Tripulante " << i << ":\n" << endl;
			cout << "Nome: " << tripulante->getTNome() << endl;
			cout << "Idade: " << tripulante->getTIdade() << endl;
			cout << "CPF: " << tripulante->getTCPF() << endl;
		}
	}
	cout << "----------------------------------------------" << endl;
	cout << endl; //Pula linha.
}

int main(){
	//Criação do vetor de ponteiros de Astronautas.
    Registros<Astronauta*> RegistroAstronautas;
	//Criação do vetor de ponteiros de Voos.
	Registros<Voo*> RegistroVoos;
	Registros<Tripulante*> RegistroTripulantes;

	int ans = -1; //Variável para as escolhas do usuário.

	//Loop while para fazer o programa funcionar enquanto o usuário não quiser sair.
	while(ans != 0){
		//Impressão na tela para o "cardápio" de comandos.
		cout << "Escolha uma das opções:" << endl;
		cout << "1 - Cadastrar astronauta.\n"
			 << "2 - Exibir astronautas.\n"
			 << "3 - Cadastrar voo.\n"
			 << "4 - Exibir voos.\n"
			 << "5 - Cadastrar tripulante.\n"
			 << "6 - Apagar tripulante.\n"
			 << "7 - Exibir tripulantes cadastrados.\n"
			 << "0 - Sair.\n"
			 << "Comando: ";
		cin >> ans; //Resposta do usuário.
		cout << endl;

		unsigned int qtastro = RegistroAstronautas.getQuant(); //Variável que carrega a quantidade de astronautas no vetor.
												//^^^^^^^^^^^------> Função da classe do vetor que retorna a quantidade de elementos (astronautas).
		unsigned int qt_voos = RegistroVoos.getQuant();
		
		if(ans == 1){
			//Chama a função addE (adiciona um elemento no vetor) e, como parâmetro, recebe a função addAstro (cria um ponteiro de Astronauta).
			RegistroAstronautas.addE(addAstro());
			cout << endl;
		} else if(ans == 2){
			cout << "Astronautas:\n" << endl;

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
		} else if(ans == 3){ //Caso o comando seja o 3, adiciona um voo no vetor RegistroVoos.
			RegistroVoos.addE(addVoo());
			cout << endl;
		} else if(ans == 4){ //Caso o comando seja o 4, Mostra os voos cadastrados no vetor RegistroVoos.
			unsigned int qtvoo = RegistroVoos.getQuant(); //Variável para a quantidade de voos no vetor.

			cout << "Voos:\n" << endl; //Título

			if(qtvoo != 0){ //Caso haja voos no vetor.
				//Loop para imprimir os códigos dos voos.
				for(int i=0;i<qt_voos;i++){
					cout << "Código do voo " << i+1 << ": "
						<< RegistroVoos.getE(i)->getCode()
						<< endl;
				}
			} else{ //Caso não haja, imprime uma mensagem de erro.
				cout << "Não há voos cadastrados!" << endl;
			}

			cout << endl; //Pula linha.
		} else if(ans == 5){ //Caso o comando seja o 5, cadastra um tripulante em um determinado voo.
			int temp_code; //Código temporário.
			string temp_cpf; //CPF temporário.

			//Coleta o código e armazena na variável temp_code
			cout << "\n----------------------------------------------" << endl;
			cout << "Qual o código do voo que será cadastrado um tripulante?" << endl;
			cin >> temp_code;
			//Cria uma variável do tipo Voo* que recebe o voo de acordo com o código fornecido pelo usuário.
			Voo* temp_voo = getVooByCode(temp_code, RegistroVoos);

			//Se houver um voo com o código fornecido.
			if(temp_voo != NULL){
				LimparBuffer();

				//Coleta o CPF e armazena na variável temp_cpf.
				cout << "----------------------------------------------" << endl;
				cout << "Qual o CPF do astronauta que deseja cadastrar?" << endl;
				getline(cin, temp_cpf);
				//Cria uma variável do tipo Astronauta* que recebe o astronauta de acordo com o CPF fornecido pelo usuário.
				Astronauta* temp_astro = getAstroByCPF(temp_cpf, RegistroAstronautas);

				//Se houver um astronauta com o CPF fornecido.
				if(temp_astro != NULL){
					//Imprime a mensagem de que tudo deu certo!
					cout << "Astronauta "
						 << temp_astro->getNome()
						 << " foi cadastrado no voo de código "
						 << temp_voo->getCode()
						 << "."
						 << endl;

					cout << "----------------------------------------------" << endl;
					//Adiciona o tripulante utilizando o voo e o astronauta adquiridos pela coleta das informações e armazena no vetor de tripulantes.
					RegistroTripulantes.addE(addTripul(temp_voo, temp_astro));
					temp_voo->OneT(); //Incrementa em um a quantidade de tripulantes no voo na qual o tripulante foi cadastrado.
					cout << "----------------------------------------------" << endl;
				} else{ //Se não houver astronauta com o CPF fornecido, imprime uma mensagem de erro.
					cout << "\n----------------------------------------------" << endl;
					cout << "Não há nenhum astronauta com o CPF fornecido." << endl;
					cout << "----------------------------------------------" << endl;	
				}
			} else{ //Se não houver voo com o código fornecido, imprime uma mensagem de erro.
				cout << "\n----------------------------------------------" << endl;
				cout << "Não há nenhum voo com o código fornecido." << endl;
				cout << "----------------------------------------------" << endl;
			}

			cout << endl; //Pula linha.
		} else if(ans == 6){
			int code; 
			string cpf;

			cout << "\n----------------------------------------------" << endl;
			cout << "Qual o código do voo que deseja deletar um tripulante? " << endl;
			cin >> code;

			cout << "----------------------------------------------" << endl;
			cout << "Qual o CPF do astronauta que deseja remover? " << endl;
			cin >> cpf;
			cout << "----------------------------------------------" << endl;

			//delTripulante(code, cpf, RegistroVoos, RegistroAstronautas);
			
			cout << endl;
		} else if(ans == 7){ //Caso o comando seja o 7, mostra os tripulantes cadastrados em um determinado voo.
			int code; //Variável para o código.

			//Coleta o código e armazena na variável code.
			cout << "\n----------------------------------------------" << endl;
			cout << "Qual o código do voo que deseja ver seus tripulantes?" << endl;
			cin >> code;
			//Cria uma variável do tipo Voo* que recebe um voo de acordo com o código fornecido pelo usuário.
			Voo* voo = getVooByCode(code, RegistroVoos);	

			//Se houver um voo com o código fornecido e a quantidade de tripulantes desse voo for maior que 0.
			if(voo != NULL && voo->getTQuant() > 0){
				//Chama a função para mostrar os tripulantes.
				showTripul(voo, RegistroTripulantes);	
			}
		}
	}

    return 0;
}
