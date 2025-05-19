#include <stdio.h>
#include <string.h>

int main() {
    char estado1[20], cidade1[20], codigo1[20];
    char estado2[20], cidade2[20], codigo2[20];

    int populacao1, populacao2;
    int pontosTuristicos1, pontosTuristicos2;
    float area1, area2, pib1, pib2;
    float densidade1, densidade2, pibPerCapita1, pibPerCapita2;

    int atributo1 = -1, atributo2 = -1;
    float valor1_a1, valor1_a2, valor2_a1, valor2_a2;
    char nomeAtributo1[50], nomeAtributo2[50];

    // Leitura carta 1
    printf("=== Carta 1 ===\n");
    printf("Estado: "); scanf("%s", estado1);
    printf("Cidade: "); scanf("%s", cidade1);
    printf("Código: "); scanf("%s", codigo1);
    printf("População: "); scanf("%d", &populacao1);
    printf("Área (km²): "); scanf("%f", &area1);
    printf("PIB: "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontosTuristicos1);

    // Leitura carta 2
    printf("\n=== Carta 2 ===\n");
    printf("Estado: "); scanf("%s", estado2);
    printf("Cidade: "); scanf("%s", cidade2);
    printf("Código: "); scanf("%s", codigo2);
    printf("População: "); scanf("%d", &populacao2);
    printf("Área (km²): "); scanf("%f", &area2);
    printf("PIB: "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontosTuristicos2);

    // Cálculos derivados
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;
    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    // Menu interativo de escolha de atributos
    do {
        printf("\nEscolha o PRIMEIRO atributo:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n6 - PIB per Capita\n> ");
        scanf("%d", &atributo1);

        printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n6 - PIB per Capita\n> ");
        scanf("%d", &atributo2);

        if (atributo1 == atributo2 || atributo1 < 1 || atributo1 > 6 || atributo2 < 1 || atributo2 > 6) {
            printf("Opções inválidas ou repetidas. Tente novamente.\n");
        }
    } while (atributo1 == atributo2 || atributo1 < 1 || atributo1 > 6 || atributo2 < 1 || atributo2 > 6);

    // Atribuir valores dos atributos selecionados para as cartas
    switch (atributo1) {
        case 1: valor1_a1 = populacao1; valor2_a1 = populacao2; strcpy(nomeAtributo1, "População"); break;
        case 2: valor1_a1 = area1; valor2_a1 = area2; strcpy(nomeAtributo1, "Área"); break;
        case 3: valor1_a1 = pib1; valor2_a1 = pib2; strcpy(nomeAtributo1, "PIB"); break;
        case 4: valor1_a1 = pontosTuristicos1; valor2_a1 = pontosTuristicos2; strcpy(nomeAtributo1, "Pontos Turísticos"); break;
        case 5: valor1_a1 = densidade1; valor2_a1 = densidade2; strcpy(nomeAtributo1, "Densidade Demográfica"); break;
        case 6: valor1_a1 = pibPerCapita1; valor2_a1 = pibPerCapita2; strcpy(nomeAtributo1, "PIB per Capita"); break;
        default: printf("Erro no atributo 1\n"); return 1;
    }

    switch (atributo2) {
        case 1: valor1_a2 = populacao1; valor2_a2 = populacao2; strcpy(nomeAtributo2, "População"); break;
        case 2: valor1_a2 = area1; valor2_a2 = area2; strcpy(nomeAtributo2, "Área"); break;
        case 3: valor1_a2 = pib1; valor2_a2 = pib2; strcpy(nomeAtributo2, "PIB"); break;
        case 4: valor1_a2 = pontosTuristicos1; valor2_a2 = pontosTuristicos2; strcpy(nomeAtributo2, "Pontos Turísticos"); break;
        case 5: valor1_a2 = densidade1; valor2_a2 = densidade2; strcpy(nomeAtributo2, "Densidade Demográfica"); break;
        case 6: valor1_a2 = pibPerCapita1; valor2_a2 = pibPerCapita2; strcpy(nomeAtributo2, "PIB per Capita"); break;
        default: printf("Erro no atributo 2\n"); return 1;
    }

    // Lógica de comparação
    int pontosCarta1 = 0, pontosCarta2 = 0;

    // Comparação do primeiro atributo
    if (atributo1 == 5) { // Densidade: menor vence
        (valor1_a1 < valor2_a1) ? pontosCarta1++ : (valor2_a1 < valor1_a1 ? pontosCarta2++ : 0);
    } else {
        (valor1_a1 > valor2_a1) ? pontosCarta1++ : (valor2_a1 > valor1_a1 ? pontosCarta2++ : 0);
    }

    // Comparação do segundo atributo
    if (atributo2 == 5) { // Densidade: menor vence
        (valor1_a2 < valor2_a2) ? pontosCarta1++ : (valor2_a2 < valor1_a2 ? pontosCarta2++ : 0);
    } else {
        (valor1_a2 > valor2_a2) ? pontosCarta1++ : (valor2_a2 > valor1_a2 ? pontosCarta2++ : 0);
    }

    float soma1 = valor1_a1 + valor1_a2;
    float soma2 = valor2_a1 + valor2_a2;

    // Resultado final
    printf("\n--- Resultado ---\n");
    printf("%s x %s\n", cidade1, cidade2);
    printf("%s: %.2f x %.2f\n", nomeAtributo1, valor1_a1, valor2_a1);
    printf("%s: %.2f x %.2f\n", nomeAtributo2, valor1_a2, valor2_a2);
    printf("Soma dos atributos: %.2f x %.2f\n", soma1, soma2);

    if (soma1 > soma2) {
        printf(" Carta vencedora: %s - %s\n", codigo1, cidade1);
    } else if (soma2 > soma1) {
        printf(" Carta vencedora: %s - %s\n", codigo2, cidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}