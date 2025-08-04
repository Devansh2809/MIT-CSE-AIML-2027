#include<stdio.h>
#include<stdlib.h>

int** MatOpr(int rows, int cols) {
  int **mat = (int **)malloc(rows * sizeof(int));
  printf("Enter the element(s) of the matrix: ");
  for (int i = 0; i < rows; i++) {
    *(mat+i) = (int *)malloc(cols * sizeof(int));
    for (int j = 0; j < cols; j++)
      scanf("%d", &mat[i][j]);
  }
  return mat;
}

void FreeMatrix(int **matrix, int rows) {
  for (int i = 0; i < rows; i++)
      free(matrix[i]);
  free(matrix);
}

void MulMat(int **a, int m1, int n1, int **b, int m2, int n2) {
  int **result = (int **)malloc(m1 * sizeof(int));
  for (int i = 0; i < m1; i++) {
    *(result+i) = (int *)malloc(n2 * sizeof(int));
      for (int j = 0; j < n2; j++) {
        *(*(result+i)+j) = 0;
          for (int k = 0; k < n1; k++)
            *(*(result+i)+j) += *(*(a+i)+k) * *(*(b+k)+j);
      }
  }
  printf("Product Matrix:\n");
  for (int i = 0; i < m1; i++) {
    for (int j = 0; j < n2; j++)
      printf("%d ", *(*(result+i)+j));
    printf("\n");
  }
  FreeMatrix(result, m1);
}

void main() {
  int m1, n1, m2, n2;
  printf("Enter the no. of rows & columns for the first matrix: ");
  scanf("%d %d", &m1, &n1);
  int **mat1 = MatOpr(m1, n1);
  printf("Enter the no. of rows & columns for the second matrix: ");
  scanf("%d %d", &m2, &n2);
  if(n1!=m2) {
    printf("Matrix multiplication not possible.\n");
    exit(0); 
  }
  int **mat2 = MatOpr(m2, n2);
  MulMat(mat1, m1, n1, mat2, m2, n2);
  FreeMatrix(mat1, m1);
  FreeMatrix(mat2, m2);
}