#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll,ll>

ll dp[2][1005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i,j,n,m,t;
    cin>>t;
    string s;
    for(ll cz=1;cz<=t;cz++){
        cin>>n;
        cin>>s;

        //if(s[n-1]=='0') dp[1][n-1]=1,dp[0][n-1]=1;
        //for(i=0;i<2;i++)
        ll ans=0;
       ll mn=n;
        for(j=n-1;j>=0;j--){
            if(s[j]=='1') break;
        mn--;
        }
        ans=max(2*mn,ans);
        if(j==-1){ cout<<n<<endl; continue;}
        mn=n;
        for(j=0;j<n;j++){
            if(s[j]=='1') break;
        mn--;
        }
        ans=max(ans,2*mn);

        cout<<ans<<endl;
    }
}
