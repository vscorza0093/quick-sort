#include <stdio.h>
#include <stdlib.h>

void swapValues(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}


int partition(int array[], int left, int right){ 
    int pivot = array[left];    //Define o pivô baseado no valor de left, que pode ser 
    int i = left;               

    for (int j = left + 1; j <= right; j++){
        if (array[j] <= pivot){
            i++;
            swapValues((array + i), (array + j));
        }
    }
    swapValues((array + left), (array + i));

    return i;
}

void quickSort(int array[], int left, int right){
    if (left < right){
        int pivot_index = partition(array, left, right);    // Recebe o valor do pivô atual para definir os novos pivôs
        printf("Left: %d\n", left);                  
        printf("Right: %d\n", right);                         
        printf("Pivot Index: %d\n", pivot_index);
        quickSort(array, left, pivot_index - 1);            // Resolve os itens que estão à esquerda do pivô
        quickSort(array, pivot_index + 1, right);           // Resolve os itens que estão à direita do pivô
    }
}

int main() {
  // Lê os nossos dados de entrada:
  int quantidade;
  scanf("%d", &quantidade);
  int joias[quantidade];
  for (int i = 0; i < quantidade; i++) {
      scanf("%d", &joias[i]);
  }
  int left = 0;
  int right = quantidade - 1;
  // Executa o algoritmo "quickSort" para ordenar as "joias".
  quickSort(joias, left, right);
  
  //Imprime as "joias" ordenadas.
  for (int i = 0; i < quantidade; i++) {
      printf("%d ", joias[i]);
  }
  
  return 0;
}