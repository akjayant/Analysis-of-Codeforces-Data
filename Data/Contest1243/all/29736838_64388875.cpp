#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll,ll>

ll arr[500005];
ll brr[500005];

vector<ll>v;
vector<ll>v1;

map<ll,ll>mp;

ll cnt[30];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,n,m,ts;
    string s,t;
    cin>>ts;

    for(ll cz=1;cz<=ts;cz++){
            v.clear();
    v1.clear();
        cin>>n;
    ll chk1=0;
        cin>>s;
        cin>>t;
        if(s==t){
            cout<<"Yes"<<endl;
            continue;
        }
        ll shajib=0;
        for(i=0;i<n;i++){
            if(s[i]!=t[i]){
                v.push_back(i);
            }
        }
        //cout<<v.size()<<" "<<v[0]<<" "<<v[1]<<endl;
        if(v.size()==2){
            if(s[v[1]]==s[v[0]]&&t[v[0]]==t[v[1]]) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
}

