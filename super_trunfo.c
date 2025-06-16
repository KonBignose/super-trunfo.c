
#include <stdio.h>
#include <string.h>

// Função para exibir os atributos disponíveis
void mostrarMenu(int excluir) {
    printf("\nEscolha um atributo para comparação:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");
}

int main() {
    // Dados da Carta 1
    char pais1[50] = "Brasil";
    int populacao1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 2000.5;  // em bilhões
    int pontos1 = 15;
    float densidade1 = populacao1 / area1;

    // Dados da Carta 2
    char pais2[50] = "Argentina";
    int populacao2 = 45300000;
    float area2 = 2780000.0;
    float pib2 = 500.75;
    int pontos2 = 12;
    float densidade2 = populacao2 / area2;

    int escolha1, escolha2;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    // Escolha do primeiro atributo
    mostrarMenu(0);
    printf("Digite a opção do primeiro atributo: ");
    scanf("%d", &escolha1);

    // Validação do primeiro atributo
    if (escolha1 < 1 || escolha1 > 5) {
        printf("Atributo inválido!\n");
        return 1;
    }

    // Escolha do segundo atributo (sem repetir)
    mostrarMenu(escolha1);
    printf("Digite a opção do segundo atributo (diferente da primeira): ");
    scanf("%d", &escolha2);

    // Validação do segundo atributo
    if (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        printf("Atributo inválido ou repetido!\n");
        return 1;
    }

    // Mapeando valores do primeiro atributo
    switch (escolha1) {
        case 1: valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
        case 2: valor1_carta1 = area1; valor1_carta2 = area2; break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: valor1_carta1 = pontos1; valor1_carta2 = pontos2; break;
        case 5: valor1_carta1 = densidade1; valor1_carta2 = densidade2; break;
        default: printf("Erro interno\n"); return 1;
    }

    // Mapeando valores do segundo atributo
    switch (escolha2) {
        case 1: valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
        case 2: valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: valor2_carta1 = pontos1; valor2_carta2 = pontos2; break;
        case 5: valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
        default: printf("Erro interno\n"); return 1;
    }

    // Comparação do primeiro atributo
    printf("\n--- Comparação do Primeiro Atributo ---\n");
    switch (escolha1) {
        case 1: printf("População:\n"); break;
        case 2: printf("Área:\n"); break;
        case 3: printf("PIB:\n"); break;
        case 4: printf("Pontos Turísticos:\n"); break;
        case 5: printf("Densidade Demográfica:\n"); break;
    }
    printf("%s: %.2f\n", pais1, valor1_carta1);
    printf("%s: %.2f\n", pais2, valor1_carta2);

    // Exibe vencedor do atributo 1
    if (escolha1 == 5) {
        printf("Vencedor: %s\n", (valor1_carta1 < valor1_carta2) ? pais1 : (valor1_carta2 < valor1_carta1 ? pais2 : "Empate!"));
    } else {
        printf("Vencedor: %s\n", (valor1_carta1 > valor1_carta2) ? pais1 : (valor1_carta2 > valor1_carta1 ? pais2 : "Empate!"));
    }

    // Comparação do segundo atributo
    printf("\n--- Comparação do Segundo Atributo ---\n");
    switch (escolha2) {
        case 1: printf("População:\n"); break;
        case 2: printf("Área:\n"); break;
        case 3: printf("PIB:\n"); break;
        case 4: printf("Pontos Turísticos:\n"); break;
        case 5: printf("Densidade Demográfica:\n"); break;
    }
    printf("%s: %.2f\n", pais1, valor2_carta1);
    printf("%s: %.2f\n", pais2, valor2_carta2);

    // Exibe vencedor do atributo 2
    if (escolha2 == 5) {
        printf("Vencedor: %s\n", (valor2_carta1 < valor2_carta2) ? pais1 : (valor2_carta2 < valor2_carta1 ? pais2 : "Empate!"));
    } else {
        printf("Vencedor: %s\n", (valor2_carta1 > valor2_carta2) ? pais1 : (valor2_carta2 > valor2_carta1 ? pais2 : "Empate!"));
    }

    // Soma dos atributos (Densidade invertida: usamos inverso para somar corretamente)
    float soma1 = (escolha1 == 5 ? (1 / valor1_carta1) : valor1_carta1) + (escolha2 == 5 ? (1 / valor2_carta1) : valor2_carta1);
    float soma2 = (escolha1 == 5 ? (1 / valor1_carta2) : valor1_carta2) + (escolha2 == 5 ? (1 / valor2_carta2) : valor2_carta2);

    printf("\n--- Resultado Final ---\n");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", pais1, soma1);
    printf("%s: %.2f\n", pais2, soma2);

    if (soma1 > soma2) {
        printf("Vencedor da Rodada: %s\n", pais1);
    } else if (soma2 > soma1) {
        printf("Vencedor da Rodada: %s\n", pais2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
