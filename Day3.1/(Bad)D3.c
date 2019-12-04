#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../helper.c"

int foundFlag = 0;

int wireB(int horPosA, int vertPosA, char** inputLines){

  int vertPosB = 1000;
  int horPosB = 1000;
  int lineBSize = 0;

  char** lineB;
  char tempNum[10];


  lineBSize = strsplt(1, &lineB, inputLines[1], ',');
  for(int i = 0; i < lineBSize; i++){
    //printf("%s - ",lineB[i]);
    strncpy(tempNum, lineB[i] + 1, strlen(lineB[i]) - 1);
    tempNum[strlen(lineB[i])-1] = '\0';
    //printf(" ((%d)) ",atoi(tempNum));

    if(lineB[i][0] == 'U'){

      for(int j = vertPosB; j <= (vertPosB + atoi(tempNum)); j++){
        if( j == vertPosA && horPosB == horPosA ){
          foundFlag = 1;
          printf("\n\n\n--------------------------------------\nFound!\n--------------------------------------\n");
          printf("V: %d, H: %d\n",vertPosB,horPosB);
          printf("Distance: %d", abs(vertPosB - 1000) + abs(horPosB - 1000));
        }
      }

      vertPosB += atoi(tempNum);

      //printf("V: %d, H: %d\n",vertPosB,horPosB);
    }
    else if(lineB[i][0] == 'D'){

      for(int j = vertPosB; j >= (vertPosB - atoi(tempNum)); j--){
        if( j == vertPosA && horPosB == horPosA ){
          foundFlag = 1;
          printf("\n\n\n--------------------------------------\nFound!\n--------------------------------------\n");
          printf("V: %d, H: %d\n",vertPosB,horPosB);
          printf("Distance: %d", abs(vertPosB - 1000 - 1) + abs(horPosB - 1000 - 1));
        }
      }

      vertPosB -= atoi(tempNum);

      //printf("V: %d, H: %d\n",vertPosB,horPosB);
    }
    else if(lineB[i][0] == 'R'){

      for(int j = horPosB; j <= (vertPosB + atoi(tempNum)); j++){
        if( vertPosB == vertPosA && j == horPosA ){
          foundFlag = 1;
          printf("\n\n\n--------------------------------------\nFound!\n--------------------------------------\n");
          printf("V: %d, H: %d\n",vertPosB,horPosB);
          printf("Distance: %d", abs(vertPosB - 1000) + abs(horPosB - 1000));
        }
      }

      horPosB += atoi(tempNum);

      //printf("V: %d, H: %d\n",vertPosB,horPosB);
    }
    else if(lineB[i][0] == 'L'){

      for(int j = horPosB; j >= (horPosB - atoi(tempNum)); j--){
        if( vertPosB == vertPosA && j == horPosA ){
          foundFlag = 1;
          printf("\n\n\n--------------------------------------\nFound!\n--------------------------------------\n");
          printf("V: %d, H: %d\n",vertPosB,horPosB);
          printf("Distance: %d", abs(vertPosB - 1000) + abs(horPosB - 1000));

        }
      }

      horPosB -= atoi(tempNum);

      //printf("V: %d, H: %d\n",vertPosB,horPosB);
    }



  }




}


int main(){
  char** inputLines;
  char** lineA;
  int lineASize;
  char** lineB;
  int lineBSize;
  int numLines = 0;

  //int panel[10000][10000][2];
  int horPosA = 1000;
  int vertPosA = 1000;


  char tempNum[10];


  numLines = readFile(&inputLines, "test.txt");

  /*for(int i = 0; i < numLines; i++){
    printf("%s\n",inputLines[i]);
  }

  printf("\n\n");*/

  lineASize = strsplt(1, &lineA, inputLines[0], ',');
  for(int i = 0; i < lineASize; i++){
    printf("%s - ",lineA[i]);
    strncpy(tempNum, lineA[i] + 1, strlen(lineA[i]) - 1);
    tempNum[strlen(lineA[i])-1] = '\0';
    //printf(" ((%d)) ",atoi(tempNum));

    if(lineA[i][0] == 'U'){

      for(int j = vertPosA; j <= (vertPosA + atoi(tempNum)); j++){
        wireB(horPosA, j, inputLines);
      }

      vertPosA += atoi(tempNum);

      //printf("V: %d, H: %d\n",vertPosA,horPosA);
    }
    else if(lineA[i][0] == 'D'){

      for(int j = vertPosA; j >= (vertPosA - atoi(tempNum)); j--){
        wireB(horPosA, j, inputLines);
      }

      vertPosA -= atoi(tempNum);

      //printf("V: %d, H: %d\n",vertPosA,horPosA);
    }
    else if(lineA[i][0] == 'R'){

      for(int j = horPosA; j <= (vertPosA + atoi(tempNum)); j++){
        wireB(j, vertPosA, inputLines);
      }

      horPosA += atoi(tempNum);

      //printf("V: %d, H: %d\n",vertPosA,horPosA);
    }
    else if(lineA[i][0] == 'L'){

      for(int j = horPosA; j >= (horPosA - atoi(tempNum)); j--){
        wireB(j, vertPosA, inputLines);
      }

      horPosA -= atoi(tempNum);

      //printf("V: %d, H: %d\n",vertPosA,horPosA);
    }



  }




  printf("\n");
  lineBSize = strsplt(1, &lineB, inputLines[1], ',');
  for(int i = 0; i < lineBSize; i++){
    printf("%s - ",lineB[i]);
  }





}
