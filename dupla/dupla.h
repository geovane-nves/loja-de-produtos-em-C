#ifndef DUPLA_H
#define DUPLA_H

#include "../produto/produto.h"

typedef struct No_duplo
{
    Produto produto;
    struct No_duplo *ant;
    struct No_duplo *prox;
} No_duplo;

void inserirNoInicio_dupla(Produto produto, No_duplo **lista);
void inserirNoFinal_dupla(Produto produto, No_duplo **lista);

void removerInicio_dupla(No_duplo **lista);
void removerFim_dupla(No_duplo **lista);
void removerPorId_dupla(No_duplo **lista, int id);

void listar_dupla(No_duplo *lista);
void listarReverso_dupla(No_duplo *lista);
void buscarNome_dupla(No_duplo *lista, char *nome);

void atualizarQuantidade_dupla(No_duplo *lista, int id, int nova_quantidade);

int contar_dupla(No_duplo *lista);

void esvaziar_dupla(No_duplo **lista);

#endif