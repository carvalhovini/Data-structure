#include <stdio.h>

int primo(int num)
{
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0){
            return 0;
        }
    }
    
    return 1;

}

int main(){
    int numero;
    
    printf("digite o numero: \n");
    scanf("%d", &numero);
    
    if(primo(numero)){
        printf("%d e um numero primo");
    } else {
        printf("%d não e um numero primo");
    }
}