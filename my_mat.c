#include<stdio.h>

void createMatrix(int n, int mat[][n]){
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            mat[i][j] = 0;
        }
    }
}

// void printMatrix(int n, int mat[][n]){
//     for (int i=0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             printf("%d ", mat[i][j]);
//         }
//         printf("\n");
//     }
// }

// void intializeMatrix(int n, int mat[][n]){
//     for (int i=0; i < n; i++){
//         for (int j=0; j < n; j++){
//             if (i == j){
//                 mat[i][j] = 0;
//             }
//             else {
//                 mat[i][j] = (int)(rand() % 10);
//             }
//         }
//     }
// }

void firstStep(int n, int prevMat[][n], int newMat[][n], int k){
    for (int i=0; i < n; i++){
        newMat[i][k] = prevMat[i][k];
        newMat[k][i] = prevMat[k][i];
    }
}

void copyMat(int n, int prevMat[][n], int newMat[][n]){
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            newMat[i][j] = prevMat[i][j];
        }
    }
}

void floydWarshallAlgo(int n, int mat[][n]){
    
    int tempMatPrev[n][n];
    copyMat(n, &mat[0], &tempMatPrev[0]);
    int tempMatNew[n][n];

    for (int k=0; k < n; k++){
        createMatrix(n, &tempMatNew[0]);
        firstStep(n ,&tempMatPrev[0], &tempMatNew[0], k);
        for (int i=0; i < n; i++){
            for (int j=0; j < n; j++){
                if (tempMatNew[i][k] != 0 && tempMatNew[k][j] != 0 && tempMatNew[i][k] + tempMatNew[k][j] < tempMatPrev[i][j]){
                    tempMatNew[i][j] = tempMatNew[i][k] + tempMatNew[k][j];
                }
                else {
                    tempMatNew[i][j] = tempMatPrev[i][j];
                }
            }
        }
        copyMat(n, &tempMatNew[0], &tempMatPrev[0]);
    }
    
    copyMat(n, &tempMatNew[0], &mat[0]);
}