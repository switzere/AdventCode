//This one will turn all inputs into vectors
//Those vectors will have a start x,y and a end x,y

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../helper.c"

typedef struct vector{
  int sX,sY,eX,eY;
}vector;


int intersect(vector A, vector B){

  /*if( A.sY >= B.sY && A.eY <= B.sY ){
    if( B.sX >= A.sX && B.eX <= A.sX){
      printf("intersect??\n");
    }
  }*/

  if( (B.sX >= A.sX && B.eX <= A.sX) || (B.sX <= A.sX && B.eX >= A.sX)){
    //printf("Inside horizontal boundaries\n");
    if( (A.sY >= B.sY && A.eY <= B.sY) || (A.sY <= B.sY && A.eY >= B.sY)){
      printf("Overlap at:\n");
      printf("sX: %d, sY: %d,      eX: %d, eY: %d\n",A.sX,A.sY,A.eX,A.eY);
      printf("sX: %d, sY: %d,      eX: %d, eY: %d\n",B.sX,B.sY,B.eX,B.eY);
      //a's X b's Y
      return abs(A.sX - 1000) + abs(B.sY - 1000);
    }
  }

  if( (A.sX >= B.sX && A.eX <= B.sX) || (A.sX <= B.sX && A.eX >= B.sX)){
    //printf("Inside horizontal boundaries\n");
    if( (B.sY >= A.sY && B.eY <= A.sY) || (B.sY <= A.sY && B.eY >= A.sY)){
      printf("Overlap at:\n");
      printf("sX: %d, sY: %d,      eX: %d, eY: %d\n",A.sX,A.sY,A.eX,A.eY);
      printf("sX: %d, sY: %d,      eX: %d, eY: %d\n",B.sX,B.sY,B.eX,B.eY);
      //b's X a's Y
      return abs(B.sX - 1000) + abs(A.sY - 1000);
    }
  }

  return -1;
}

int main(){
  char** inputLines;
  char** lineA;
  int lineASize;
  char** lineB;
  int lineBSize;
  int numLines = 0;

  int horPosA = 1000;
  int vertPosA = 1000;
  int horPosB = 1000;
  int vertPosB = 1000;

  int distance = -1;
  int lowestDistance = -1;

  char tempNum[10];
  int addNum = 0;


  numLines = readFile(&inputLines, "D3.txt");

  /*for(int i = 0; i < numLines; i++){
    printf("%s\n",inputLines[i]);
  }

  printf("\n\n");*/

  lineASize = strsplt(1, &lineA, inputLines[0], ',');
  vector* vA = malloc(sizeof(vector)*lineASize);

  //Set up A's vectors
  for(int i = 0; i < lineASize; i++){

   strncpy(tempNum, lineA[i] + 1, strlen(lineA[i]) - 1);
    tempNum[strlen(lineA[i])-1] = '\0';
    addNum = atoi(tempNum);

    if(lineA[i][0] == 'U'){

      vA[i].sX = horPosA;
      vA[i].sY = vertPosA;

      vertPosA += addNum;

      vA[i].eX = horPosA;
      vA[i].eY = vertPosA;

    }
    else if(lineA[i][0] == 'R'){

      vA[i].sX = horPosA;
      vA[i].sY = vertPosA;

      horPosA += addNum;

      vA[i].eX = horPosA;
      vA[i].eY = vertPosA;

    }
    else if(lineA[i][0] == 'D'){

      vA[i].sX = horPosA;
      vA[i].sY = vertPosA;

      vertPosA -= addNum;

      vA[i].eX = horPosA;
      vA[i].eY = vertPosA;

    }
    else if(lineA[i][0] == 'L'){

      vA[i].sX = horPosA;
      vA[i].sY = vertPosA;

      horPosA -= addNum;

      vA[i].eX = horPosA;
      vA[i].eY = vertPosA;

    }
  }



  //Set up B's vectors
  lineBSize = strsplt(1, &lineB, inputLines[1], ',');
  vector* vB = malloc(sizeof(vector)*lineBSize);

  //Set up vectors
  for(int i = 0; i < lineBSize; i++){

    strncpy(tempNum, lineB[i] + 1, strlen(lineB[i]) - 1);
    tempNum[strlen(lineB[i])-1] = '\0';
    addNum = atoi(tempNum);

    if(lineB[i][0] == 'U'){

      vB[i].sX = horPosB;
      vB[i].sY = vertPosB;

      vertPosB += addNum;

      vB[i].eX = horPosB;
      vB[i].eY = vertPosB;

    }
    else if(lineB[i][0] == 'R'){

      vB[i].sX = horPosB;
      vB[i].sY = vertPosB;

      horPosB += addNum;

      vB[i].eX = horPosB;
      vB[i].eY = vertPosB;

    }
    else if(lineB[i][0] == 'D'){

      vB[i].sX = horPosB;
      vB[i].sY = vertPosB;

      vertPosB -= addNum;

      vB[i].eX = horPosB;
      vB[i].eY = vertPosB;

    }
    else if(lineB[i][0] == 'L'){

      vB[i].sX = horPosB;
      vB[i].sY = vertPosB;

      horPosB -= addNum;

      vB[i].eX = horPosB;
      vB[i].eY = vertPosB;

    }

  }



  for(int i = 0; i < lineASize; i++){
    //printf("A VECTOR:    sX: %d, sY: %d,      eX: %d, eY: %d\n",vA[i].sX,vA[i].sY,vA[i].eX,vA[i].eY);

    for(int j = 0; j < lineBSize; j++){
      //printf("B VECTOR:     sX: %d, sY: %d,      eX: %d, eY: %d\n",vB[j].sX,vB[j].sY,vB[j].eX,vB[j].eY);

      distance = intersect(vA[i], vB[j]);
      if(distance > 0){
        printf("Distance: %d\n",distance);
        if(distance < lowestDistance || lowestDistance == -1){
          lowestDistance = distance;
        }
      }

    }
  }

  printf("Closest Distance: %d\n", lowestDistance);


}
