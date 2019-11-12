#include <iostream>
#include <bits/stdc++.h>
#define forn(i,n)for(int i=0;i<n;i++)
#define forna(i,a,n)for(int i=a;i<n;i++)
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1e9+7
#define ff first
#define ss second
#define INF 1e9
#define MAX 100000
#define ya cout<<"YES"<<endl;continue;
typedef long long ll;
using namespace std;
vector <pair<int,int>> p(MAX);
set <int> s;
int count[MAX];
int main()
{
    IOS
	int q;cin>>q;
	while(q--){
		int n;cin>>n;
		string s,t;cin>>s>>t;
		vector <char> ss,tt;
		forn(i,n){
			if(s[i]==t[i]) continue;
			ss.pb(s[i]);
			tt.pb(t[i]);
		}
		//for(auto x:ss) cout<<x<<endl;
		if((int)ss.size() != 0 && (int)ss.size() != 2){
			cout<<"NO"<<endl;
			continue;
		}
		//cout<<"haha"<<endl;
		if(ss.empty()) {
			cout<<"YES"<<endl;continue;
		}
		if(ss[0]==ss[1] && tt[0]==tt[1]){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}
