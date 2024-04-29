#ifndef TRIP_H
#define TRIP_H

#include "astro.hpp"
#include "voo.hpp"
#include <string>
using namespace std;

class Tripulante{
	private:
		int codigo;
		int idade;
		string nome;
		string cpf;
		bool vivo; 

	public:
		Tripulante(int codigo, int idade, string nome, string cpf, bool VoM);
		int getTCode();
		string getTNome();
		int getTIdade();
		string getTCPF();
		bool getTVivo();
		void setVivo(bool ToF);
};

Tripulante* addTripul(Voo* voo, Astronauta* astronauta);

#endif
