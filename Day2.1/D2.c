#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
  FILE* fp;
  char buff[500];
  char* token;

  int intcode[500];
  int result = 0;
  int iCount = 0;

  fp = fopen("D2.txt", "r");
  fgets(buff,500,fp);
  fclose(fp);

  token = strtok(buff, ",");
  while(token != NULL){
    intcode[iCount] = atoi(token);
    printf("%d, ",intcode[iCount]);
    token = strtok(NULL, ",");
    iCount++;
  }
  iCount--;

  intcode[1] = 12;
  intcode[2] = 2;

  printf("\n\n");


  for(int i = 0; i < iCount; i = i + 4){
    printf("%d %d %d %d\n",intcode[i],intcode[i+1],intcode[i+2],intcode[i+3]);
    if(intcode[i] == 1){
      result = intcode[intcode[i+1]] + intcode[intcode[i+2]];
      intcode[intcode[i+3]] = result;
    }
    else if(intcode[i] == 2){
      result = intcode[intcode[i+1]] * intcode[intcode[i+2]];
      intcode[intcode[i+3]] = result;
    }
    else if(intcode[i] == 99){
      break;
    }
    else{
      printf("Error\n");
    }
  }

  for(int i = 0; i < 12; i++){
    printf("%d, ",intcode[i]);
  }
  printf("\n");


}
