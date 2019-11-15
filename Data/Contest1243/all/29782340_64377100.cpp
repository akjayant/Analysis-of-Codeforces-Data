#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream fin("AAtest.in.txt");
ll k,n;
string s,s1;
vector<ll> v;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    cin>>k;
    while(k--){
        cin>>n;
        cin>>s>>s1;
        v.resize(0);
        for(int i=0; i<n; i++) if(s[i]!=s1[i]) v.push_back(i);
        if(v.size()==0) cout<<"Yes\n";
        else if(v.size()!=2) cout<<"No\n";
        else if(s1[v[0]]!=s1[v[1]] || s[v[0]]!=s[v[1]]) cout<<"No\n";
        else cout<<"Yes\n";
    }
}
