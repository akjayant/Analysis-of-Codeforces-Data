#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;
const LL MOD=1e9+7;

const int MAX=100000009;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j%2==0)
            {
                cout<<j*n+i+1<<" ";
            }
            else
            {
                cout<<j*n+n-i<<" ";
            }
        }
        cout<<'\n';

        for(int j=0;j<n;j++)
        {
            if(j%2==1)
            {
                cout<<j*n+i+1<<" ";
            }
            else
            {
                cout<<j*n+n-i<<" ";
            }
        }
        cout<<'\n';

    }
    if(n%2==1)
    {
        for(int i=0;i<n;i++)
        {
            cout<<i*n+n/2+1<<" ";
        }
    }
    cout<<'\n';
}
