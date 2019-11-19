#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> p(n,0);
        int ocp=0,ocq=0;
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            if(p[i]%2==1)ocp++;
        }
        int m;
        cin>>m;
        vector<int> q(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>q[i];
            if(q[i]%2==1)ocq++;
        }
        ll ans = 1LL*ocp*ocq + 1LL*(n-ocp)*(m-ocq);
        cout<<ans<<endl;
    }
    return 0;
}