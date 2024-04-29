#include "morto.hpp"
#include "astro.hpp"
#include <string>
using namespace std;

Morto::Morto(string nome, string cpf, int idade){
	this->nome = nome;
	this->cpf = cpf;
	this->idade = idade;
}

string Morto::getMNome(){
	return this->nome;
}

string Morto::getMCPF(){
	return this->cpf;
}

int Morto::getMIdade(){
	return this->idade;
}

//Função que retorna um tripulante com todos os dados preenchidos.
Morto* addMorto(Astronauta* astro){
	string nome = astro->getNome(); //Nome do astronauta fornecido pelo usuário.
	string cpf = astro->getCPF(); //CPF do astronauta fornecido pelo usuário.
	int idade = astro->getIdade(); //Idade do astronauta fornecido pelo usuário.

	//Cria um morto com as variáveis do início da função.
	Morto* morto = new Morto(nome, cpf, idade);
	return morto; //Retorna esse morto.
}

