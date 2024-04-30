#include "reg.hpp"
#include "format.hpp"
#include "voo.hpp"
#include "astro.hpp"
#include "trip.hpp"
#include "morto.hpp"
#include <iostream>
#include <string>
using namespace std;

//Função para imprimir na tela os tripulantes de um voo.
void showTripul(Voo* voo, Registros<Tripulante*> &RegTripul){
	unsigned int TQuant = RegTripul.getQuant(); //Variável que recebe a quantidade de tripulantes cadastrados em um voo.
	int voo_code = voo->getCode(); //Variável que recebe o código do voo.
	int j = 0;

	cout << "----------------------------------------------" << endl; //Linha de separação.
	cout << "Quantidade de tripulantes no voo: " << voo->getTQuant() << endl; //Impressão da quantidade de tripulantes.

	//Loop para imprimir os tripulantes.
	for(int i=0;i<TQuant;i++){
		int TripCode = RegTripul.getE(i)->getTCode(); //Pega o código do tripulante.
		if(TripCode == voo_code){ //Se o código do tripulante for igual ao código do voo fornecido pelo usuário
			cout << "----------------------------------------------" << endl; //Linha de separação.
			//Variável do tipo Tripulante* que recebe o tripulante de código igual ao do voo fornecido pelo usuário.
			Tripulante* tripulante = RegTripul.getE(i);
			//Impressão dos dados do tripulante.
			cout << "Tripulante " << ++j << ":\n" << endl;
			cout << "Nome: " << tripulante->getTNome() << "." << endl;
			cout << "CPF: " << formatCPF(tripulante->getTCPF()) << "." << endl;
			cout << "Idade: " << tripulante->getTIdade() << "." << endl;
			cout << "Situação: ";
			if(tripulante->getTVivo()){ //Se o tripulante estiver vivo.
				cout << "Vivo(a)." << endl; //Imprime que ele está vivo.
			} else{ //Caso não esteja vivo.
				cout << "Morto(a)." << endl; //Imprime que ele está morto.
			}
		}
	}
	cout << "----------------------------------------------" << endl; //Linha de separação.
	cout << endl; //Pula linha.
}

//Função para a deleção de um tripulante de um voo.
void delTripul(Voo* voo, Astronauta* astro, Registros<Tripulante*> &RegTrip){
	int code_voo = voo->getCode(); //Variável que armazena o código do voo fornecido.
	string cpf_astro = astro->getCPF(); //Variável que armazena o cpf do astronauta fornecido.
	unsigned int TQuant = RegTrip.getQuant(); //Variável que armazena a quantidade de tripulantes no vetor de tripulantes.
	
	//Loop para verificar se o código do voo e o cpf do astronauta batem com o código do tripulante e o cpf do mesmo.
	for(int i=0;i<TQuant;i++){
		int code_trip = RegTrip.getE(i)->getTCode();
		string cpf_trip = RegTrip.getE(i)->getTCPF();

		if(code_trip == code_voo && cpf_trip == cpf_astro){ //Se achar
			//Variável do tipo Tripulante* que recebe o elemento que possui o código igual ao do voo fornecido e o cpf igual ao do astronauta fornecido.
			Tripulante* del_trip = RegTrip.getE(i);
			//Imprime mensagem de sucesso.
			cout << "O tripulante " << del_trip->getTNome() 
				 << " cadastrado no voo " << del_trip->getTCode() 
				 << " foi removido da tripulação com sucesso!"
				 << endl;
			//Função do vetor para remover um elemento.
			RegTrip.delE(del_trip);
			voo->MOneT(); //Decrementa a quantidade de tripulantes do voo.
			return; //retorna
		}
	}

	//Mensagem de erro, caso saia do loop ao invés de retornar antes do loop finalizar.
	cout << "Não há nenhum tripulante nesse voo com o cpf fornecido..." << endl;
}

//Função para fazer a limpa.
void limpezaGeral(Registros<Voo*> &RegVoos, Registros<Astronauta*> &RegAstro, Registros<Tripulante*> &RegTrip){
	unsigned int AQuant = RegAstro.getQuant(); //Variável que recebe a quantidade de astronautas.
	unsigned int TQuant = RegTrip.getQuant(); //Variável que recebe a quantidade de tripulantes.

	//Loop para fazer as trocas e checagens
	for(int i=0;i<AQuant;i++){
		Astronauta* astro = RegAstro.getE(i); //Variável do tipo Astronauta* que recebe o elemento i.
		//Se astronauta não estiver vivo.
		if(astro->getVivo() == false){
			//Loop para fazer as trocas.
			for(int j=0;j<TQuant;j++){
				Tripulante* trip = RegTrip.getE(j); //Variável do tipo Tripulante* que recebe o elemento j.
				//Se o cpf do tripulante for igual ao cpf do astronauta.
				if(trip->getTCPF() == astro->getCPF()){
					trip->setVivo(false); //Chama o setter da variável vivo da classe tripulante para false.
				}
			}
		}
	}
}

//Função para explodir um voo.
void explodeVoo(Voo* voo, Registros<Tripulante*> &RegTrip, Registros<Astronauta*> &RegAst, Registros<Morto*> &RegMortos){
	voo->setExplode(true); //Chama o setter da variável explode da classe voo e setta para true.
	voo->setFin(false); //Chama o setter da variável fin da classe voo e setta para false.
	voo->setLanc(false); //Chama o setter da variável lanc da classe voo e setta para false.
	//Impressão do título.
	cout << "O voo " << voo->getCode() << " sofreu um acidente e acabou explodindo!" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Tripulação: " << endl;

	unsigned int TQuant = RegTrip.getQuant(); //Variável que recebe a quantidade de tripulantes.
	//Loop para fazer as coletas.
	for(int i=0;i<TQuant;i++){
		Tripulante* trip = RegTrip.getE(i); //Variável do tipo Tripulante* que recebe o elemento i.
		int code_trip = trip->getTCode(); //Variável que recebe o código do tripulante atual.
		string cpf_trip = trip->getTCPF(); //Variável que recebe o CPF do tripulante atual.

		//Se o código do voo for igual ao código do tripulante
		if(voo->getCode() == code_trip){
			Astronauta* astro = getAstroByCPF(cpf_trip, RegAst); //Variável do tipo Astronauta* que recebe o astronauta de acordo com o CPF do tripulante.
			astro->setVivo(false); //Chama o setter da variável vivo da classe astronauta e setta para false.
			astro->setOcup(false); //Chama o setter da variável ocup da classe astronauta e setta para false.
			Morto* morto = addMorto(astro); //Variável do tipo Morto* que recebe um morto com todos os dados preenchidos.
			RegMortos.addE(morto); //Adiciona o morto criado anteriormente no registro de mortos.

			//Imprime o CPF do astronauta que tava no voo.
			cout << "Astronauta: " << trip->getTNome()
				 << " [ " << formatCPF(trip->getTCPF())
				 << " ]." << endl;
		}
	}

	//Mensagem de conforto.
	cout << "----------------------------------------------" << endl;
	cout << "Nossos sentimentos à todos os entes queridos da tripulação..." << endl;
	cout << "----------------------------------------------" << endl;
}

//Função para finalizar um voo.
void finalVoo(Voo* voo, Registros<Tripulante*> &RegTrip, Registros<Astronauta*> &RegAst){
	voo->setFin(true); //Chama o setter da variável fin da classe voo e setta para true.
	voo->setLanc(false); //Chama o setter da variável lanc da classe voo e setta para false.
	voo->setExplode(false); //Chama o setter da variável explode da classe voo e setta para false.

	//Mensagem de sucesso.
	cout << "A tripulação está de volta! O voo " << voo->getCode() << " foi um sucesso!" << endl;

	//Variável que recebe a quantidade de tripulantes.
	unsigned int TQuant = RegTrip.getQuant(); 

	//Loop para fazer as alterações.
	for(int i=0;i<TQuant;i++){
		Tripulante* trip = RegTrip.getE(i); //Variável do tipo Tripulante* que recebe o elemento i.

		//Se o código do voo for igual ao código do tripulante.
		if(voo->getCode() == trip->getTCode()){
			string cpf_trip = trip->getTCPF(); //Variável que recebe o CPF do tripulante.
			Astronauta* astro = getAstroByCPF(cpf_trip, RegAst); //Variável do tipo Astronauta* que recebe um astronauta de acordo com o cpf do tripulante.
			astro->setOcup(false); //Chama o setter da variável ocup da classe astronauta do astronauta coletado anteriormente e setta para false.
		}
	}
}

//Função para mostrar os mortos.
void showMortos(Registros<Morto*> &RegMortos, Registros<Tripulante*> &RegTrip, Registros<Voo*> &RegVoos){
	unsigned int MQuant = RegMortos.getQuant(); //Variável que recebe a quantidade de mortos.
	unsigned int TQuant = RegTrip.getQuant(); //Variável que recebe a quantidade de tripulantes.

	//Título.
	cout << "EM MEMÓRIA DAQUELES QUE JÁ FORAM:" << endl;
	cout << "----------------------------------------------" << endl;

	//Loop para impressão de informações.
	for(int i=0;i<MQuant;i++){
		Morto* morto = RegMortos.getE(i); //Variável do tipo Morto* que recebe o elemento i do registro.
		//Impressão das informações do finado.
		cout << "Nome: " << morto->getMNome() << endl;
		cout << "CPF: " << formatCPF(morto->getMCPF()) << endl;
		cout << "Idade: " << morto->getMIdade() << endl;
		cout << "Voos que participou:" << endl;
		
		//Loop para imprimir os voos que o finado participou.
		for(int j=0;j<TQuant;j++){
			Tripulante* trip = RegTrip.getE(j); //Variável do tipo Tripulante* que recebe o elemento j do registro.
			Voo* voo = getVooByCode(trip->getTCode(), RegVoos); //Variável do tipo Voo* que recebe o voo de acordo com o código do tripulante.
			//Se as condições forem satisfeitas.
			if(trip->getTCPF() == morto->getMCPF() && voo->getLanc() == false && (voo->getFin() || voo->getExplode())){
				cout << "- Voo " << voo->getCode() << endl; //Lista os voos.
			}
		}
		cout << "----------------------------------------------" << endl; //Linha de separação.
	}
}
