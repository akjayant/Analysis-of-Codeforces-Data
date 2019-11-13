#include <bits/stdc++.h>
#define intt long long
#define pb push_back
#define mk make_pair
#define ii pair<int,int>
#define sc second
#define fr first
using namespace std;
vector <intt> ans[302];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt n;
    cin>>n;
    int i;
    intt v=1,j=n*n;
    bool ok=1;
    while(ok)
    {

        ok=0;
        for(i=0; i<n; i++)
        {
            if(n-ans[i].size()>=2)
            {
                ok=1;
                ans[i].pb(v),ans[i].pb(j);
                v++;
                j--;
            }

        }
    }
    int f=v;
    for(i=0;i<n;i++)
    {
        int k;
        for(k=0;k<ans[i].size();k++)
            cout<<ans[i][k]<<" ";
        if(n%2==1)
         cout<<f++;
         cout<<endl;
    }

    return 0;
}
