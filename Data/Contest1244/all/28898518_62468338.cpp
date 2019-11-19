#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll,ll>

ll arr[500005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i,j,n,m,a,b,c,d,k,x,y,t;
    cin>>t;

    for(ll cz=1;cz<=t;cz++){
        cin>>a>>b>>c>>d>>k;

        if(a%c==0) m=a/c;
        else m=a/c+1;

        if(b%d==0) j=b/d;
        else j=b/d+1;

        if(m+j>k) cout<<-1<<endl;
        else cout<<m<<" "<<j<<endl;
    }
}

