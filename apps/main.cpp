#include <iostream> //Biblioteca de entrada e saída (cout e cin).
#include <iomanip> //Formatação do cout.
#include <string> //Biblioteca para manipulação de strings.
#include "reg.hpp" //Modularização dos registros.
#include "format.hpp" //Modularização da formatação de CPF/string.
#include "func.hpp" //Modularização das funções gerais.
#include "astro.hpp" //Modularização da classe Astronauta.
#include "voo.hpp" //Modularização da classe Voo.
#include "trip.hpp" //Modularização da classe Tripulante.
#include "morto.hpp" //Modularização da classe Morto.

using namespace std;

int main(){
	//Criação do vetor de ponteiros de Astronautas.
    Registros<Astronauta*> RegistroAstronautas;
	//Criação do vetor de ponteiros de Voos.
	Registros<Voo*> RegistroVoos;
	//Criação do vetor de ponteiros de Tripulantes.
	Registros<Tripulante*> RegistroTripulantes;
	//Criação do vetor de ponteiros de Mortos.
	Registros<Morto*> RegistroMortos;

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
			 << "7 - Exibir tripulação.\n"
			 << "8 - Lançar um voo.\n"
			 << "9 - Explodir um voo.\n"
			 << "10 - Finalizar um voo.\n"
			 << "11 - Exibir astronautas mortos.\n"
			 << "0 - Sair.\n"
			 << "Comando: ";
		cin >> ans; //Resposta do usuário.
		cout << endl;

		unsigned int qtastro = RegistroAstronautas.getQuant(); //Variável que carrega a quantidade de astronautas no vetor.
												//^^^^^^^^^^^------> Função da classe do vetor que retorna a quantidade de elementos (astronautas).
		unsigned int qt_voos = RegistroVoos.getQuant();
		
		if(ans == 1){
			//Variável do tipo Astronauta* que recebe a função addAstro.
			Astronauta* astro = addAstro(RegistroAstronautas);

			if(astro != NULL){
				//Chama a função addE (adiciona um elemento no vetor) e, como parâmetro, recebe astro.
				RegistroAstronautas.addE(astro);
				cout << endl;
			} else{
				cout << endl;
			}
		} else if(ans == 2){	
			//Caso não haja elementos no vetor (astronautas), imprime uma mensagem de erro.
			if(qtastro == 0){
				cout << "\n----------------------------------------------" << endl;
				cout << "Não há nenhum astronauta cadastrado. Cadastre com o comando 1!" << endl;
				cout << "----------------------------------------------" << endl;
			} else{ //Caso haja elementos no vetor (astronautas).
				cout << "Astronautas:\n" << endl; //Título	

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
			//Variável do tipo Voo* que recebe um voo com todos os dados preenchidos.
			Voo* voo = addVoo(RegistroVoos);
			
			//Condicional para saber se o voo é válido.
			if(voo != NULL){ //Se for válido.
				RegistroVoos.addE(voo); //Adiciona o voo no vetor de voos.
				cout << endl; //Pula linha.
			} else{ //Se não for válido
				cout << endl; //Somente pula a linha.
			}

		} else if(ans == 4){ //Caso o comando seja o 4, Mostra os voos cadastrados no vetor RegistroVoos.
			unsigned int qtvoo = RegistroVoos.getQuant(); //Variável para a quantidade de voos no vetor.	

			if(qtvoo != 0){ //Caso haja voos no vetor.
				cout << "----------------------------------------------" << endl;
				cout << "Voos:" << endl; //Título

				//Loop para imprimir os códigos dos voos.
				for(int i=0;i<qt_voos;i++){
					cout << "----------------------------------------------" << endl;
					cout << "Código do voo " << i+1 << ": "
						 << RegistroVoos.getE(i)->getCode()
						 << endl;
					cout << "Situação do voo: ";

					Voo* voo = RegistroVoos.getE(i);

					//Se o voo foi lançado.
					if(voo->getLanc()){
						cout << "Lançado." << endl; //Imprime que foi lançado.
					} else if(voo->getExplode()){ //Caso tenha explodido.
						cout << "Explodiu." << endl; //Imprime que explodiu.
					} else if(voo->getFin()){ //Caso tenha sido finalizado.
						cout << "Finalizado." << endl; //Imprime que finalizou.
					} else{ //Caso não seja nenhum dos casos.
						cout << "Em planejamento." << endl; //Imprime que está em planejamento.
					}
				}
				cout << "----------------------------------------------" << endl;
			} else{ //Caso não haja, imprime uma mensagem de erro.
				cout << "\n----------------------------------------------" << endl;
				cout << "Não há nenhum voo cadastrado. Cadastre com o comando 3!" << endl;
				cout << "----------------------------------------------" << endl;
			}

			cout << endl; //Pula linha.
		} else if(ans == 5){ //Caso o comando seja o 5, cadastra um tripulante em um determinado voo.
			int temp_code; //Código temporário.
			string temp_cpf; //CPF temporário.

			if(RegistroVoos.getQuant() <= 0){
				cout << "\n----------------------------------------------" << endl;
				cout << "Não há nenhum voo cadastrado. Cadastre com o comando 3!" << endl;
				cout << "----------------------------------------------" << endl;
				cout << endl;
			} else{
				//Coleta o código e armazena na variável temp_code
				cout << "\n----------------------------------------------" << endl;
				cout << "Qual o código do voo que será cadastrado um tripulante?" << endl;
				cin >> temp_code;
				//Cria uma variável do tipo Voo* que recebe o voo de acordo com o código fornecido pelo usuário.
				Voo* temp_voo = getVooByCode(temp_code, RegistroVoos);

				//Se houver um voo com o código fornecido e o voo não foi lançado ainda.
				if(temp_voo != NULL && temp_voo->getLanc() == false && temp_voo->getFin() == false && temp_voo->getExplode() == false){
					LimparBuffer();

					if(RegistroAstronautas.getQuant() <= 0){
						cout << "----------------------------------------------" << endl;
						cout << "Não há nenhum astronauta cadastrado. Cadastre com o comando 1!" << endl;
						cout << "----------------------------------------------" << endl;
					} else{
						//Coleta o CPF e armazena na variável temp_cpf.
						cout << "----------------------------------------------" << endl;
						cout << "Qual o CPF do astronauta que deseja cadastrar?" << endl;
						getline(cin, temp_cpf);

						string conf_cpf = confCPF(temp_cpf); //Bota o cpf na configuração padrão.

						//Cria uma variável do tipo Astronauta* que recebe o astronauta de acordo com o CPF fornecido pelo usuário.
						Astronauta* temp_astro = getAstroByCPF(conf_cpf, RegistroAstronautas);

						//Se houver um astronauta com o CPF fornecido e o astronauta está vivo.
						if(temp_astro != NULL && temp_astro->getVivo()){
							cout << "----------------------------------------------" << endl;

							bool check = true; //Variável para checar.
							unsigned int TQuant = RegistroTripulantes.getQuant(); //Variável da quantidade de tripulantes total.
							//Loop para verificar os tripulantes.
							for(int i=0;i<TQuant;i++){
								string cpf_trip = RegistroTripulantes.getE(i)->getTCPF(); //Variável que recebe o cpf do tripulante i.
								int code_trip = RegistroTripulantes.getE(i)->getTCode(); //Variável que recebe o código do tripulante i.
								//Se código do tripulante for igual ao código fornecido pelo usuário e o cpf do tripulante for igual ao cpf fornecido pelo usuário.
								if(code_trip == temp_code && temp_cpf == cpf_trip){
									//Imprime uma mensagem de erro.
									cout << "O astronauta de CPF " << formatCPF(temp_cpf)
										 << " já está cadastrado no voo." << endl;
									cout << "----------------------------------------------" << endl;
									check = false; //check recebe false.
									break; //Para o loop.
								}
							}

							//Se o check for true.
							if(check){
								//Imprime a mensagem de que tudo deu certo!
								cout << "Astronauta "
									<< temp_astro->getNome()
									<< " foi cadastrado no voo de código "
									<< temp_voo->getCode()
									<< " com sucesso!"
									<< endl;
								//Adiciona o tripulante utilizando o voo e o astronauta adquiridos pela coleta das informações e armazena no vetor de tripulantes.
								RegistroTripulantes.addE(addTripul(temp_voo, temp_astro));
								temp_voo->OneT(); //Incrementa em um a quantidade de tripulantes no voo na qual o tripulante foi cadastrado.
								cout << "----------------------------------------------" << endl;
							}
						} else if(temp_astro == NULL){ //Se não houver astronauta com o CPF fornecido, imprime uma mensagem de erro.
							//Imprime uma mensagem de erro.
							cout << "\n----------------------------------------------" << endl;
							cout << "Não há nenhum astronauta com o CPF fornecido..." << endl;
							cout << "----------------------------------------------" << endl;	
						} else if(temp_astro->getVivo() == false){ //Se o astronauta estiver morto.
							//Imprime uma mensagem de erro.
							cout << "\n----------------------------------------------" << endl;
							cout << "Não há como adicionar um astronauta morto no voo! Mais respeito por favor." << endl;
							cout << "----------------------------------------------" << endl;	
						}
					}
				} else if(temp_voo == NULL){ //Se não houver voo com o código fornecido, imprime uma mensagem de erro.
					//Imprime uma mensagem de erro.
					cout << "\n----------------------------------------------" << endl;
					cout << "Não há nenhum voo com o código fornecido." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(temp_voo->getFin()){ //Caso o voo já tenha sido lançado
					//Imprime uma mensagem de erro.
					cout << "\n----------------------------------------------" << endl;
					cout << "Não tem como adicionar tripulantes em um voo já finalizado." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(temp_voo->getExplode()){ //Caso o voo tenha explodido
					//Imprime uma mensagem de erro.
					cout << "\n----------------------------------------------" << endl;
					cout << "Não tem como adicionar tripulantes em um voo que explodiu..." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(temp_voo->getLanc()){ //Se o voo foi lançado.
					//Imprime uma mensagem de erro.
					cout << "\n----------------------------------------------" << endl;
					cout << "Não tem como adicionar tripulantes em um voo já lançado." << endl;
					cout << "----------------------------------------------" << endl;
				}

				cout << endl; //Pula linha.
			}
		} else if(ans == 6){
			int code; //Variável para armazenar o código do voo.
			string cpf; //Variável para armazenar o CPF do astronauta.

			//Se a quantidade de voos for 0 ou menos.
			if(RegistroVoos.getQuant() <= 0){
				//Imprime uma mensagem de erro.
				cout << "\n----------------------------------------------" << endl;
				cout << "Não há nenhum voo cadastrado. Cadastre com o comando 3!" << endl;
				cout << "----------------------------------------------" << endl;
				cout << endl;
			} else{ //Caso contrário.
				//Coleta o código do voo e armazena na variável code.
				cout << "\n----------------------------------------------" << endl;
				cout << "Qual o código do voo que deseja deletar um tripulante? " << endl;
				cin >> code;
				//Variável do tipo Voo* que recebe o voo de acordo com o código fornecido pelo usuário.
				Voo* voo = getVooByCode(code, RegistroVoos);

				//Se existir um voo com o código fornecido e a quantidade de tripulantes for maior que 0.
				if(voo != NULL && voo->getTQuant() > 0 && voo->getLanc() == false && voo->getFin() == false && voo->getExplode() == false){
					LimparBuffer();
					//Coleta o CPF do astronauta e armazena na variável cpf.
					cout << "----------------------------------------------" << endl;
					cout << "Qual o CPF do astronauta que deseja remover? " << endl;
					getline(cin, cpf);
					cout << "----------------------------------------------" << endl;

					string conf_cpf = confCPF(cpf); //Bota o cpf na configuração padrão.

					//Variável do tipo Astronauta* que recebe o astronauta de acordo com o CPF fornecido pelo usuário.
					Astronauta* astro = getAstroByCPF(conf_cpf, RegistroAstronautas);

					//Se existir um astronauta com o cpf fornecido.
					if(astro != NULL){
						delTripul(voo, astro, RegistroTripulantes); //Chama a função para a deleção do tripulante da tripulação do voo.
						cout << "----------------------------------------------" << endl;
						
						cout << endl; //Pula linha.
					} else{ //Caso não exista um astronauta com o cpf fornecido.
						//Imprime uma mensagem de erro.
						cout << "Não há nenhum astronauta com o CPF fornecido..." << endl;
						cout << "----------------------------------------------" << endl;
					}
				} else if(voo == NULL){ //Caso não haja um voo com o código fornecido.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não há nenhum voo com o código fornecido..." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getTQuant() <= 0){ //Caso o número de tripulantes do voo seja 0 ou menos.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não há nenhum tripulante cadastrado no voo. Cadastre com o comando 5!" << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getFin()){ //Caso o voo já tenha sido finalizado.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não dá para remover um tripulante pois o voo já foi finalizado." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getExplode()){ //Caso o voo tenha explodido.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não dá para remover um tripulante pois o voo explodiu." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getLanc()){ //Caso o voo já tenha sido lançado.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não dá para remover um tripulante pois o voo já foi lançado." << endl;
					cout << "----------------------------------------------" << endl;
				}

				cout << endl;
			}
		} else if(ans == 7){ //Caso o comando seja o 7, mostra os tripulantes cadastrados em um determinado voo.
			int code; //Variável para o código.

			//Se a quantidade de voos for 0 ou menos
			if(RegistroVoos.getQuant() <= 0){
				//Imprime uma mensagem de erro.
				cout << "\n----------------------------------------------" << endl;
				cout << "Não há nenhum voo cadastrado. Cadastre com o comando 3!" << endl;
				cout << "----------------------------------------------" << endl;
				cout << endl;
			} else{ //Caso contrário.
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
				} else if(voo == NULL){ //Caso não exista um voo com o código fornecido.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não há nenhum voo com o código fornecido..." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getTQuant() <= 0){ //Caso a quatidade de tripulantes do voo seja 0 ou menos.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não há nenhum tripulante cadastrado no voo..." << endl;
					cout << "----------------------------------------------" << endl;
				}
			}
		} else if(ans == 8){ //Caso o comando seja o 8, lança um voo.
			int code; //Variável para o código.

			//Se a quantidade de voos for 0 ou menos.
			if(RegistroVoos.getQuant() <= 0){
				//Imprime uma mensagem de erro.
				cout << "\n----------------------------------------------" << endl;
				cout << "Não há nenhum voo cadastrado. Cadastre com o comando 3!" << endl;
				cout << "----------------------------------------------" << endl;
				cout << endl;
			} else{ //Caso contrário.
				//Coleta o código do voo e armazena na variável code.
				cout << "\n----------------------------------------------" << endl;
				cout << "Qual o código do voo que deseja lançar?" << endl;
				cin >> code;
				//Variável do tipo Voo* que recebe o voo de acordo com o CPF fornecido pelo usuário.
				Voo* voo = getVooByCode(code, RegistroVoos);

				//Se houver um voo com o código fornecido e a quantidade de tripulantes do voo for maior que 0.
				if(voo != NULL && voo->getTQuant() > 0 && voo->getLanc() == false && voo->getFin() == false && voo->getExplode() == false){
					unsigned int TQuant = RegistroTripulantes.getQuant(); //Variável que armazena a quantidade de tripulantes no total.
					bool check = true;
					bool check_vivo = true;

					//Loop para verificar cada tripulante.
					for(int i=0;i<TQuant;i++){
						Tripulante* trip = RegistroTripulantes.getE(i); //Variável do tipo Tripulante* que recebe o elemento i.
						int TCode = trip->getTCode(); //Variável que recebe o código do tripulante.
						string Tcpf = trip->getTCPF(); //Variável que recebe o cpf do tripulante.
						Astronauta* astro = getAstroByCPF(Tcpf, RegistroAstronautas); //Variável do tipo Astronauta* que recebe o astronauta de acordo com o CPF do tripulante.

						//Se o código do voo for igual ao código do tripulante e o astronauta estiver ocupado.
						if(voo->getCode() == TCode && astro->getOcup()){
							check = false; //check recebe falso.
							break; //Para o loop.
						} else if(voo->getCode() == TCode && astro->getVivo() == false){
							check_vivo = false;
							break;
						}
					}

					//Se check for falso.
					if(check == false){
						//Impressão dos dados do astronauta ocupado.
						cout << "----------------------------------------------" << endl;
						cout << "Os seguintes astronautas já estão em um voo:"<< endl;

						//Loop para imprimir os dados do astronauta ocupado.
						for(int i=0;i<TQuant;i++){
							Tripulante* trip = RegistroTripulantes.getE(i); //Variável do tipo Tripulante* que recebe o elemento i.
							int TCode = trip->getTCode(); //Variável que recebe o código do tripulante.
							string Tcpf = trip->getTCPF(); //Variável que recebe o cpf do tripulante.
							Astronauta* astro = getAstroByCPF(Tcpf, RegistroAstronautas); //Variável do tipo Astronauta* que recebe o astronauta de acordo com o CPF do tripulante.

							//Se o código do voo for igual ao código do tripulante e o astronauta estiver ocupado.
							if(voo->getCode() == TCode && astro->getOcup()){
								//Imprime os dados do astronauta.
								cout << "Astronauta " << astro->getNome()
									 << " de CPF: " << formatCPF(astro->getCPF())
									 << endl;
								cout << "Cadastrado no(s) voo(s): " << endl;
								//Loop para imprimir os voos na qual o astronauta ocupado pertence.
								for(int j=0;j<TQuant;j++){
									Tripulante* trip2 = RegistroTripulantes.getE(j); //Variável do tipo Tripulante* que recebe o elemento j.
									string Tcpf2 = trip2->getTCPF(); //Variável que recebe o código do tripulante (trip2).

									//Se o cpf do astronauta for igual ao cpf do trip2 e o código do trip2 for diferente do código do voo do tripulante 1.
									if(astro->getCPF() == trip2->getTCPF() && trip2->getTCode() != TCode){
										cout << "Voo " << trip2->getTCode() << endl; //Impressão do dado do voo.
									}
								}
							}
						}

						//Recomendação para o usuário.
						cout << "Espere o voo finalizar para que o(s) astronauta(s) esteja(m) livre(s)!" << endl;
						cout << "----------------------------------------------" << endl;

					} else if(check_vivo == false){
						cout << "----------------------------------------------" << endl;
						cout << "Não tem como lançar um voo com astronautas mortos nele. Verifique com o comando 7 e apague com o comando 6!" << endl;
						cout << "----------------------------------------------" << endl;
					} else{
						cout << "----------------------------------------------" << endl;
						voo->setLanc(true); //Chama o setter da classe voo para setar o lançamento como true.
						voo->setExplode(false); //Chama o setter da classe voo para setar o explode como false.
						voo->setFin(false); //Chama o setter da classe voo para setar o finalizado como false.
						//Imprime mensagem de sucesso.
						cout << "O voo " << code << " foi lançado! Boa sorte para a tripulação!" << endl;
						cout << "----------------------------------------------" << endl;

						//Loop para setar os tripulantes como "ocupados".
						for(int i=0;i<TQuant;i++){
							Tripulante* trip = RegistroTripulantes.getE(i);
							if(trip->getTCode() == code){
								string trip_cpf = trip->getTCPF();
								Astronauta* astro = getAstroByCPF(trip_cpf, RegistroAstronautas);

								astro->setOcup(true);
							}
						}
					}

				} else if(voo == NULL){ //Caso não haja voo com o código fornecido pelo usuário.
					//Imprime mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não há nenhum voo com o código fornecido..." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getTQuant() <= 0){ //Caso a quantidade de tripulantes do voo seja 0 ou menos.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não tem como lançar sem tripulantes. Cadastre um com o comando 5!" << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getFin()){ //Caso o voo já tenha finalizado.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não tem como lançar um voo que já foi finalizado." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getExplode()){ //Caso o voo tenha explodido.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não tem como lançar um voo que explodiu." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getLanc()){ //Caso o voo já tenha sido lançado.
					//Imprime uma mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não tem como lançar um voo que já foi lançado." << endl;
					cout << "----------------------------------------------" << endl;
				}

				cout << endl; //Pula linha.
			}
		} else if(ans == 9){
			int code;

			if(RegistroVoos.getQuant() <= 0){
				cout << "\n----------------------------------------------" << endl;
				cout << "Não há nenhum voo cadastrado. Cadastre com o comando 3!" << endl;
				cout << "----------------------------------------------" << endl;
				cout << endl;
			} else{
				cout << "\n----------------------------------------------" << endl;
				cout << "Qual o código do voo que deseja EXPLODIR?" << endl;
				cin >> code;

				Voo* voo = getVooByCode(code, RegistroVoos);

				if(voo != NULL && voo->getLanc() && voo->getExplode() == false && voo->getFin() == false){
					cout << "----------------------------------------------" << endl;
					explodeVoo(voo, RegistroTripulantes, RegistroAstronautas, RegistroMortos);
					limpezaGeral(RegistroVoos, RegistroAstronautas, RegistroTripulantes);

				} else if(voo == NULL){ //Caso não tenha nenhum voo com o código fornecido.
					//Imprime mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não há nenhum voo com o código fornecido..." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getExplode()){ //Caso o voo já tenha explodido.
					//Imprime mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não tem como explodir um voo que já explodiu." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getFin()){ //Caso o voo já tenha finalizado.
					//Imprime mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não tem como explodir um voo que já foi finalizado." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getLanc() == false){ //Caso o voo ainda não tenha sido lançado.
					//Imprime mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não tem como explodir um voo que ainda não foi lançado." << endl;
					cout << "----------------------------------------------" << endl;
				}

				cout << endl;
			}
		} else if(ans == 10){
			int code;

			if(RegistroVoos.getQuant() <= 0){
				cout << "\n----------------------------------------------" << endl;
				cout << "Não há nenhum voo cadastrado. Cadastre com o comando 3!" << endl;
				cout << "----------------------------------------------" << endl;
				cout << endl;
			} else{
				cout << "\n----------------------------------------------" << endl;
				cout << "Qual o código do voo que deseja finalizar?" << endl;
				cin >> code;

				Voo* voo = getVooByCode(code, RegistroVoos);

				if(voo != NULL && voo->getLanc() && voo->getExplode() == false && voo->getFin() == false){
					cout << "----------------------------------------------" << endl;
					finalVoo(voo, RegistroTripulantes, RegistroAstronautas);
					cout << "----------------------------------------------" << endl;
				} else if(voo == NULL){ //Caso não tenha nenhum voo com o código fornecido.
					//Imprime mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não há nenhum voo com o código fornecido..." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getExplode()){ //Caso o voo já tenha explodido.
					//Imprime mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não tem como finalizar um voo que explodiu." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getFin()){ //Caso o voo já tenha finalizado.
					//Imprime mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não tem como finalizar um voo que já foi finalizado." << endl;
					cout << "----------------------------------------------" << endl;
				} else if(voo->getLanc() == false){ //Caso o voo ainda não tenha sido lançado.
					//Imprime mensagem de erro.
					cout << "----------------------------------------------" << endl;
					cout << "Não tem como finalizar um voo que ainda não foi lançado." << endl;
					cout << "----------------------------------------------" << endl;
				}

				cout << endl;
			}
		} else if(ans == 11){
			if(RegistroMortos.getQuant() <= 0){
				cout << "\n----------------------------------------------" << endl;	
				cout << "Não há mortos." << endl;
				cout << "----------------------------------------------" << endl;
			} else{
				showMortos(RegistroMortos, RegistroTripulantes, RegistroVoos);
			}

			cout << endl;
		} 
	}

    return 0;
}
