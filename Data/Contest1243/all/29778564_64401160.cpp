#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define pii pair<int,int>
#define io(); freopen("in.txt","r",stdin); freopen("output.txt","w",stdout); 
#define fast(); ios_base::sync_with_stdio(false);
#define all(x) x.begin(),x.end()
int fun(int n){
	int ct=0;
	int save=n;
	int ans=0;
	set<int>v;
	while(n%2==0){
		ct++;
		n/=2;
	}
	if(ct>0) {ans++;v.insert(2);}
	for(int i=3;i*i<=n;i+=2){
		ct=0;
		while(n%i==0){
			ct++;
			n/=i;
		}
		if(ct>0) {ans++;v.insert(i);}
	}
	if(n>2) {ans++;v.insert(n);}
	if(v.size()==1) return *v.begin();
	return 1;
}
int32_t main(){
	fast();
    #ifndef ONLINE_JUDGE
    io();
    #endif
    int n;
    cin>>n;
    cout<<fun(n);
}