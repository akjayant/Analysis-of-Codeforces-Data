#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define pii pair<int,int>
#define io(); freopen("in.txt","r",stdin); freopen("output.txt","w",stdout); 
#define fast(); ios_base::sync_with_stdio(false);
#define all(x) x.begin(),x.end()
bool fun(string s,string t){
	string u="",v="";
	for(int i=0;i<s.size();i++) if(s[i]!=t[i]){
		u+=s[i];
		v+=t[i];
	}
	//cout<<u<<" "<<v<<endl;
	if(u.size()>2 or u.size()==1) return false;
	if(u.size()==0) return true;
	string a=u,b=v;
	swap(a[0],b[0]);
	if(a==b) return true;
	a=u,b=v;
	swap(a[0],b[1]);
	if(a==b) return true;
	a=u,b=v;
	swap(a[1],b[0]);
	if(a==b) return true;
	a=u,b=v;
	swap(a[1],b[1]);
	if(a==b) return true;
	return false;
}
int32_t main(){
	fast();
    #ifndef ONLINE_JUDGE
    io();
    #endif
    int t,n,i,j;
    cin>>t;
    while(t--){
    	cin>>n;
    	string u,v;
    	cin>>u;
    	cin>>v;
    	if(fun(u,v)) cout<<"Yes\n";
    	else cout<<"No\n";
    }
}