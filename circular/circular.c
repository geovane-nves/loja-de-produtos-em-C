#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular.h"

// Insere um produto em uma lista circular.
// flag == 1: insere no início e atualiza a cabeça.
// flag == 2: insere no final e mantém a cabeça atual.
void inserir_circular(Produto produto, No_circular **cabeca, int flag)
{
    No_circular *novo = malloc(sizeof(No_circular));
    if (novo == NULL)
    {
        puts("Erro ao alocar memoria.");
        return;
    }

    // Adiciona o produto ao novo nó
    novo->produto = produto;
    if (*cabeca == NULL)
    {
        // Proximo sendo ele mesmo tornando a cabeca circular
        novo->prox = novo;
        // Primeiro item da cabeca
        *cabeca = novo;
    }
    else
    {
        No_circular *ultimo = *cabeca;
        // Verifica se o proximo nó não é a cabeca
        while (ultimo->prox != *cabeca)
        {
            ultimo = ultimo->prox;
        }

        // Faz o novo nó apontar para o antigo início
        novo->prox = *cabeca;

        // Faz o último nó apontar para o novo início, fechando o círculo
        ultimo->prox = novo;

        if (flag == 1)
        {
            // Atualiza a lista principal para começar a partir do novo nó
            *cabeca = novo;
        }
    }

    return;
}

// Remove o primeiro nó da lista e atualiza a cabeça.
void removerInicio_circular(No_circular **cabeca)
{
    if (*cabeca == NULL)
    {
        printf("A lista de Produtos em Promoção esta vazia.\n");
        return;
    }

    No_circular *antiga_cabeca = *cabeca;

    // Verificar se a cabeca só tem um elemento
    if (antiga_cabeca->prox == *cabeca)
    {
        // Se tiver ela passa a não ter mais nenhum
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

// Remove o último nó da lista, mantendo a cabeça no mesmo produto.
void removerFim_circular(No_circular **cabeca)
{
    if (*cabeca == NULL)
    {
        printf("A lista de Produtos em Promoção esta vazia.\n");
        return;
    }

    No_circular *remover = *cabeca;

    // Verificar se a cabeca só tem um elemento
    if (remover->prox == *cabeca)
    {
        // Se tiver ela passa a não ter mais nenhum
        *cabeca = NULL;
        free(remover);
        return;
    }

    No_circular *penultimo = *cabeca;
    No_circular *ultimo;
    while (penultimo->prox->prox != *cabeca)
    {
        // Acho o penultimo
        penultimo = penultimo->prox;
    }

    // Acho o ultimo
    ultimo = penultimo->prox;

    // O penutimo vira o ultimo
    penultimo->prox = *cabeca;

    // Libera o ultimo
    free(ultimo);

    return;
}

// Procura um produto pelo ID e remove o nó correspondente.
void removerPorId_circular(No_circular **cabeca, int id)
{
    // Lista Vazia
    if (*cabeca == NULL)
    {
        printf("A lista de Produtos em Promoção esta vazia.\n");
        return;
    }

    // Verificar se a cabeca é o elemento desejado
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
    // Verifica se o Loop encontrou o ID
    if (atual->prox == *cabeca)
    {
        // Se o codigo chegou ate a cabeça significa que não foi encontrado o respectivo id
        printf("Produto com ID %d não encontrado.\n", id);
        return;
    }
    // o que desejamos remover:
    No_circular *remover = atual->prox;

    // O atual prox vai ser o proximo de remover
    atual->prox = remover->prox;
    free(remover);

    return;
}

// Percorre e exibe todos os produtos da lista circular.
void listar_circular(No_circular *cabeca)
{

    if (cabeca == NULL)
    {
        printf("A Lista esta vazia \n");
        return;
    }

    printf("\ncabeca de produtos pereciveis: \n\n");

    No_circular *comparador = cabeca;
    // O do-while garante que a cabeça também seja visitada.
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

// Exibe os produtos cujo nome contém o texto informado.
void buscarNome_circular(No_circular *cabeca, char *nome)
{
    if (cabeca == NULL)
    {
        printf("A Lista esta vazia \n");
        return;
    }

    No_circular *comparador = cabeca;
    int encontrou = 0;
    // A busca termina quando o percurso volta para a cabeça.
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

// Atualiza a quantidade do produto identificado pelo ID.
void atualizarQuantidade_circular(No_circular *cabeca, int id, int nova_quantidade)
{
    if (cabeca == NULL)
    {
        printf("A Lista esta vazia \n");
        return;
    }

    No_circular *comparador = cabeca;

    // Percorre a lista até encontrar o ID ou retornar à cabeça.
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

// Retorna a quantidade de nós existentes na lista circular.
int contar_circular(No_circular *cabeca)
{
    if (cabeca == NULL)
    {
        printf("A Lista esta vazia \n");
        return 0;
    }

    No_circular *percorrer = cabeca;
    int contador = 0;

    // Cada passagem pelo laço representa um nó da lista.
    do
    {
        contador++;
        percorrer = percorrer->prox;
    } while (percorrer->prox != cabeca);

    return contador;
}

// Libera todos os nós e deixa a lista vazia.
void esvaziar_circular(No_circular **cabeca)
{
    // Se já estiver vazia, não faz nada
    if (*cabeca == NULL)
    {
        return;
    }

    // Começa apagando a partir do SEGUNDO nó
    No_circular *atual = (*cabeca)->prox;
    No_circular *aux;

    // Vai apagando até dar a volta e chegar na cabeça de novo
    while (atual != *cabeca)
    {
        aux = atual;
        atual = atual->prox;
        free(aux);
    }

    // limpamos a cabeça
    free(*cabeca);

    // Garantindo que o ponteiro principal zere, indicando lista vazia
    *cabeca = NULL;

    printf("Lista esvaziada com sucesso.\n");
}
