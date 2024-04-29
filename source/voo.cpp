#include "reg.hpp"
#include "voo.hpp"
#include <iostream>
using namespace std;

//Construtor
Voo::Voo(int codigo){
	this->codigo = codigo; //codigo da classe recebe codigo (parâmetro).
	this->Tquant = 0; //Quantidade de tripulantes recebe 0.
	this->lanc = false; //Variável lanc começa recebendo false.
	this->explode = false; //Variável explode começa recebendo false.
	this->finalizado = false; //Variável finalizado começa recebendo false.
}

//Função que retorna o código do voo.
int Voo::getCode(){
	return this->codigo;
}

//Função que retorna a quantidade de tripulantes cadastrados no voo.
unsigned int Voo::getTQuant(){
	return this->Tquant;
}

//Função que retorna se o voo foi lançado ou não.
bool Voo::getLanc(){
	return this->lanc;
}

//Função que retorna se o voo explodiu ou não.
bool Voo::getExplode(){
	return this->explode;
}

//Função que retorna se o voo foi finalizado ou não.
bool Voo::getFin(){
	return this->finalizado;
}

//Função para incrementar em um a quantidade de tripulantes.
void Voo::OneT(){
	Tquant++;
}

//Função para decrementar em um a quantidade de tripulantes.
void Voo::MOneT(){
	Tquant--;
}

//Setter para a variável lanc da classe (True - Foi lançado / False - Não foi lançado).
void Voo::setLanc(bool ToF){
	this->lanc = ToF;
}

//Setter para a variável explode da classe (True - Explodiu / False - Não explodiu).
void Voo::setExplode(bool ToF){
	this->explode = ToF;
}

//Setter para a variável finalizade da classe (True - Foi finalizado / False - Não foi finalizado).
void Voo::setFin(bool ToF){
	this->finalizado = ToF;
}

//Função que acha um voo pelo código.
Voo* getVooByCode(int code, Registros<Voo*> &RegVoos){
	unsigned int qtvoo = RegVoos.getQuant(); //Variável que recebe a quantidade de voos do vetor RegVoos (parâmetro).

	//Loop para comparar os cpfs de cada astronauta do vetor para ver qual é igual.
	for(int i=0;i<qtvoo;i++){
		int t_code = RegVoos.getE(i)->getCode();
		if(t_code == code){
			return RegVoos.getE(i); //Retorna o voo.
		}
	}

	return NULL; //Retorna Vazio.
}

//Função que retorna um voo com todos os dados preenchidos.
Voo* addVoo(Registros<Voo*> &RegVoo){
	int code_voo; //Variável para o código do voo.

	cout << "-----------------------------------" << endl;
	//Coleta do código do voo.
	cout << "Qual o código do voo?" << endl;
	cin >> code_voo;
	cout << "-----------------------------------" << endl;

	if(getVooByCode(code_voo, RegVoo) != NULL){
		cout << "Já há um voo com o código fornecido. Tente um novo!" << endl;
		cout << "-----------------------------------" << endl;
		return NULL;
	} else{
		//novo voo do tipo Voo* é criado (ponteiro).
		Voo* voo = new Voo(code_voo);
		return voo; //retorna voo,
	}
}
