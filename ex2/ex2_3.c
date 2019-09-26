#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float calcFunc(float x){
  return pow(x, 3) - (4 * x) - 1;
}

int main(){

  float n1, n2, n3, f1, f2, f3;
  int i, t;

  scanf("%f", &n1);
  scanf("%f", &n2);
  scanf("%i", &t);

  f1 = calcFunc(n1);
  f2 = calcFunc(n2);

  if ((f1 * f2) < 0){

    for (i = 3; i <= t; i++){
      f1 = calcFunc(n1);
      f2 = calcFunc(n2);
      n3 = ((n1 * f2) - (n2 * f1)) / (f2 - f1);
      printf("\np%i: %f\n", i, n3);
      f3 = calcFunc(n3);

      if ((f2 * f3) < 0){
        n1 = n2;
        n2 = n3;
      }
      else{
        n2 = n3;
      }
    }
    
  }
  else{
    printf("Nao ha raizes entre os dois numeros.\n");
  }

  return 0;
}
