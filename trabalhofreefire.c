#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10  // capacidade máxima da mochila

// ======================================================
// Definição da struct Item
// Representa um item na mochila com nome, tipo e quantidade
// ======================================================
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// ======================================================
// Declaração das funções
// ======================================================
void inserirItem(Item mochila[], int *qtd);
void removerItem(Item mochila[], int *qtd);
void listarItens(Item mochila[], int qtd);
void buscarItem(Item mochila[], int qtd);

// ======================================================
// Função principal
// ======================================================
int main() {
    Item mochila[MAX_ITENS];
    int qtd = 0; // quantidade atual de itens
    int opcao;

    do {
        printf("\n====== MENU MOCHILA ======\n");
        printf("1. Cadastrar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("===========================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                inserirItem(mochila, &qtd);
                listarItens(mochila, qtd);
                break;
            case 2:
                removerItem(mochila, &qtd);
                listarItens(mochila, qtd);
                break;
            case 3:
                listarItens(mochila, qtd);
                break;
            case 4:
                buscarItem(mochila, qtd);
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// ======================================================
// Função: inserirItem
// Objetivo: cadastra um novo item na mochila (até 10 itens)
// ======================================================
void inserirItem(Item mochila[], int *qtd) {
    if (*qtd >= MAX_ITENS) {
        printf("\nA mochila esta cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\n--- Cadastro de Item ---\n");
    printf("Nome: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // remove o '\n'

    printf("Tipo (ex: arma, municao, cura): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar(); // limpa o buffer

    mochila[*qtd] = novo;
    (*qtd)++;

    printf("\nItem '%s' adicionado com sucesso!\n", novo.nome);
}

// ======================================================
// Função: removerItem
// Objetivo: remove um item da mochila pelo nome
// ======================================================
void removerItem(Item mochila[], int *qtd) {
    if (*qtd == 0) {
        printf("\nA mochila esta vazia!\n");
        return;
    }

    char nomeRemover[30];
    printf("\nDigite o nome do item que deseja remover: ");
    fgets(nomeRemover, sizeof(nomeRemover), stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    for (int i = 0; i < *qtd; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            // Desloca os itens para preencher o espaço
            for (int j = i; j < *qtd - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*qtd)--;
            printf("\nItem '%s' removido com sucesso!\n", nomeRemover);
            return;
        }
    }

    printf("\nItem nao encontrado!\n");
}

// ======================================================
// Função: listarItens
// Objetivo: exibe todos os itens cadastrados
// ======================================================
void listarItens(Item mochila[], int qtd) {
    if (qtd == 0) {
        printf("\nA mochila esta vazia!\n");
        return;
    }

    printf("\n--- Itens na mochila ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n", 
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// ======================================================
// Função: buscarItem
// Objetivo: faz uma busca sequencial pelo nome do item
// ======================================================
void buscarItem(Item mochila[], int qtd) {
    if (qtd == 0) {
        printf("\nA mochila esta vazia!\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < qtd; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n", 
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("\nItem '%s' nao encontrado!\n", nomeBusca);
}
