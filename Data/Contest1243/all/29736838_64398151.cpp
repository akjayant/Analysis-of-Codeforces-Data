#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll,ll>

ll arr[500005];
ll brr[500005];

vector<ll>v;
vector<ll>v1;

map<ll,ll>mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,n,m,t;

    cin>>n;
    m=n;
    ll chk=0,ans=0;
    for(i=2;i*i<=n;i++){
        if(n%i==0) {ans=i;chk++;}
        while(n%i==0){
            n=n/i;
        }
    }
    if(chk==1&&n==1) cout<<ans<<endl;
    else if(m==n) cout<<n<<endl;
    else cout<<1<<endl;
}

