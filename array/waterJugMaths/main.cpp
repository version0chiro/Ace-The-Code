#include <bits/stdc++.h>

using namespace std;

int pour(int m,int n,int d){
    int from = m;
    int to = 0;
    int steps = 1;

    while(from!=d && to!=d){
        int temp = min(from,n-to);

        to+=temp;
        from-=temp;

        steps++;

        if(from==d || to==d){
            break;
        }

        if(from==0){
            from = m;
            steps++;
        }
        if(to ==n){
            to = 0;
            steps++;
        }
    }

    return steps;
}

int minSteps(int m, int n, int d)
{
    if (m > n)
    {
        swap(m, n);
    }

    if (d > n)
    {
        return -1;
    }

    if ((d % __gcd(n, m)) != 0)
        return -1;
    
    return min(pour(m,n,d),pour(n,m,d));
}

int main()
{
    int n = 3, m = 5, d = 4;

    printf("Minimum number of steps required is %d",
           minSteps(m, n, d));

    return 0;
}