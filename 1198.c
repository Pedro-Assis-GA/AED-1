#include <stdio.h>
#include <stdlib.h> 
int main() {
    long long int hashmat, oponente;
    while (scanf("%lld %lld", &hashmat, &oponente) != EOF) {
        printf("%lld\n", labs(hashmat - oponente));
    }
    
    return 0;
}
