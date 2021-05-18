#include <bits/stdc++.h>

using namespace std;

void printSolution(int sol[][],int n){
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            cout<<" "<<setw(2)<<sol[x][y]<<" ";
        }
        cout<<"\n";
    }    
}

int solveKT(int n)
{
    int sol[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = -1;
        }
    }

    int yMoves[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int xMoves[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    sol[0][0] = 0;

    if (solveKTUtil(0, 0, 1, sol, yMoves, xMoves) == 0)
    {
        cout << "not possible";
        return 0;
    }
    else
    {
        printSolution(sol);
    }

    return 1;
}
int solveKTUtil(int x,int y,int movei,int sol[n][n])
int main()
{

    int n;
    cin >> n;
    solveKT(n);

    return 0;
}