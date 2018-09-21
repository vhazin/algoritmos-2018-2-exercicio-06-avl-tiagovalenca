#include <stdio.h>

void check(int a[], int numeros);

int main(void) {
  int casos, numeros;

  scanf("%d", &casos);

  while(casos--){
    scanf("%d", &numeros);
    int tree[numeros];

    for(int i = 0; i < numeros; i++){
      scanf("%d", &tree[i]);
    }

    check(tree, numeros);
  }
  return 0;
}

void check(int a[], int numeros){
  int altura[numeros];

  for(int i = 0; i < numeros; i++){
    altura[i] = 0;
  }

  int flag = 1;

  for(int j = numeros -1; j >= 0; j--){
    int direita = 2*j+2;
    int esquerda = 2*j+1;

    if(a[j] != -1){
      if(direita < numeros){

        if(altura[esquerda] >= altura[direita]){
          altura[j] = altura[esquerda] + 1;
        }else{
          altura[j] = altura[direita] + 1;
        }

        if(altura[esquerda] - altura[direita] > 1 || altura[direita] - altura[esquerda] > 1){
          flag = 0;
          break;
        }
      }else{
        if(esquerda < numeros){
          altura[j] = 1 + altura[esquerda];
        }else{
          altura[j] = 1;
        }
      }
    }
  }

  if(flag){
    printf("T\n");
  }else{
    printf("F\n");
  }
}
