#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mod 1000000007

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(),cout.tie();
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s,t;
        cin>>s;
        cin>>t;
        ll pos1=-1,pos2=-1;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                if(pos1==-1) pos1=i;
                else if(pos2==-1) pos2=i;
            }
        }
        swap(s[pos1],t[pos2]);
        if(s==t) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

