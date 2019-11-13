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

const ll mod = 1e9 + 7ll;
const int N = (int)1e5 + 7;

int main(){
	
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string st,tt;
		cin>>st>>tt;
		vector<int> df,cnt(30,0);
		int fl=0;
		rep(i,0,n){
			cnt[st[i]-'a']++;
			if(cnt[st[i]-'a']>=2) fl=1;
			if(st[i]!=tt[i]) df.pb(i);
		}

		string ans="No";
		if(df.size()==0 && fl) ans="Yes";
		if(df.size()==2 && st[df[0]]==st[df[1]] && tt[df[0]]==tt[df[1]]) ans="Yes";
		cout<<ans<<endl;
	}
	return 0;
}
