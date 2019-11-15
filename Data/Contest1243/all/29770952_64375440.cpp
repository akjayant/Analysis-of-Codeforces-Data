#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int main()
{
    //freopen("test.in","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin>>k;
    while(k--)
    {
        int n; cin>>n;
        vector<int> v(n), a(n+1);
        for(int i=0;i<n;i++) cin>>v[i];
        for(int x:v)
        {
            for(int i=x;i>=0;i--) a[i]++;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=i) ans=i;
            else break;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
