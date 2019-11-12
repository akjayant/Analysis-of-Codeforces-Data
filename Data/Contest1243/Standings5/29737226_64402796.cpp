#include<bits/stdc++.h>
#define ll long long int
#define haha(x) x.begin(),x.end()
#define pb emplace_back
#define pp pop_back
#define endl "\n"
#define s second
#define mp make_pair
using namespace std;

const int K=3e5+100;
ll arr[K],hell[K];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll ttt,n,i;		string s,t;
cin>>ttt;
      while(ttt--){
            cin>>n;
            
            cin>>s>>t;
            vector<ll>v;
            for(i=0;i<n;i++){
                if(s[i]!=t[i]){
                    hell[s[i]-'0']++;
                    hell[t[i]-'0']++; 
                    v.pb(i);
                }
            }
            bool flex=false,br=false;;
            for(i=0;i<30;i++){
                if(hell[i]%2)
                { flex=1; cout<<"No\n"; break; }
            }
            if(flex)
                continue;
            ll j;
            ll x=(ll)v.size(); vector<pair<ll,ll>>p;
            for(i=0;i<x;i++){
                if(s[v[i]]==t[v[i]])
                    continue;
                flex=0;
                for(j=i+1;j<x;j++){
                    if(t[v[i]]==t[v[j]]){
                    p.push_back(make_pair(v[i],v[j])); swap(s[v[i]],t[v[j]]);
                    flex=1; break;
                    }
                }
                if(flex)
                    continue;
                for(j=i+1;j<x;j++)
                {
                    if(t[v[i]]==s[v[j]]){
	                    p.push_back(make_pair(v[j],v[j])); swap(s[v[j]],t[v[j]]);
	                    p.pb(make_pair(v[i],v[j])); swap(s[v[i]],t[v[j]]);
	                    flex=1;
	                    break;
                    }
                }
                if(flex==0){
                      br=1; cout<<"No\n"; break; }
            }
            if(br)
                continue;
            cout<<"Yes\n"<<(ll)p.size()<<endl;
            for(i=0;i<p.size();i++){
                cout<<1+p[i].first<<" "<<1+p[i].s<<endl;
            }
    }}