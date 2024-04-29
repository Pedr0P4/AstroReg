#include "trip.hpp"
#include "astro.hpp"
#include "voo.hpp"
#include <string>
using namespace std;

//Contrutor.
Tripulante::Tripulante(int codigo, int idade, string nome, string cpf, bool VoM){
	this->codigo = codigo; //Código da classe recebe codigo (parâmetro).
	this->idade = idade; //Idade da classe recebe idade (parâmetro).
	this->nome = nome; //Nome da classe recebe nome (parâmetro).
	this->cpf = cpf; //CPF da classe recebe cpf (parâmetro).
	this->vivo = VoM; //vivo da classe recebe VoM (parâmetro), true para vivo e false para morto.
}

//Função para retornar o código do tripulante.
int Tripulante::getTCode(){
	return this->codigo;
}

//Função para retornar o nome do tripulante.
string Tripulante::getTNome(){
	return this->nome;
}

//Função para retornar a idade do tripulante.
int Tripulante::getTIdade(){
	return this->idade;
}

//Função para retornar o CPF do tripulante.
string Tripulante::getTCPF(){
	return this->cpf;
}

//Função para retornar se o tripulante ta vivo ou não.
bool Tripulante::getTVivo(){
	return this->vivo;
}

//Setter para definir se o tripulante está vivo ou não (True - Vivo / False - Morto).
void Tripulante::setVivo(bool ToF){
	this->vivo = ToF;
}

//Função que retorna um tripulante com todos os dados preenchidos.
Tripulante* addTripul(Voo* voo, Astronauta* astronauta){
	int code_t = voo->getCode(); //Código do voo fornecido pelo usuário.
	int idade_t = astronauta->getIdade(); //Idade do astronauta fornecido pelo usuário.
	string nome_t = astronauta->getNome(); //Nome do astronauta fornecido pelo usuário.
	string cpf_t = astronauta->getCPF(); //CPF do astronauta fornecido pelo usuário.
	bool vivo_t = astronauta->getVivo(); //Se o astronauta está vivo ou não.

	//Cria um tripulante com as variáveis do início da função.
	Tripulante* tripul = new Tripulante(code_t, idade_t, nome_t, cpf_t, vivo_t);
	return tripul; //Retorna esse tripulante.
}
