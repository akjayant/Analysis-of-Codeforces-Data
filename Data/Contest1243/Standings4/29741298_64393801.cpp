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
// int ncr(int n,int r){
//     int h=fact(n);
//     int v=fact(r);
//     int j=fact(n-r);
//     v*=j;
//     v%=mod;
//     v=powi(v,mod-2);
//     return (h*v)%mod;
// }
void solve(){
    int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	int flag3=0;
	queue<pair<int,int>> q;
	vi a(26);
	for(int i=0;i<n;i++){
		a[s[i]-'a']++;a[t[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(a[i]%2!=0){flag3++;break;}
	}
	if(!flag3){
		cout<<"Yes\n";
		for(int i=0;i<n;i++){
			if(s[i]!=t[i]){
				for(int j=i+1;j<n;j++){
					if(s[j]==s[i]){
						q.push({j,i});
						swap(t[i],s[j]);break;
					}
				}
				if(s[i]!=t[i]){
					q.push({i,i});
					swap(s[i],t[i]);
					for(int j=i+1;j<n;j++){
						if(t[j]==t[i]){
							q.push({i,j});
							swap(s[i],t[j]);break;
						}
					}
				}
			}
		}
		if(q.size()==0){
			q.push({0,0});
		}
		cout<<q.size()<<"\n";
		while(!q.empty()){
			cout<<q.front().F+1<<" "<<q.front().S+1<<"\n";
			q.pop();
		}
	}
	else{
		cout<<"No";
	}
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