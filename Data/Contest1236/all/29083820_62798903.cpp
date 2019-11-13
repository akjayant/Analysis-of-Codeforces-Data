#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define NMAX 200005
using namespace std;
typedef long long ll;
int a[305][305], n, m, i, j, k;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
}

int main()
{
    fast();
    cin>>n;
    for(j=1;j<=n;j++)
    {
        if(j%2)
            for(i=1;i<=n;i++)
        {
            k++;
            a[i][j]=k;
        }
        else for(i=n;i>=1;i--)
        {
            k++;
            a[i][j]=k;
        }
    }
    for(i=1;i<=n;i++,cout<<'\n')
        for(j=1;j<=n;j++)
        cout<<a[i][j]<<' ';
    return 0;
}
