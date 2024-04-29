#ifndef ASTRO_H
#define ASTRO_H

#include <string>
#include "reg.hpp"
using namespace std;

class Astronauta{
    private:
        int idade;
		bool vivo;
        string cpf;
        string nome;
		bool ocup;

    public:
    	Astronauta(int idade, string cpf, string nome);

		int getIdade();

		bool getVivo();

		string getCPF();

		string getNome();

		bool getOcup();

		void setVivo(bool ToF);

		void setOcup(bool ToF);
};

Astronauta* getAstroByCPF(string cpf, Registros<Astronauta*> &RegAst);

Astronauta* addAstro(Registros<Astronauta*> &RegAst);

#endif
