#include <stdio.h>

// Declaração das funções
void menu_msg();
int capturar_numero();
int soma(int a, int b);
int subtracao(int a, int b);
int multiplicacao(int a, int b);
float divisao(int a, int b);

int main() {
    char op;
    int num1, num2;

    do {
        // Exibir menu
        menu_msg();
        op = getchar();
        
        // Limpar o buffer após capturar a opção
        while (getchar() != '\n');

        if (op != '+' && op != '-' && op != '*' && op != '/') {
            puts("====================");
            printf("<OPCAO INVALIDA>\n");
            puts("====================");
            continue;
        }

        // Capturar números
        printf("Digite o primeiro número: ");
        num1 = capturar_numero();

        printf("Digite o segundo número: ");
        num2 = capturar_numero();

        // Realizar a operação com base na escolha do usuário
        switch (op) {
            case '+':
                printf("Resultado: %d\n", soma(num1, num2));
                break;
            case '-':
                printf("Resultado: %d\n", subtracao(num1, num2));
                break;
            case '*':
                printf("Resultado: %d\n", multiplicacao(num1, num2));
                break;
            case '/':
                if (num2 == 0) {
                    printf("Erro: Divisão por zero!\n");
                } else {
                    printf("Resultado: %.2f\n", divisao(num1, num2));
                }
                break;
        }

        // Pergunta para repetir ou encerrar
        printf("Deseja realizar outra operação? (S/N): ");
        op = getchar();
        
        // Limpar o buffer após capturar a resposta
        while (getchar() != '\n');

    } while (op == 'S' || op == 's');

    printf("Programa encerrado.\n");
    return 0;
}

// Função para exibir o menu
void menu_msg() {
    puts("====================");
    puts("Escolha uma operação:");
    puts("+ : Soma");
    puts("- : Subtração");
    puts("* : Multiplicação");
    puts("/ : Divisão");
    puts("====================");
    printf("Opção: ");
}

// Função para capturar número inteiro
int capturar_numero() {
    int num;
    while (scanf("%d", &num) != 1) {
        printf("Entrada inválida! Por favor, insira um número inteiro: ");
        
        // Limpar buffer
        while (getchar() != '\n');
    }
    // Limpar buffer após capturar o número
    while (getchar() != '\n');
    return num;
}

// Funções de operações
int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a * b;
}

float divisao(int a, int b) {
    return (float)a / b;
}