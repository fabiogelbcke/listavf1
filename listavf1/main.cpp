
#include <iostream>

class Pessoa{
public:
    std::string nome;
    int dianasc;
    int mesnasc;
    int anonasc;
    Pessoa *prox;
public:
    Pessoa(int dia, int mes, int ano, std::string nome):anonasc(ano), mesnasc(mes), dianasc(dia), nome(nome){
        prox = nullptr;
    }
};

template <class p>
class Lista {
    p *cabeca;
    p *atual;
public:
    Lista(){
        cabeca=nullptr;
        atual=nullptr;
    }
    void inserir(p);
    void bsort();
    void listar(){
        p *pont = cabeca;
        std::cout<<pont->nome<<std::endl;
        do{
            pont = pont->prox;
            std::cout<<pont->nome<<std::endl;
            
            
        }while (pont != atual);
    }
    
};
template <class p>
void Lista<p>::bsort() {
    p *atual;
    p *anterior;
    atual = this->cabeca;
    anterior=nullptr;
    while (atual->prox != nullptr){
        bool shouldswitch=false;
        if (atual->anonasc < atual->prox->anonasc){
            shouldswitch=true;
        }
        else if (atual->anonasc == atual->prox->anonasc && atual->mesnasc < atual->prox->mesnasc){
            shouldswitch=true;
        }
        else if (atual->anonasc == atual->prox->anonasc && atual->mesnasc == atual->prox->mesnasc && atual->dianasc < atual->prox->dianasc){
            shouldswitch=true;
        }
        if (shouldswitch){
            std::cout<<"1"<<atual->nome<<std::endl;
            std::cout<<"2"<<atual->prox->nome<<std::endl;
            if(anterior!=nullptr){
                anterior->prox = atual->prox;
            }
            else{
                this->cabeca = atual->prox;
            }
            if (atual->prox->prox != nullptr){
                p *temp = atual->prox->prox;
                atual->prox->prox = atual;
                atual->prox = temp;
            }
            else{
                atual->prox->prox=atual;
                atual->prox=nullptr;
                this->atual = atual;
            }
            
            anterior = nullptr;
            atual = this->cabeca;
            std::cout<<"lista:"<<std::endl;
            this->listar();
            std::cout<<"endlista"<<std::endl;
        }
        else{
            std::cout<<"a"<<atual->nome<<std::endl;
            anterior = atual;
            atual = atual->prox;
            
            
        }
    }
}

template <class p>
void Lista<p>::inserir(p person){
    if (this->atual!=nullptr){
        this->atual->prox = &person;
        this->atual = &person;
    }
    else{
        this->atual = &person;
        this->cabeca = &person;
    }
}

int main(int argc, const char * argv[])
{
    
    
    
    Pessoa p1 = Pessoa(15, 10, 1993, "random1");
    Pessoa p2 = Pessoa(10, 12, 1996, "random2");
    Pessoa p3 = Pessoa(13, 5, 1994, "random3");
    Lista<Pessoa> list;
    list.inserir(p1);
    list.inserir(p2);
    list.inserir(p3);
    list.listar();
    std::cout<<"-------"<<std::endl;
    list.bsort();
    std::cout<<"-------"<<std::endl;
    list.listar();
    
    

    
    return 0;
}

