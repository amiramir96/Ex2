#include<stdio.h>

//edit matrix size n*n to be whole zero values
void createMatrix(int n, int mat[][n]){
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            mat[i][j] = 0;
        }
    }
}

void printMatrix(int n, int mat[][n]){
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            printf ("%d", mat[i][j]);
        }
        printf("\n");
    } 
}

//does initilize the new mat to hold the values of row and col of the 'k' node of the graph
void firstStep(int n, int prevMat[][n], int newMat[][n], int k){
    for (int i=0; i < n; i++){
        newMat[i][k] = prevMat[i][k];
        newMat[k][i] = prevMat[k][i];
    }
}

//copy all vals of prevMat to the newMat
void copyMat(int n, int prevMat[][n], int newMat[][n]){
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            newMat[i][j] = prevMat[i][j];
        }
    }
}

//main algo proccess - in the end of the function - the input matrix hold the shortest path between nodes i to j of the graph
void floydWarshallAlgo(int n, int mat[][n]){
    //initialize phase - two matrixes
    int tempMatPrev[n][n];
    copyMat(n, &mat[0], &tempMatPrev[0]);
    int tempMatNew[n][n];

    //three loops of n iterates - O(n^3) 
    for (int k=0; k < n; k++){
        createMatrix(n, &tempMatNew[0]);
        firstStep(n ,&tempMatPrev[0], &tempMatNew[0], k);
        for (int i=0; i < n; i++){
            for (int j=0; j < n; j++){
                //edit new value for a path between i to j IF and only IF the new suggested path is exists (no zero vals)
                //and is smaller from prev path OR the prev valu is 0 (non exist path) - then any existing path is better!
                if (tempMatNew[i][k] != 0 && tempMatNew[k][j] != 0 && tempMatNew[i][k] + tempMatNew[k][j] < tempMatPrev[i][j]){
                    tempMatNew[i][j] = tempMatNew[i][k] + tempMatNew[k][j];
                }
                // else if (tempMatNew[i][k] != 0 && tempMatNew[k][j] != 0 && tempMatPrev[i][j] == 0) {
                //     tempMatNew[i][j] = tempMatNew[i][k] + tempMatNew[k][j];

                // }
                else {
                    tempMatNew[i][j] = tempMatPrev[i][j];
                }
            }
        }
        //switch - prevmat is now the last new mat so we will be able to work again on the next step
        copyMat(n, &tempMatNew[0], &tempMatPrev[0]);
    }
    //copy values from the temporary matrix to the origin input matrix and we done! :-)    
    copyMat(n, &tempMatNew[0], &mat[0]);
}