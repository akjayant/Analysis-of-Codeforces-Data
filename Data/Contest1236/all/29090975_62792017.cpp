#include <bits/stdc++.h>
using namespace std;

int n,m,cnt;
int a[305][305];

int main(){
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        int st,v;
        if(i%2==1)st=(i-1)*n+1,v=1;
        else st=i*n,v=-1;
        for(int j=1;j<=n;j++)
        {
            a[i][j]=st;
            st+=v;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",a[j][i]);
        printf("\n");
    }

    return 0;
}
