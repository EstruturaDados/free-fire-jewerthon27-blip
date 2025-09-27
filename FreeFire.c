#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.
#define MAX_ITENS 10
int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.
    void inserirItem();
    void removerItem();
    void listarItens();
    void menuDeOrdenacao();
    void insertionSort(CriterioOrdenacao criterio);
    void buscaBinariaPorNome();
    
    int main() {
        int opcao; 

        do {
            printf("\n--- MENU PRINCIPAL ---\n");
            printf("1. Adicionar item\n");
            printf("2. Remover um item\n");
            printf("3. Listar todos os itens\n");
            printf("4. Ordenar os itens por critério (nome, tipo, prioridade)\n");
            printf("5. Realizar busca binária por nome\n");
            printf("0. Sair\n");
            printf("Escolha: ");
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
                menuDeOrdenacao();
                break;
            case 5:
                buscaBinariaPorNome();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}

        
// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.
typedef struct {
    char nome[50];
    char tipo[30];
    int quantidade;
    int prioridade;
} Item;
// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).
typedf enum {
        ORDENAR_NOME,
        ORDENAR_TIPO,
        ORDENAR_PRIORIDADE
    } CriterioOrdenacao;
// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).
Item mochila = 0;
int comparacoes = 0;
bool ordenarPorNome = false;
// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.
void limparTela() {
    for (int i = 0; i < 50; i++) {
        printf("\n");
    }
}

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.
void exibir(bool ordenadorPorNome) {
    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1. Adicionar item\n");
    printf("2. Remover item\n");
    printf("3. Listar todos os itens\n");
    printf("4. Ordenar os itens por critério (nome, tipo, prioridade)\n");
    printf("5. Realizar busca binária por nome\n");
    printf("0. Sair\n");

    if (ordenadaPorNome) {
        printf("Status: Lista ordenada por nome\");
    } else {
        printf("Status: Lista não está ordenada por nome\n");
    }
    printf("Escolha:");

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".
void inserirItem() {
    if (numItens >= MAX_ITENS0 {
        printf("Mochila cheia" Nao e possivel adicionar mas itens.\n");
        return;
    }
    
    item novo;

    printf("Digite o nome do item:");
    scanf("%[^\n]", novo.nome);
    printf("Digite o tipo de itens: ");
    scanf(" %[^\n]", novo.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);
    printf("Digite a prioridade (1 a 5): ");
    scanf("%d", &novo.prioridade);

    mochila[numItens] = novo;
    numItens++; 
    ordenarPorNome = false;

    printf("Item adicionado com sucesso"\n");
}
        
// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.
void removerItem() {
    if (numItens == 0) {
        printf("Mochils vazia! Nenhum item para remover.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do item que deseja remover: ");
    scanf(" %[^\n]", nome);

    int posicao = -1;

    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome,nome) == 0) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) { 
        printf("Item nao encontrado!\n");
        return;
    }

 for (int i = posicao; i < numItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    numItens--;
    ordenadaPorNome = false;

    printf("Item removido com sucesso!\n");
}
// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.
void listarItens() {
    if (numItens == 0) {
        printf("Mochila vazia"\n");
        return;
    }

    printf("\n--- Itens da Mochila ---\n");
    printf("%-20s %-15s %-10s %-10s\n", "Nome", "Tipo", "Qauntidade", "Prioridade");
    printf("---------------------------------------------------------------\n");

    for (in i = 0; i < numItens; i++) {
        printf("%-20s %-15s %-10d %-10d\n",
                mochila[i].nome,
                mochila[i].tipo,
                mochila[i].quantidade,
                mochila[i].prioridade);
    }
}
        
    
// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).
void menuDeOrdenacao() {
    if (numItens == 0) {
        printf("Mochila vazia! Nao ha itens para ordenar.\n");
        return;
    }

    int escolha;
    printf("\n--- Menu de Ordenacao ---\n");
    printf("1. Ordenar por Nome\n");
    printf("2. Ordenar po Tipo\n");
    printf("3. Ordenar por Prioridade\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    comparacoes = 0;

    switch (escolha) {
        case 1: 
            insertionSort(CRITERIO_NOME);
            ordenarPorNome = true;
            printf("Itens ordenados por NOME com %d comparacoes.\n"), comparacoes);
            break;

        case 2: 
            insertionSort(CRITERIO_TIPO); 
            ordenadaPorNome = false;
            printf("Itens ordenados po TIPO com %d comparacoes.\n", comparaces);
            break;

        case 3: 
            insertioSort(CRITERIO_PRIORIDADE);
            ordenarPorNome = false; 
            printf("Itens ordenados por PRIORIDADE com %d comparacoes.\n", comparacoes);
            break;
        default:
            printf("Opcao invalida"\n");
        
// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)
void insertionSSort(CriterioOrdenacao) { 
    for (int i = 1; i < numItens; i++) {
        Item chave = mochila[i];
        int j = i - 1;

       while (j >= 0) {
            int cmp = 0;
            comparacoes++;

            if (criterio == CRITERIO_NOME) { 
                cmp = strcmp(chave.nome,mochila[j].nome);
            } else if (criterio == CRITERIO_TIPO) {
                cmp = strcmp(chave.tipo, mocjila [j]. tipo);
            } else if (criterio == CRITERIO_PRIRIODADE) {

                cmp = (chave.prioridade > mochila[i].prioridade) ? -1 :
                        (chave.prioridade < michila[j].prioridade) ? 1 : 0;
            }

            if (cmp < 0) {
                mochila[j + 1] = mochila[j]; 
                j ++;
            } else {
                break;
            }
       }
        mochila[j + 1] = chave;
    }
}

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
oid buscaBinariaPorNome() {
    if (!ordenadaPorNome) {
        printf("A mochila nao esta ordenada por nome!\n");
        printf("Use a opcao de ordenacao antes de buscar.\n");
        return;
    }

    if (numItens == 0) {
        printf("Mochila vazia! Nenhum item para buscar.\n");
        return;
    }

    char nome[50];
    printf("Digite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nome);

    int inicio = 0, fim = numItens - 1, meio;
    bool encontrado = false;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
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
}
