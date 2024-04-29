#include <string>
#include <iostream>
#include "reg.hpp"
#include "format.hpp"
#include "astro.hpp"

using namespace std;

//Construtor.
Astronauta::Astronauta(int idade, string cpf, string nome){
	this->idade = idade; //idade da classe recebe idade (parâmetro).
	this->vivo = true; //vivo recebe true (NÃO é parâmetro).
	this->cpf = cpf; //cpf da classe recebe cpf (parâmetro).
	this->nome = nome; //nome da classe recebe nome (parâmetro).
	this->ocup = false; //ocup da classe recebe false.
}

//Função que retorna o valor da variável idade da classe.
int  Astronauta::getIdade(){
	return this->idade;
}

//Função que retorna se está vivo ou não.
bool Astronauta::getVivo(){
	return this->vivo;
}

//Função que retorna o conteúdo da variável cpf da classe.
string Astronauta::getCPF(){
	return this->cpf;
}

//Função que retorna o conteúdo da variável nome da classe.
string Astronauta::getNome(){
	return this->nome;
}

//Função que retorna o conteúdo da variável ocup da classe.
bool Astronauta::getOcup(){
	return this->ocup;
}

//Setter para definir se o astronauta está vivo ou não (True - Vivo / False - Morto);
void Astronauta::setVivo(bool ToF){
	this->vivo = ToF;
}

//Setter para definir se o astronauta está ocupado em um voo.
void Astronauta::setOcup(bool ToF){
	this->ocup = ToF;
}

//Função que pega um astronauta pelo CPF.
Astronauta* getAstroByCPF(string cpf, Registros<Astronauta*> &RegAst){
	unsigned int qtastro = RegAst.getQuant(); //Variável que recebe a quantidade de astronautas do vetor RegAst (parâmetro).

	//Loop para comparar os cpfs de cada astronauta do vetor para ver qual é igual.
	for(int i=0;i<qtastro;i++){
		string t_cpf = RegAst.getE(i)->getCPF();
		if(cpf == t_cpf){
			return RegAst.getE(i); //Retorna o astronauta.
		}
	}

	return NULL; //Retorna Vazio.
}

//Função que retorna um astronauta com todos os dados preenchidos.
Astronauta* addAstro(Registros<Astronauta*> &RegAst){
	string nome; //Variável para receber o nome do astronauta.
	string t_cpf; //Variável para receber o CPF do astronauta.
	int idade; // Variável para receber a idade do astronauta.

	LimparBuffer(); //Limpa o buffer.

	cout << "-----------------------------------" << endl;
	//Coleta do nome do astronauta.
	cout << "Qual o nome do astronauta?" << endl;
	getline(cin, nome);
	cout << "-----------------------------------" << endl;

	//Coleta do CPF do astronauta.
	cout << "Qual o CPF de " << nome << "?" << endl;
	getline(cin, t_cpf);
	cout << "-----------------------------------" << endl;

	string cpf = confCPF(t_cpf);

	if(getAstroByCPF(cpf, RegAst) != NULL){
		cout << "Já há um CPF igual ao fornecido. Tente um novo!" << endl;
		cout << "-----------------------------------" << endl;
		return NULL;
	} else{
		//Coleta da idade do astronauta.
		cout << "Qual a idade de " << nome << "?" << endl;
		cin >> idade;
		cout << "-----------------------------------" << endl;
		
		//Ponteiro para criar um astronauta com os valores fornecidos pelo usuário.
		Astronauta* astro = new Astronauta(idade, cpf, nome);
		return astro; //Retorna o ponteiro.
	}	
}
