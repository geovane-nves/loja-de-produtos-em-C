#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "../produto/produto.h"

typedef struct No_circular
{
    Produto produto;
    struct No_circular *prox;
} No_circular;

void inserir_circular(Produto produto, No_circular **cabeca, int flag);
void removerInicio_circular(No_circular **cabeca);
void removerFim_circular(No_circular **cabeca);
void removerPorId_circular(No_circular **cabeca, int id);
void listar_circular(No_circular *cabeca);
void buscarNome_circular(No_circular *cabeca, char *nome);
void atualizarQuantidade_circular(No_circular *cabeca, int id, int nova_quantidade);
int contar_circular(No_circular *cabeca);
void esvaziar_circular(No_circular **cabeca);
#endif