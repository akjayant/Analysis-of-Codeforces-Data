#include <bits/stdc++.h>
using namespace std;
int nn;
int a[501][501];
int F[20002];

int main()
{
    cin>>nn;
     for (int i=1;i<=110;i++) F[i] += 2;
    for (int i=1;i<=110;i++) F[i] += 3;
    for (int i=1;i<=110;i++) F[i] += 4;
    for (int i=1;i<=110;i++) F[i] += 4;
    for (int i=1;i<=nn;i++)
    {
        if ( i%2 == 0 )
        for (int j=1;j<=nn;j++) a[j][i] = (i-1)*nn + nn- j + 1 ;
        else
        for (int j=1;j<=nn;j++) a[j][i] = (i-1)*nn + j ;

    }

     for (int i=1;i<=110;i++) F[i] += 2;
    for (int i=1;i<=110;i++) F[i] += 3;
    for (int i=1;i<=110;i++) F[i] += 4;
    for (int i=1;i<=110;i++) F[i] += 4;

    for (int i=1;i<=nn;i++)
        {
        for (int j=1;j<=nn;j++) cout<<a[i][j]<<" ";
        cout<<"\n";
        }

    return 0;
}
