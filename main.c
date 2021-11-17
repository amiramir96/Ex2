#include<stdio.h>
#include "my_mat.h"

int main(){

    int rowAndCol = 10; //define num of row and col 
    int mat[rowAndCol][rowAndCol]; //matrix const
    
    //vars
    char letter; //for scanf input
    int num; //for A phase input
    int num1; 
    int num2;
    while (1==1){
        scanf("%c", &letter);
        //case A
        if (letter == 'A'){
            for (int i=0; i < rowAndCol; i++){ //edit matrix to the input val
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
            floydWarshallAlgo(rowAndCol, &mat[0]); //orginize matrix via floyd-marshall algorithm
        }
        else if (letter == 'B'){ //case B - just get the cur location from the matrix and output the ans
            scanf("%d %d", &num1, &num2);
            if (mat[num1][num2] > 0){
                printf("True");
            }
            else{
                printf("False");
            }
            printf("\n");
        }
        else if (letter == 'C'){ //case C -  just get the cur location from the matrix and output the ans
            scanf("%d %d", &num1, &num2);
            if (mat[num1][num2] > 0){
                printf("%d", mat[num1][num2]);
            }
            else{
                printf("-1");
            }
            printf("\n");
        }
        else if (letter == 'D'){//EXIT from proccess
            break;
        }
    }
}   