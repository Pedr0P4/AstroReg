#ifndef MORTO_H
#define MORTO_H

#include "astro.hpp"
#include <string>
using namespace std;

class Morto{
	private:
		string nome;
		string cpf;
		int idade;
	
	public:
		Morto(string nome, string cpf, int idade);
		string getMNome();
		string getMCPF();
		int getMIdade();
};

Morto* addMorto(Astronauta* astro);

#endif
