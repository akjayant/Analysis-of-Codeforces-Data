#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+10;

vector<int> v;
int res[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i%2==1)
                res[j][i]=j+(i-1)*n;
            else
                res[n-j+1][i]=j+(i-1)*n;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<res[i][j]<<" ";
        cout<<"\n";
    }
}
