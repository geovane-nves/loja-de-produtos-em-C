#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dupla.h"

void inserirNoInicio_dupla(Produto produto, No_duplo **lista)
{
    No_duplo *novo = malloc(sizeof(No_duplo));

    if (novo == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->produto = produto;
    novo->ant = NULL;
    novo->prox = *lista;

    if (*lista != NULL)
    {
        (*lista)->ant = novo;
    }

    *lista = novo;

    printf("Produto inserido com sucesso.\n");
}

void inserirNoFinal_dupla(Produto produto, No_duplo **lista)
{
    No_duplo *novo = malloc(sizeof(No_duplo));

    if (novo == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->produto = produto;
    novo->prox = NULL;

    if (*lista == NULL)
    {
        novo->ant = NULL;
        *lista = novo;
        printf("Produto inserido com sucesso.\n");
        return;
    }

    No_duplo *atual = *lista;

    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    novo->ant = atual;
    atual->prox = novo;

    printf("Produto inserido com sucesso.\n");
}

void removerInicio_dupla(No_duplo **lista)
{
    if (*lista == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }

    No_duplo *remover = *lista;

    *lista = remover->prox;

    if (*lista != NULL)
    {
        (*lista)->ant = NULL;
    }

    free(remover);

    printf("Produto removido com sucesso.\n");
}

void removerFim_dupla(No_duplo **lista)
{
    if (*lista == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }

    No_duplo *atual = *lista;

    while (atual->prox != NULL)
    {
        atual = atual->prox;
    }

    if (atual->ant != NULL)
    {
        atual->ant->prox = NULL;
    }
    else
    {
        *lista = NULL;
    }

    free(atual);

    printf("Produto removido com sucesso.\n");
}

void removerPorId_dupla(No_duplo **lista, int id)
{
    if (*lista == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }

    No_duplo *atual = *lista;

    while (atual != NULL && atual->produto.id != id)
    {
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("ID nao encontrado.\n");
        return;
    }

    if (atual->ant != NULL)
    {
        atual->ant->prox = atual->prox;
    }
    else
    {
        *lista = atual->prox;
    }

    if (atual->prox != NULL)
    {
        atual->prox->ant = atual->ant;
    }

    free(atual);

    printf("Produto removido com sucesso.\n");
}

void listar_dupla(No_duplo *lista)
{
    if (lista == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("\nLista de produtos nao pereciveis:\n\n");

    while (lista != NULL)
    {
        exibir_produto(&lista->produto);
        lista = lista->prox;
    }
}

void listarReverso_dupla(No_duplo *lista)
{
    if (lista == NULL)
    {
        printf("A lista esta vazia.\n");
        return;
    }

    while (lista->prox != NULL)
    {
        lista = lista->prox;
    }

    printf("\nLista de produtos nao pereciveis (ordem reversa):\n\n");

    while (lista != NULL)
    {
        exibir_produto(&lista->produto);
        lista = lista->ant;
    }
}

void buscarNome_dupla(No_duplo *lista, char *nome)
{
    int encontrou = 0;

    while (lista != NULL)
    {
        if (strstr(lista->produto.nome, nome) != NULL)
        {
            exibir_produto(&lista->produto);
            encontrou = 1;
        }

        lista = lista->prox;
    }

    if (encontrou == 0)
    {
        printf("Nenhum produto encontrado.\n");
    }
}

void atualizarQuantidade_dupla(No_duplo *lista, int id, int nova_quantidade)
{
    while (lista != NULL)
    {
        if (lista->produto.id == id)
        {
            alterar_quantidade(&lista->produto, nova_quantidade);
            printf("Quantidade atualizada com sucesso.\n");
            return;
        }

        lista = lista->prox;
    }

    printf("Produto com ID %d nao encontrado.\n", id);
}

int contar_dupla(No_duplo *lista)
{
    int quantidade = 0;

    while (lista != NULL)
    {
        quantidade++;
        lista = lista->prox;
    }

    return quantidade;
}

void esvaziar_dupla(No_duplo **lista)
{
    No_duplo *aux;

    while (*lista != NULL)
    {
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }

    printf("Lista esvaziada com sucesso.\n");
}