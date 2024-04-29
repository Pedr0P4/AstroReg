#include "format.hpp"
#include <string>
#include <iostream>
#include <limits>

using namespace std;

//Função que limpa o buffer.
void LimparBuffer(){
	//Limpar o buffer.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//Função para padronizar os CPF's.
string confCPF(string cpf){
	unsigned int tamanho_string = cpf.length(); //Variável que armazena o tamanho do cpf do parâmetro.
	string novo_cpf = "00000000000"; //Variável que armazena uma sequência de 0's do tamanho de um cpf padrão.

	//Se o tamanho do cpf do parâmetro for menor ou igual a 11.
	if(tamanho_string <= 11){
		//Loop que repete tamanho_string vezes.
		for(int i=0;i<tamanho_string;i++){
			novo_cpf[i] = cpf[i]; //Novo_cpf na posição i recebe o número da posição i do cpf do parâmetro.
		}
	} else{ //Caso contrário.
		//Loop que repete 11 vezes (tamanho padrão de um CPF).
		for(int i=0;i<11;i++){
			novo_cpf[i] = cpf[i]; //Novo_cpf na posição i recebe o número da posição i do cpf do parâmetro.
		}
	}

	return novo_cpf; //Retorna novo_cpf
}

//Função para formatar o CPF.
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

