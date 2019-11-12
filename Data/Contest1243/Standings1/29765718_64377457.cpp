/// !!!!!!!! NGHI VAN HACK !!!!!!!! ///

#include <bits/stdc++.h>
#define Killian "TASK"
#define MOD 1000000007
#define endl "\n"
#define pii pair <int,int>
using namespace std;
int t,n,a[1005];
bool cmp (int a,int b)
{
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(Killian".inp","r",stdin);
//    freopen(Killian".out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        sort(a+1,a+1+n,cmp);
        for (int i=n; i>=1; i--)
        {
            int cnt=0;
            for (int j=1; j<=n; j++)
                if (a[j]>=i)
                    cnt++;
            if (cnt>=i)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
}
