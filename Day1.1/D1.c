#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
  FILE *fp;
  int mass[200];
  char buff[200];
  int iCount = 0;
  int sum = 0;

  fp = fopen("D1.txt", "r");
  while(fgets(buff, 100, fp)){
    sscanf(buff, "%d", &mass[iCount]);
    iCount++;
  }
  fclose(fp);

  for(int i = 0; i < iCount; i++){
    printf("%d\n",iCount);
    printf("%d\n", mass[i]);
    sum += floor(mass[i]/3) - 2;
  }

  printf("Sum: %d\n",sum);

  return 0;
}
