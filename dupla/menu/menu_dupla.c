#include <stdio.h>
#include <stdlib.h>
#include "menu_dupla.h"
#include "../../produto/produto.h"
#include "../dupla.h"

void menu_dupla(No_duplo **lista)
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
        printf("\n===== NAO PERECIVEIS =====\n");
        printf("1. Inserir no inicio\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do inicio\n");
        printf("4. Remover do fim\n");
        printf("5. Remover por ID\n");
        printf("6. Listar produtos\n");
        printf("7. Listar em ordem reversa\n");
        printf("8. Buscar por nome\n");
        printf("9. Atualizar quantidade\n");
        printf("10. Contar produtos\n");
        printf("11. Esvaziar lista\n");
        printf("0. Voltar\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
    case 1:
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
        inserirNoInicio_dupla(*produto, lista);
        free(produto);
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
        inserirNoFinal_dupla(*produto, lista);
        free(produto);
    }

    break;
    
    case 3:
    removerInicio_dupla(lista);
    break;




    case 4:
    removerFim_dupla(lista);
    break;




    case 5:
    printf("Digite o ID: ");
    scanf("%d", &id);

    removerPorId_dupla(lista, id);
    break;



    case 6:
    listar_dupla(*lista);
    break;

    

    case 7:
    listarReverso_dupla(*lista);
    break;





    case 8:
    printf("Digite o nome para buscar: ");
    scanf(" %49[^\n]", nome);

    buscarNome_dupla(*lista, nome);

    break;




    case 9:
    printf("Digite o ID: ");
    scanf("%d", &id);

    printf("Digite a nova quantidade: ");
    scanf("%d", &nova_quantidade);

    atualizarQuantidade_dupla(*lista, id, nova_quantidade);

    break;






    case 10:
    printf("Quantidade de produtos: %d\n", contar_dupla(*lista));
    break;



    case 11:
    esvaziar_dupla(lista);
    break;





    
        }

    } while (opcao != 0);
}