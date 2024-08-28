#include <stdio.h>  
#include <string.h>  

typedef struct {  
    char estado[50];  
    char codigo[20];  
    char nome[50];  
    int populacao;  
    float area;  
    float pib;  
    int pontos_turisticos;  
} Carta;  

float densidade_populacional(Carta carta) {  
    return carta.populacao / carta.area;  
}  

void cadastrar_carta(Carta *carta) {  
    printf("Digite o estado: ");  
    scanf("%s", carta->estado);  
    
    printf("Digite o codigo da carta: ");  
    scanf("%s", carta->codigo);  
    
    printf("Digite o nome da cidade: ");  
    scanf("%s", carta->nome);  
    
    printf("Digite a populacao: ");  
    scanf("%d", &carta->populacao);  
    
    printf("Digite a area (em km²): ");  
    scanf("%f", &carta->area);  
    
    printf("Digite o PIB (em milhoes de dolares): ");  
    scanf("%f", &carta->pib);  
    
    printf("Digite o numero de pontos turisticos: ");  
    scanf("%d", &carta->pontos_turisticos);  
}  

void comparar_cartas(Carta carta1, Carta carta2, char *atributo) {  
    if (strcmp(atributo, "populacao") == 0) {  
        if (carta1.populacao > carta2.populacao) {  
            printf("A cidade %s venceu com populacao de %d.\n", carta1.nome, carta1.populacao);  
        } else if (carta1.populacao < carta2.populacao) {  
            printf("A cidade %s venceu com populacao de %d.\n", carta2.nome, carta2.populacao);  
        } else {  
            printf("As populacoes sao iguais.\n");  
        }  

    } else if (strcmp(atributo, "area") == 0) {  
        if (carta1.area > carta2.area) {  
            printf("A cidade %s venceu com area de %.2f km².\n", carta1.nome, carta1.area);  
        } else if (carta1.area < carta2.area) {  
            printf("A cidade %s venceu com area de %.2f km².\n", carta2.nome, carta2.area);  
        } else {  
            printf("As areas sao iguais.\n");  
        }  

    } else if (strcmp(atributo, "pib") == 0) {  
        if (carta1.pib > carta2.pib) {  
            printf("A cidade %s venceu com PIB de %.2f milhoes.\n", carta1.nome, carta1.pib);  
        } else if (carta1.pib < carta2.pib) {  
            printf("A cidade %s venceu com PIB de %.2f milhoes.\n", carta2.nome, carta2.pib);  
        } else {  
            printf("Os PIBs sao iguais.\n");  
        }  

    } else if (strcmp(atributo, "densidade") == 0) {  
        float densidade1 = densidade_populacional(carta1);  
        float densidade2 = densidade_populacional(carta2);  
        if (densidade1 < densidade2) {  
            printf("A cidade %s venceu com densidade populacional de %.2f habitantes/km².\n", carta1.nome, densidade1);  
        } else if (densidade1 > densidade2) {  
            printf("A cidade %s venceu com densidade populacional de %.2f habitantes/km².\n", carta2.nome, densidade2);  
        } else {  
            printf("As densidades populacionais sao iguais.\n");  
        }  

    } else {  
        printf("Atributo invalido.\n");  
    }  
}  

int main() {  
    Carta carta1, carta2;  

    printf("Cadastro da primeira carta...\n");  
    cadastrar_carta(&carta1);  

    printf("\nCadastro da segunda carta...\n");  
    cadastrar_carta(&carta2);  

    printf("\nSobre as cartas cadastradas:\n");  
    printf("Carta 1: %s - Populacao: %d, Area: %.2f, PIB: %.2f, Densidade: %.2f habitantes/km²\n",   
           carta1.nome, carta1.populacao, carta1.area, carta1.pib, densidade_populacional(carta1));  
    printf("Carta 2: %s - Populacao: %d, Area: %.2f, PIB: %.2f, Densidade: %.2f habitantes/km²\n",   
           carta2.nome, carta2.populacao, carta2.area, carta2.pib, densidade_populacional(carta2));  

    char atributo[20];  
    printf("\nEscolha um atributo para comparar (populacao, area, pib, densidade): ");  
    scanf("%s", atributo);  

    comparar_cartas(carta1, carta2, atributo);  

    return 0;  
}
