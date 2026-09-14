#include <stdio.h>
#include "./simples/simples.h"
#include "./simples/menu/menu_simples.h"

// Importação da Lista Circular Simplesmente encadeada
#include "./circular/circular.h"
#include "./circular/menu/menu_circular.h"

// Importação da Lista Duplamente Encadeada
#include "./dupla/dupla.h"
#include "./dupla/menu/menu_dupla.h"

int main()
{
    No *lista = NULL;
    No_circular *cabeca_circular = NULL;
    No_duplo *lista_dupla = NULL;
    int opcao;

    do
    {
        printf("\n===== ESTOQUE DA LOJA =====\n");
        printf("1. Gerenciar Perecíveis (Simples)\n");
        printf("2. Gerenciar Nao Perecíveis (Dupla)\n");
        printf("3. Gerenciar Promoções (Circular)\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            menu_simples(&lista);
            break;

        case 2:
            menu_dupla(&lista_dupla);
            break;

        case 3:
            menu_circular(&cabeca_circular);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    esvaziar(&lista);
    esvaziar_dupla(&lista_dupla);

    return 0;
}