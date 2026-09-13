#include <stdio.h>
#include <stdlib.h>
#include "menu_circular.h"
#include "../../produto/produto.h"
#include "../circular.h"

void menu_circular(No_circular **lista)
{
    {
        int opcao;
        int id;
        int nova_quantidade;

        char nome[50];
        char validade[20];

        int quantidade;
        float preco;

        Produto *produto;

        do
        {
            printf("\n===== PERECIVEIS =====\n");
            printf("1. Inserir no inicio\n");
            printf("2. Inserir no fim\n");
            printf("3. Remover do inicio\n");
            printf("4. Remover do fim\n");
            printf("5. Remover por ID\n");
            printf("6. Listar produtos\n");
            printf("7. Buscar por nome\n");
            printf("8. Atualizar quantidade\n");
            printf("9. Contar produtos\n");
            printf("10. Esvaziar lista\n");
            printf("0. Voltar\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao)
            {
            case 1:
                // Quando terminar fazer essas funções dentro do funcionalidades
                printf("Nome: ");
                scanf(" %49[^\n]", nome);

                printf("Quantidade: ");
                scanf("%d", &quantidade);

                printf("Preco: ");
                scanf("%f", &preco);

                printf("Validade: ");
                scanf(" %19[^\n]", validade);

                produto = criarProduto(nome, quantidade, preco, validade);

                if (produto != NULL)
                {
                    // Usando a Flag 1 para inserir na cabeça
                    inserir_circular(*produto, lista, 1);
                    free(produto);
                }
                else
                {
                    printf("\nNão Foi Possivel Criar o prduto");
                }

                break;

            case 2:

                printf("Nome: ");
                scanf(" %49[^\n]", nome);

                printf("Quantidade: ");
                scanf("%d", &quantidade);

                printf("Preco: ");
                scanf("%f", &preco);

                printf("Validade: ");
                scanf(" %19[^\n]", validade);

                produto = criarProduto(nome, quantidade, preco, validade);

                if (produto != NULL)
                {
                    inserir_circular(*produto, lista, 2);
                    free(produto);
                }
                else
                {
                    printf("\nNão Foi Possivel Criar o prduto");
                }

                break;

            case 3:

                removerInicio_circular(lista);
                break;

            case 4:

                removerFim_circular(lista);

                break;

            case 5:

                printf("\nDigite o ID: ");
                scanf("%d", &id);

                removerPorId_circular(lista, id);

                break;

                case 6:

                    listar_circular(*lista);

                    break;

                case 7:

                    printf("Digite o nome para buscar: ");
                    scanf(" %49[^\n]", nome);

                    buscarNome_circular(*lista, nome);

                    break;

                case 8:

                    printf("Digite o ID: ");
                    scanf("%d", &id);

                    printf("Digite a nova quantidade: ");
                    scanf("%d", &nova_quantidade);

                    atualizarQuantidade_circular(*lista, id, nova_quantidade);

                    break;

                case 9:

                    printf("Quantidade de produtos: %d\n", contar_circular(*lista));

                    break;

                // case 10:

                //     esvaziar(lista);

                //     break;

            case 0:

                printf("Voltando ao menu principal...\n");

                break;

            default:

                printf("Opcao invalida.\n");
            }

        } while (opcao != 0);
    }
}