#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int ansPosA = 0;
int ansPosB = 0;

int nounverb(int a, int b, int intcode[5000], int iCount){
  int result = 0;
  intcode[1] = a;
  intcode[2] = b;

  int copyIC[5000];

  for(int i = 0; i < iCount; i++){
    copyIC[i] = intcode[i];
  }


  for(int i = 0; i < iCount; i = i + 4){
    //printf("i:%d  - %d %d %d %d\n",i,copyIC[i],copyIC[i+1],copyIC[i+2],copyIC[i+3]);
    if(copyIC[i] == 1){
      result = copyIC[copyIC[i+1]] + copyIC[copyIC[i+2]];
      copyIC[copyIC[i+3]] = result;
    }
    else if(copyIC[i] == 2){
      result = copyIC[copyIC[i+1]] * copyIC[copyIC[i+2]];
      copyIC[copyIC[i+3]] = result;
    }
    else if(copyIC[i] == 99){
      break;
    }
    else{
      break;
    }
    //printf("a:%d b:%d\n",a,b);
    //printf("copyIC[0]=%d,    %d %d %d %d\n",copyIC[0],copyIC[i],copyIC[i+1],copyIC[i+2],copyIC[i+3]);
  }

  if(copyIC[0] == 19690720){
    printf("\n\nFOUND! - %d %d\n",a,b);
    ansPosA = a;
    ansPosB = b;
    return 1;
  }


  return 0;

}

int main(){
  FILE* fp;
  char buff[500];
  char* token;

  int intcode[5000];
  int iCount = 0;
  int found = 0;

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



  printf("\n\n");



  for(int i = 0; i <= 99; i++){
    for(int j = 0; j <= 99; j++){
      found = nounverb(i, j, intcode, iCount);
    }
    if(found == 1){
      break;
    }
  }

  printf("%d %d",ansPosA,ansPosB);

}
