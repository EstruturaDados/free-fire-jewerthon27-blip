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
    int main() {
        int opcao; 

        do {
            printf("\n--- MENU PRINCIPAL ---\n");
            printf("1. Adicionar item\n");
            printf("2.Remover um item\n");
            printf("3.Listar todos os itens\n");
            printf("4.Ordenar os itens por critério (nome, tipo, prioridade)\n");
            printf("5.Realizar busca binária por nome\n");
            printf("0.Sair\n");
            printf("Escolha: ");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1:
                    printf("Opção 1: Adicionar item (não implementado)\n");
                    break;
                case 2:
                    printf("Opção 2: Removewr item (não impementado)\n");
                    break;
                case 3:
                    printf("Opção 3: Listar itens (não impementado)\n");
                    break;
                case 4:
                    printf("Opção 4: Ordenar itens (não impementado)\n");
                case 5:
                    printf("Opção 5: Buscar item (não implmentado)\n");
                    break;
                case 0:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opção inválida"\n");
            }

        } while(opcao !=0);
                    
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
// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
