#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int dispSolution (int solution[], int size) {
   int k;
   if (solution[size] == 1)
      k = 1;
   else
      k = dispSolution (solution, solution[size]-1) + 1;
   cout << "Line number "<< k << ": Word Number: " <<solution[size]<<" to "<< size << endl;
   return k;
}

void wordWrap(int wordLenArr[], int size, int maxWidth) {
   int extraSpace[size+1][size+1];
   int lineCost[size+1][size+1];
   int totalCost[size+1];
   int solution[size+1];

   for(int i = 1; i<=size; i++) {    //find extra space for all lines
      extraSpace[i][i] = maxWidth - wordLenArr[i-1];

      for(int j = i+1; j<=size; j++) {    //extra space when word i to j are in single line
         extraSpace[i][j] = extraSpace[i][j-1] - wordLenArr[j-1] - 1;
      }
   }

   for (int i = 1; i <= size; i++) {    //find line cost for previously created extra spaces array

      for (int j = i; j <= size; j++) {

         if (extraSpace[i][j] < 0)
            lineCost[i][j] = INT_MAX;
         else if (j == size && extraSpace[i][j] >= 0)
            lineCost[i][j] = 0;
         else
            lineCost[i][j] = extraSpace[i][j]*extraSpace[i][j];
      }
   }

   totalCost[0] = 0;
   for (int j = 1; j <= size; j++) {    //find minimum cost for words
      totalCost[j] = INT_MAX;

      for (int i = 1; i <= j; i++) {
         if (totalCost[i-1] != INT_MAX && lineCost[i][j] != INT_MAX && (totalCost[i-1] + lineCost[i][j] < totalCost[j])){
            totalCost[j] = totalCost[i-1] + lineCost[i][j];
            solution[j] = i;
         }
      }
   }

   dispSolution(solution, size);
}

main() {
   int n = 84;
   int wordLenArr[n];
   for(int i=0; i<n; i++){
       cin>>wordLenArr[i];
   }
   int maxWidth = 6;
   wordWrap (wordLenArr, n, maxWidth);
}