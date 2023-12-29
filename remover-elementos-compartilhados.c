#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("14576642, 12684333");
}

// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Gustavo Bastos de Souza", "Júlio César Cordeiro Batista");
}

// elemento da lista
typedef struct estrutura {
    int chave;
    struct estrutura* prox;
} NO;

void tornarCircular(NO* p1, NO* p2, NO* compartilhado){
    NO* primeiroItemP1 = p1;
    NO* primeiroItemP2 = p2;
    NO* anteriorP1;
    NO* anteriorP2;
    while(p1 != compartilhado){
        anteriorP1 = p1;
        p1 = p1->prox;
    }
    while(p2 != compartilhado){
        anteriorP2 = p2;
        p2 = p2->prox;
    }
    anteriorP1->prox = primeiroItemP1;
    anteriorP2->prox = primeiroItemP2;
}

// funcao principal
void removerNoCompartilhados(NO* *p1, NO* *p2) {

    NO* noLista1 = *p1;
    NO* noLista2 = *p2;
    NO* compartilhado = NULL;

    bool control = false;

    while (noLista1 != NULL) {
        noLista2 = *p2;  // Reinicia noLista2 no início da segunda lista para cada iteração de noLista1.

        while (noLista2 != NULL) {
            if (noLista1 == noLista2) {
                compartilhado = noLista1;
                control = true;
                break;
            }
            noLista2 = noLista2->prox;  // Avança noLista2 para o próximo nó.
        }

        if (control) break;
        noLista1 = noLista1->prox;
    }

    if (compartilhado != NULL) {
        printf("Compartilhado %d \n", compartilhado->chave);
        tornarCircular(*p1, *p2, compartilhado);
        free(compartilhado);
    } else {
        printf("Nenhum nó compartilhado encontrado\n");
    }
}

// por favor nao inclua nenhum codigo a ser entregue abaixo deste ponto§

//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------

int main() {
	NO* p1 = NULL;
	NO* p2 = NULL;
    removerCompartilhados(&p1, &p2);
}


