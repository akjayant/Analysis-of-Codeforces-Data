/*
    Mbak Rose Dong
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n,i,j,k,x,y,ans,m,q,curr,temp;
    int tc;
    cin >> tc;
    while(tc--)
    {
        scanf("%d",&n);
        string a,b;
        cin >> a >> b;
        int beda = 0;
        x = -1;
        y = -1;
        for(i=0;i<n;i++)
        {
            if(a[i] != b[i])
            {
                beda++;
                if(x == -1) x = i;
                else y = i;
            }
        }
        if(beda == 0)
            printf("Yes\n");
        else
        {
            if(beda == 2 && a[x] == a[y] && b[x] == b[y])
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}
