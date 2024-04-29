#ifndef REG_H
#define REG_H

template <typename T>
class Registros {
	private:
		unsigned int quant;
		T* elements;

	public:
		Registros();
		void addE(T elem);
		void delE(T elem);
		T getE(unsigned int pos);
		int getQuant();
		~Registros();
};

#include "../source/reg.cpp"

#endif
