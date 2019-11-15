#include <bits/stdc++.h>

using namespace std;
int a[1000][1000];
int main()
{
    int n;
    scanf("%d",&n);
    int temp=1;
    int i=1;while(i<=n)
    {
        if(i%2==1)
        {
             int j=1;while(j<=n)
         {
             a[j][i]=temp;
             temp++;
             j++;
         }
        }
        else
        {
            int j=n;while(j>=1)
         {
             a[j][i]=temp;
             temp++;
             j--;
         }
        }

        i++;
    }
    i=1;while(i<=n)
    {
        int j=1;while(j<=n)
        {
            if(j!=1) cout<<" ";
            cout<<a[i][j];
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}
