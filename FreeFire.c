#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10

typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
    int prioridade;
} Item;

Item mochila[MAX_ITENS];
int numItens = 0;
bool ordenadaPorNome = false;

void limparTela() {
    printf("\n");
}

void pausa() {
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
    getchar();
}

void inserirItem() {
    if (numItens >= MAX_ITENS) {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        pausa();
        return;
    }

    Item novo;
    printf("Digite o nome do item: ");
    scanf(" %[^\n]", novo.nome);
    printf("Digite o tipo do item: ");
    scanf(" %[^\n]", novo.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);
    printf("Digite a prioridade (1 a 5): ");
    scanf("%d", &novo.prioridade);

    mochila[numItens++] = novo;
    ordenadaPorNome = false;

    printf("Item adicionado com sucesso!\n");
    pausa();
}

void removerItem() {
    if (numItens == 0) {
        printf("Mochila vazia! Nenhum item para remover.\n");
        pausa();
        return;
    }

    char nome[50];
    printf("Digite o nome do item que deseja remover: ");
    scanf(" %[^\n]", nome);

    int posicao = -1;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("Item nao encontrado!\n");
        pausa();
        return;
    }

    for (int i = posicao; i < numItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }
    numItens--;
    ordenadaPorNome = false;

    printf("Item removido com sucesso!\n");
    pausa();
}

void listarItens() {
    if (numItens == 0) {
        printf("Mochila vazia!\n");
        pausa();
        return;
    }

    printf("        --- ITENS DA MOCHILA ---\n");
    printf("%-20s %-15s %-10s %-10s\n", "Nome", "Tipo", "Quantidade", "Prioridade");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < numItens; i++) {
        printf("%-20s %-15s %-10d %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade,
               mochila[i].prioridade);
    }
    pausa();
}

void exibirMenu() {
    limparTela();
    printf("--- MENU PRINCIPAL ---\n");
    printf("1. Adicionar item\n");
    printf("2. Remover item\n");
    printf("3. Listar todos os itens (exibe tabela com os componentes)\n");
    printf("4. Ordenar os itens por criterio (nome, tipo, prioridade)\n");
    printf("5. Realizar busca binaria por nome\n");
    printf("6. Sair\n");

    if (ordenadaPorNome) {
        printf("Status: Lista ordenada por nome\n");
    } else {
        printf("Status: Lista nao esta ordenada por nome\n");
    }
    printf("Escolha: ");
}

int compararPorNome(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return strcmp(itemA->nome, itemB->nome);
}

void ordenarPorNomeFuncao() {
    if (numItens == 0) {
        printf("Mochila vazia! Nao ha itens para ordenar.\n");
        pausa();
        return;
    }
    qsort(mochila, numItens, sizeof(Item), compararPorNome);
    ordenadaPorNome = true;
    printf("Itens ordenados por nome com sucesso!\n");
    pausa();
}

void buscaBinariaPorNome() {
    if (!ordenadaPorNome) {
        printf("A mochila nao esta ordenada por nome!\nUse a opcao de ordenacao antes de buscar.\n");
        pausa();
        return;
    }

    if (numItens == 0) {
        printf("Mochila vazia! Nenhum item para buscar.\n");
        pausa();
        return;
    }

    char nome[50];
    printf("Digite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nome);

    int inicio = 0, fim = numItens - 1;
    bool encontrado = false;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(nome, mochila[meio].nome);

        if (cmp == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[meio].nome);
            printf("Tipo: %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);
            printf("Prioridade: %d\n", mochila[meio].prioridade);
            encontrado = true;
            break;
        } else if (cmp < 0) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado!\n");
    }
    pausa();
}

int main() {
    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                ordenarPorNomeFuncao();
                break;
            case 5:
                buscaBinariaPorNome();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                pausa();
        }

    } while(opcao != 6);

    return 0;
}
