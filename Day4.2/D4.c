//This one will turn all inputs into vectors
//Those vectors will have a start x,y and a end x,y

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../helper.c"


int main(){
  int count = 0;
  int prevNum = -1;
  int dubFlag, ascFlag, justDoubleFlag;
  char num[7];


  for(int i = 138307; i < 654504; i++){
    dubFlag = 0;
    ascFlag = 0;

    sprintf(num, "%d", i);

    for(int j = 1; j < 6; j++){
      if(num[j-1] > num[j]){
        ascFlag = 1;
        break;
      }
      if(num[j-1] == num[j]){
        if(j > 1){
          if(num[j-2] != num[j-1] && num[j] != num[j+1]){
            dubFlag = 1;
          }
        }
        else if(num[j] != num[j+1]){
          dubFlag = 1;
        }
      }
    }

    if(ascFlag == 0 && dubFlag == 1){
      count++;
      printf("%s\n",num);
    }

  }



  printf("Count: %d\n",count);

}
