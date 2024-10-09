#include <stdio.h>
#include <stdlib.h>

int LerInt(){
  int numLido;
  scanf("%d", &numLido);

  return numLido;
}

int **CriaMatDinamica(int numLinha, int numColuna){
  int contl;
  int **mat = (int **)malloc(numLinha * sizeof(int *));
  
  if(mat==NULL){
      printf("memoria insuficiente");

      exit(1);
    }
  
  for(contl=0; contl<numLinha; contl++){
    mat[contl] = (int *) malloc(numColuna * sizeof(int));

    if(mat[contl]==NULL){
      printf("memoria insuficiente");

      exit(1);
    }
  }

  return mat;
}

void LiberaMatDinamica(int **mat, int numLinha){
  int contl;

  for(contl=0; contl<numLinha; contl++){
    free(mat[contl]);
  }

  free(mat);
}

void CalculaArranjo(int numLinha, int numColuna){
  int contl, contc;
  int **mat = CriaMatDinamica(numLinha, numColuna);

  for(contl=0; contl<numLinha; contl++){
    for(contc=0; contc<numColuna; contc++){
      if(contc==0 || contl==contc) mat[contl][contc] = 1;
      else if(contc<contl) mat[contl][contc] = mat[contl-1][contc] + mat[contl-1][contc-1];
      else mat[contl][contc] = 0;
    }
  }

  printf("%d\n", mat[numLinha-1][numColuna-1]);

  LiberaMatDinamica(mat, numLinha);
}

int main(){
  int numLinha, numColuna;

  while(numLinha = 1 + LerInt(), numColuna = 1 + LerInt(), (numColuna-1)!=0 && (numLinha-1)!=0){
    CalculaArranjo(numLinha, numColuna);
  }
  
  return 0;  
}
