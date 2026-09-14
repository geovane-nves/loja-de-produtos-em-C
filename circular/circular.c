#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular.h"

void inserir_circular(Produto produto, No_circular **cabeca, int flag)
{
    No_circular *novo = malloc(sizeof(No_circular));
    if (novo == NULL)
    {
        puts("Erro ao alocar memoria.");
        return;
    }

    novo->produto = produto;
    if (*cabeca == NULL)
    {
        novo->prox = novo;
        *cabeca = novo;
    }
    else
    {
        No_circular *ultimo = *cabeca;
        while (ultimo->prox != *cabeca)
        {
            ultimo = ultimo->prox;
        }

        novo->prox = *cabeca;

        ultimo->prox = novo;

        if (flag == 1)
        {
            *cabeca = novo;
        }
    }

    return;
}

void removerInicio_circular(No_circular **cabeca)
{
    if (*cabeca == NULL)
    {
        printf("A lista de Produtos em Promoção esta vazia.\n");
        return;
    }

    No_circular *antiga_cabeca = *cabeca;

    if (antiga_cabeca->prox == *cabeca)
    {
        *cabeca = NULL;
        free(antiga_cabeca);
        return;
    }

    No_circular *ultimo = *cabeca;
    while (ultimo->prox != *cabeca)
    {
        ultimo = ultimo->prox;
    }

    *cabeca = antiga_cabeca->prox;
    ultimo->prox = *cabeca;
    free(antiga_cabeca);

    return;
}

void removerFim_circular(No_circular **cabeca)
{
    if (*cabeca == NULL)
    {
        printf("A lista de Produtos em Promoção esta vazia.\n");
        return;
    }

    No_circular *remover = *cabeca;

    if (remover->prox == *cabeca)
    {
        *cabeca = NULL;
        free(remover);
        return;
    }

    No_circular *penultimo = *cabeca;
    No_circular *ultimo;
    while (penultimo->prox->prox != *cabeca)
    {
        penultimo = penultimo->prox;
    }

    ultimo = penultimo->prox;

    penultimo->prox = *cabeca;

    free(ultimo);

    return;
}

void removerPorId_circular(No_circular **cabeca, int id)
{
    if (*cabeca == NULL)
    {
        printf("A lista de Produtos em Promoção esta vazia.\n");
        return;
    }

    if ((*cabeca)->produto.id == id)
    {
        removerInicio_circular(cabeca);
        return;
    }

    No_circular *atual = *cabeca;

    while (atual->prox->produto.id != id && atual->prox != *cabeca)
    {
        atual = atual->prox;
    }
    if (atual->prox == *cabeca)
    {
        printf("Produto com ID %d não encontrado.\n", id);
        return;
    }
    No_circular *remover = atual->prox;

    atual->prox = remover->prox;
    free(remover);

    return;
}

void listar_circular(No_circular *cabeca)
{

    if (cabeca == NULL)
    {
        printf("A Lista esta vazia \n");
        return;
    }

    printf("\ncabeca de produtos pereciveis: \n\n");

    No_circular *comparador = cabeca;
    do
    {
        printf("ID: %d\n", comparador->produto.id);
        printf("Nome: %s\n", comparador->produto.nome);
        printf("Quantidade: %d\n", comparador->produto.quantidade);
        printf("Preco: %.2f\n", comparador->produto.preco);
        printf("\n");

        comparador = comparador->prox;
    } while (comparador->prox != cabeca);

    return;
}

void buscarNome_circular(No_circular *cabeca, char *nome)
{
    if (cabeca == NULL)
    {
        printf("A Lista esta vazia \n");
        return;
    }

    No_circular *comparador = cabeca;
    int encontrou = 0;
    do
    {
        if (strstr(comparador->produto.nome, nome) != NULL)
        {
            exibir_produto(&comparador->produto);
            encontrou++;
        }
        comparador = comparador->prox;
    } while (comparador->prox != cabeca);

    if (encontrou == 0)
    {
        printf("Nenhum produto encontrado.\n");
    }

    return;
}

void atualizarQuantidade_circular(No_circular *cabeca, int id, int nova_quantidade)
{
    if (cabeca == NULL)
    {
        printf("A Lista esta vazia \n");
        return;
    }

    No_circular *comparador = cabeca;

    do
    {
        if (comparador->produto.id == id)
        {
            alterar_quantidade(&comparador->produto, nova_quantidade);
            printf("Quantidade atualizada com sucesso.\n");
            return;
        }
        comparador = comparador->prox;
    } while (comparador->prox != cabeca);

    printf("Produto com ID %d nao encontrado.\n", id);

    return;
}

int contar_circular(No_circular *cabeca)
{
    if (cabeca == NULL)
    {
        printf("A Lista esta vazia \n");
        return 0;
    }

    No_circular *percorrer = cabeca;
    int contador = 0;

    do
    {
        contador++;
        percorrer = percorrer->prox;
    } while (percorrer->prox != cabeca);

    return contador;
}

void esvaziar_circular(No_circular **cabeca)
{
    if (*cabeca == NULL)
    {
        return;
    }

    No_circular *atual = (*cabeca)->prox;
    No_circular *aux;

    while (atual != *cabeca)
    {
        aux = atual;
        atual = atual->prox;
        free(aux);
    }

    free(*cabeca);

    *cabeca = NULL;

    printf("Lista esvaziada com sucesso.\n");
}
