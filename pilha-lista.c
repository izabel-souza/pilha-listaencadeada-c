#include "pilha-lista.h"

TPilha *inicializa() {
    TPilha *pilha = malloc(sizeof(TPilha));
    pilha->topo = NULL;

    return pilha;
}

void libera(TPilha *p) {
    TLista *aux = p->topo;
    TLista *r;

    while(aux != NULL) {
        r = aux;
        aux = aux->prox;
        free(r);
    }
    free(p);
}

int pilha_vazia(TPilha *pilha) {
    if(pilha->topo == NULL) return 1;
    else return 0;
}

/* *
 * Insere elem no topo da pilha
 * */
void push(TPilha *pilha, int elem) {
    TLista *novo = malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

/* *
 * Altera o elemento do topo da pilha
 * */
void altera_topo(TPilha *pilha, int elem) {
    pilha->topo->info = elem;
}

/* *
 * Exclui o elemento do topo da pilha
 * retorna o info do elemento excluído
 */
int pop(TPilha *pilha) {
	if(!pilha_vazia(pilha)) {
        int aux = pilha->topo->info;
        pilha->topo = pilha->topo->prox;

        return aux;
    }
    else printf("Pilha vazia"); exit(1);
}

/* *
 * Consulta o elemento do topo da pilha
 * retorna info do elemento do topo
 */
int peek(TPilha *pilha) {
    if(!pilha_vazia(pilha)){
        int aux = pilha->topo->info;
        return aux;
    }
    else return -1;
}

void imprime_pilha(TPilha *pilha) {
    for(TLista *p = pilha->topo; p != NULL; p = p->prox) {
        printf("%d \n", p->info);
    }
    printf("\n");
}

int main (void) {
    
    TPilha *pilha;
    pilha = inicializa();
    push(pilha, 5);
    printf("topo: %d\n", peek(pilha));
    push(pilha, 4);
    printf("topo: %d\n", peek(pilha));
    push(pilha, 3);
    printf("topo: %d\n", peek(pilha));

    printf("Pilha original:\n");
    imprime_pilha(pilha);

    int info = pop(pilha);
    printf("elemento removido: %d\n", info);

    printf("Pilha apos remocao:\n");
    imprime_pilha(pilha);

    altera_topo(pilha, 7);
    printf("Pilha apos alteracao do topo:\n");
    imprime_pilha(pilha);
}