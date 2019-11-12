#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef pair<int,int>   pii;
typedef vector< pii >  vii;
typedef long long int 	ll;

#define pb push_back
#define fe first
#define se second
#define all(a) (a).begin(),(a).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define scn(n) scanf("%d",&n)
#define prn(n) printf("%d\n",n)
#define scnl(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mset(A, val) memset(A, val, sizeof(A))
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const ll mod = 1e9 + 7ll;
const int N = (int)1e5 + 7;

int main(){
	
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		string st,tt;
		cin>>n;
		cin>>st>>tt;
		vector<int> cnt(30,0);
		rep(i,0,n){
			cnt[tt[i]-'a']++;
			cnt[st[i]-'a']++;
		}
		int fl=0;
		rep(i,0,30){
			if(cnt[i]%2==1){
				fl=1;
				break;
			}
		}
		if(fl){
			cout<<"No"<<endl;
			continue;
		}
		vii stor;
		rep(i,0,n){
			if(st[i]==tt[i]) continue;
			else{
				int j=i+1,tp=0;
				while(j<n){
					if(st[j]==st[i]){
						st[j]=tt[i];
						tt[i]=st[i];
						stor.pb({j,i});
						break;
					}
					if(tt[j]==st[i]){
						tt[j]=st[j];
						st[j] = tt[i];
						tt[i] = st[i];
						stor.pb({j,j});
						stor.pb({j,i});
						break;					
					}
					j++;
				}
			}
		}

		cout<<"Yes"<<endl;
		cout<<stor.size()<<endl;
		for(auto it:stor)
			cout<<it.fe+1<<" "<<it.se+1<<endl;
	}
	return 0;
}
