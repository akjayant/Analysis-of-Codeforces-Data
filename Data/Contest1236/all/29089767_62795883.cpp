#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        int m = 1;

        for(int j = 1; j < n*n; j += n)
        {
            int x = m? j+i-1: j+n-i;
            printf("%d ", x);

            m ^= 1;
        }
        printf("\n");
    }
    return 0;
}
