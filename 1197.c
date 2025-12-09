#include <stdio.h>

int main() {
    int v, t;
    
    while (scanf("%d %d", &v, &t) == 2) {
        int deslocamento = 2 * v * t;
        
        printf("%d\n", deslocamento);
    }
    
    return 0;
}