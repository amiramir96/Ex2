#include<stdio.h>
#include "my_mat.h"
// ivgeni instructions to use define if there is perm constants 
// and in this assigment we work only with 10x10 matrix so our row and col constant is 10
#define ROWANDCOL 10

int main(){

    int mat[ROWANDCOL][ROWANDCOL]; //matrix const
    
    //vars
    char letter; //for scanf input
    int num; //for A phase input
    int num1; 
    int num2;
    while (1==1){
        scanf("%c", &letter);
        //case A
        if (letter == 'A'){
            for (int i=0; i < ROWANDCOL; i++){ //edit matrix to the input val
                for (int j=0; j < ROWANDCOL; j++){
                    scanf("%d", &num);
                    if (i == j){
                        mat[i][j] = 0;
                    }
                    else {
                        mat[i][j] = num;
                    }
                }
            }
            floydWarshallAlgo(ROWANDCOL, &mat[0]); //orginize matrix via floyd-marshall algorithm
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