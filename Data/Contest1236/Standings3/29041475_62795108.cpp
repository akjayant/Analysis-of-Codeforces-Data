#include <bits/stdc++.h>
using namespace std;
int n;
vector < int > a[301];

int main()
{
   // freopen("x.inp","r",stdin);
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        if ( i%2 == 1 ) for (int j=1;j<=n;j++) a[j].push_back( (i-1)*n + j );
        else for (int j=1;j<=n;j++) a[j].push_back(  (i-1)*n + n- j + 1 );
    }

    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<n;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
