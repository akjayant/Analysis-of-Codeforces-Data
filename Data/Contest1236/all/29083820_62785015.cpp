#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define NMAX 200005
using namespace std;
typedef long long ll;
ll a, b, c, d, q, i, ans;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
}
int main()
{
    fast();
    cin>>q;
    while(q)
    {
        --q;
        cin>>a>>b>>c;
        ans=-1;
        for(i=0;i<=a;i++)
        {
            ans=max(ans,min(i,b/2)*3+min(b-(min(i,b/2))*2,c/2)*3);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
