#include<bits/stdc++.h>
#define ll long long 
#define ull unsigned long long int
#define boost ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0)
#define vi vector<int>
#define P push_back
#define F first
#define S second
#define debug(x) cout<<x<<" "
#define pi vector<pair<int,int> >
#define FOR(i,x,n) for(int i=x;i<n;i++)
#define all(a) a.begin(),a.end()
ll mod=1e9+7;
#define N 99999999
using namespace std;
#define int ll
ll powi(int i,int b){
	int res=1;
	while(b){
		if(b&1)res*=i,res%=mod;
		b>>=1;
		i*=i;
		i%=mod;
	}
	return res;
}
// unordered_map<int,int> m;
// ll fact(int n){
// 	//if(n==0)return 0;
// 	if(n<=1)return 1;
// 	if(m[n]!=0)return m[n];
// 	return m[n]=(n*fact(n-1))%mod;
// }
// int root(int a,vi &unio){
// 	if(unio[a]==a)return a;
// 	else return unio[a]=root(unio[a],unio);
// }
// void merge(int x,int y,vi &unio){
// 	unio[root(y,unio)]=root(x,unio);
// }
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=-1,r=-1;
    for(int i=0;i<s.length();i++){
        if(l==-1){
            if(s[i]=='1')l=i,r=i;
        }
        else{
            if(s[i]=='1')r=i;
        }
    }
    int ans=0;
    if(l==-1)ans=n;
    else if(l==r){
        ans=2*n-min(2*l,2*(n-l-1));
    }
    else{
        ans=2*n-2*min(l,n-r-1);
    }
    cout<<ans;
}	
signed main(){
    boost;
    int t=1;
    cin>>t;
    for(int _=1;_<=t;_++){
        //~ cout<<"Case #"<<_<<": ";
        solve();
        cout<<"\n";
    }
    
    return 0;
}