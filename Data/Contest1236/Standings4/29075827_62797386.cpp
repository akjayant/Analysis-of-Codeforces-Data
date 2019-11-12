#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[400][400],i,j;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i%2)
                a[i][j]=((i-1)*n+j);
            else a[i][n-j+1]=((i-1)*n+j);
        }

    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout << a[j][i] << ' ';
        }
        cout << endl;

    }
}
