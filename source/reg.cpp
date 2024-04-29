//Construtor.
template <typename T> 
Registros<T>::Registros(){  
	this->quant = 0; //A classe começa com 0 em quant.
    this->elements = new T[0]; //A classe começa com um ponteiro de um array com 0 elementos.
}

//Função para adicionar elementos.
template <typename T> 
void Registros<T>::addE(T elem){
	T* novoArray = new T[quant+1]; //Criação de um ponteiro para um array do tamanho da quantidade de elementos atuais +1.

	for(int i=0;i<this->quant;i++){
		novoArray[i] = this->elements[i]; //Copia todos os elementos de elements da classe para esse novo array.
	}

	novoArray[this->quant] = elem; //No fim do array adiciona o elemento novo. 

	delete[] this->elements; //Deleta o ponteiro dos elementos da classe.
	this->elements = novoArray; //Os elementos da classe agora recebem o novo array com o novo elemento e os anteriores.

	this->quant++; //Quantidade de elementos é incrementado em 1.
}

//Função para deletar elementos.
template <typename T> 
void Registros<T>::delE(T elem){
	T* novoArray = new T[quant-1]; //Criação de um ponteiro para um array do tamanho da quantidade de elementos atuais -1.
	unsigned int j = 0; //Variável para manipular as posições do array.

	for(int i=0;i<this->quant;i++){
		if(elem != elements[i]){ //Se o elemento fornecido pelo usuário for diferente do elemento de posição i do vetor.
			novoArray[j++] = this->elements[i]; //O valor do elemento é copiado para o array criado no início da função.
		}
	}

	delete[] this->elements; //Deleta o array de elementos da classe.
	this->elements = novoArray; //O array de elementos da classe recebe o array criado no início da função.

	this->quant--; //Quantidade de elementos diminui em 1.
}

//Função para mostrar o elemento na posição recebida no parâmetro (pos).
template <typename T> 
T Registros<T>::getE(unsigned int pos){
    return this->elements[pos];
}

//Função para retornar o valor da quantidade de elementos.
template <typename T> 
int Registros<T>::getQuant(){
    return this->quant;
}

//Destrutor.
template <typename T> 
Registros<T>::~Registros(){
    delete[] elements;
}
