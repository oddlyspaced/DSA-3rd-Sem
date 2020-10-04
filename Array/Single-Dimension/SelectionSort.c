#include <stdio.h>
#include<stdlib.h>
int main() {
    int size;
	printf("Enter size of array:\n");
	scanf("%d", &size);
	int *p;
	p = (int*)malloc(size*sizeof(int));
	printf("Enter values:\n");
    
    int i, j;
    for (i = 0; i < size; i++) {
        scanf("%d", &p[i]);
    }
    printf("\n");
    for (i = 0; i < size; i++) {
        printf("%d", p[i]);
    }

    for (i = 0; i < (size - 1); i++) {
      for (j = i + 1; j < size; j++) {
          if (p[i] > p[j]) {
              int t = p[i];
              p[i] = p[j];
              p[j] = t;
            }
        }
    }
    printf("\n");
    for (i = 0; i < size; i++) {
        printf("%d", p[i]);
    }
    free(p);
}