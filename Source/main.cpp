#include <iostream>

using namespace std;

template <typename T> class RegAst{
    private:
        unsigned int quant;
        T* elements;
    
    public:
        RegAst(){
            this->quant = 0;
            this->elements = new T[0];
        }

        void addE(T* Astronauta){
            T* novoArray = new T*[quant+1];

            for(int i=0;i<this->quant;i++){
                novoArray[i] = this->elements[i];
            }

            novoArray[this->quant] = item;

            delete this->elements;
            this->elements = novoArray;

            this->quant++;
        }
};

class Astronaut{
    private:
        int idade;
        string cpf;
        string nome;
    public:
    


};

int main(){
    RegAst<*Astronaut>


    return 0;
}