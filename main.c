#include<stdio.h>
#include "my_mat.h"

int main(){
    int rowAndCol = 10;
    int mat[rowAndCol][rowAndCol];
    int num;
    int num1;
    int num2;
    char letter;
    while (1==1){
        scanf("%c", &letter);
        if (letter == 'A'){
            for (int i=0; i < rowAndCol; i++){
                for (int j=0; j < rowAndCol; j++){
                    scanf("%d", &num);
                    if (i == j){
                        mat[i][j] = 0;
                    }
                    else {
                        mat[i][j] = num;
                    }
                }
            }
            floydWarshallAlgo(rowAndCol, &mat[0]);
        }
        else if (letter == 'B'){
            scanf("%d %d", &num1, &num2);
            if (mat[num1][num2] > 0){
                printf("True");
            }
            else{
                printf("False");
            }
            printf("\n");
        }
        else if (letter == 'C'){
            scanf("%d %d", &num1, &num2);
            if (mat[num1][num2] > 0){
                printf("%d", mat[num1][num2]);
            }
            else{
                printf("-1");
            }
            printf("\n");
        }
        else if (letter == 'D'){
            break;
        }
    }
}   