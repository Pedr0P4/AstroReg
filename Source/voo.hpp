#ifndef VOO_H
#define VOO_H

#include "reg.hpp"

class Voo{
	private:
		int codigo;
		unsigned int Tquant;
		bool lanc;
		bool explode;
		bool finalizado; 

	public:
		Voo(int codigo);
		int getCode();
		unsigned int getTQuant();
		bool getLanc();
		bool getExplode();
		bool getFin();
		void OneT();
		void MOneT();
		void setLanc(bool ToF);
		void setExplode(bool ToF);
		void setFin(bool ToF);
};


Voo* getVooByCode(int code, Registros<Voo*> &RegVoos);

Voo* addVoo(Registros<Voo*> &RegVoo);

#endif
