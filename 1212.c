#include <stdio.h>

int main() {
    unsigned int valorA, valorB;
    
    while (scanf("%u %u", &valorA, &valorB) == 2) {
        if (valorA == 0 && valorB == 0) break;

        unsigned int contagem_carry = 0;
        unsigned int carry_atual = 0;

        while (valorA > 0 || valorB > 0) {
            
            unsigned int soma = (valorA % 10) + (valorB % 10) + carry_atual;

            if (soma > 9) {
                contagem_carry++;
                carry_atual = 1;
            } else {
                carry_atual = 0;
            }

            valorA /= 10;
            valorB /= 10;
        }

        if (contagem_carry == 0) {
            printf("No carry operation.\n");
        } else if (contagem_carry == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%u carry operations.\n", contagem_carry);
        }
    }

    return 0;
}
