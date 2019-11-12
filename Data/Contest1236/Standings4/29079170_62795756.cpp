#include<bits/stdc++.h>
using namespace std;
const int maxn=1110;
int a[maxn][maxn];
int main()
{
    int n;
    scanf("%d",&n);
    int mod=1,cnt=n*n;
    for(int i=0;i<n;i++)
    {
        if(mod) for(int j=0;j<n;j++) a[j][i]=cnt--;
        else    for(int j=n-1;j>=0;j--) a[j][i]=cnt--;
        mod=1-mod;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j) printf(" ");
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}
