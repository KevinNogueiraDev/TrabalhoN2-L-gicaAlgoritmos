#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrar(int codigo[5], char nome[5][50], int *total) {
    system("clear");
    if (*total == 5) {
        printf("\nCadastro cheio!\n");
        return;
    }

    printf("Digite o código do livro: ");
    scanf("%d", &codigo[*total]); getchar();

    printf("Digite o nome do livro: ");
    fgets(nome[*total], 15, stdin);

    (*total)++;

    printf("\nCadastro realizado com sucesso!\n");
}

void consultar(int codigo[5], char nome[5][50], int total) {
    system("clear");
    int busca, encontrou = -1;

    if(total == 0) {
        printf("Não existe nenhum livro para consultar! ");
        return;
    }

    printf("-------- CONSULTA --------\n");
    printf("Digite o código do livro: ");
    scanf("%d", &busca); getchar();

    for (int c = 0; c < total; c++) {
        if (codigo[c] == busca) {
            encontrou = c;
            break;
        } 
    }
    
    if (encontrou >= 0) {
        printf("Código do livro: %d\nNome do livro: %s", codigo[encontrou], nome[encontrou]);
    } else { 
         printf("Livro não encontrado!");
    }

}

void listar(int codigo[5], char nome[5][50], int total) {
    system("clear");
    
    for (int c = 0; c < total; c++) {
        printf("-------- LIVRO %d --------\n", c + 1);
        printf("Código do livro: %d\n", codigo[c]);
        printf("Nome do livro: %s", nome[c]);
        printf("--------------------------\n\n");
    }
   

}

void alterar(int codigo[5], char nome[5][50], int total) {
    system("clear");
    int busca, encontrou = -1;

    if (total == 0) {
        printf("Não existe nenhum livro para alterar!");
    }

    printf("------ ALTERAR ------\n");
    printf("Digite o código do livro que deseja alterar: ");
    scanf("%d", &busca); getchar();

    for (int c = 0; c < total; c++) {
        if (codigo[c] == busca) {
            encontrou = c;
            break;
        }
    }

    if (encontrou >= 0) {
        system("clear");
        printf("Livro encontrado!\n");
        printf("Código do livro: %d\nNome do livro: %s\n", codigo[encontrou], nome[encontrou]);
        printf("---------------------\n");
        printf("Digite o novo código do livro: ");
        scanf("%d", &codigo[encontrou]); getchar();
        printf("Digite o novo nome do livro: ");
        fgets(nome[encontrou], 15, stdin);
    } else { 
        printf("Livro não encontrado!");
    }
}

void excluir(int codigo[5], char nome[5][50], int *total) {

    int busca, encontrou = -1, escolha;

    system("clear");

    printf("----------- EXCLUIR ----------\n");
    printf("Digite o código do livro que deseja excluir: ");
    scanf("%d", &busca); getchar();

    for (int c = 0; c < *total; c++) {
        if (codigo[c] == busca) {
            encontrou = c;
            break;
        }
    }
    
    if (encontrou == -1) {
        printf("Livro não encontrado!");
        return;
    }
    
    printf("Código do livro: %d\nNome do livro: %s", codigo[encontrou], nome[encontrou]);
    printf("Tem certeza que deseja excluir este livro?\nDigite '1' p/ SIM e '0' p/ NÃO... ");
    scanf("%d", &escolha);
    
    if (escolha == 1) {
        int p = 0;
        for (int c = encontrou; c < *total - 1; c++) {
            codigo[c] = codigo[c + 1];
            strcpy(nome[c], nome[c + 1]);
        }
        (*total)--;
        printf("Livro excluído com sucesso!");
    } else if (escolha == 0) {
        printf("Exclusão do livro: %d CANCELADA", codigo[encontrou]);
    } else {
        printf("Valor inválido!\n Exclusão do livro: %d CANCELADA", codigo[encontrou]);
    }

}

int main(void) {

    int codigo[5];
    char nome[5][50];

    int total = 0;
    int opcao;
    
    do {
        printf("\n===== MENU =====\n");
        printf("\n1 - Cadastrar");
        printf("\n2 - Consultar");
        printf("\n3 - Listar");
        printf("\n4 - Alterar");
        printf("\n5 - Excluir");
        printf("\n0 - Sair");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                cadastrar(codigo, nome, &total);
                break;

            case 2:
                consultar(codigo, nome, total);
                break;

            case 3:
                listar(codigo, nome, total);
                break;

            case 4:
                alterar(codigo, nome, total);
                break;

            case 5:
                excluir(codigo, nome, &total);
                break;

            case 0:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}