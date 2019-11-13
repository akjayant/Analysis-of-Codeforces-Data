
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=1e5+5,MOD=1e9+7;
const ld EPS = 1e-9;


int main(){
	fastio;
	int tests;
	cin>>tests;
	
	while(tests--){

		int n;
		cin>>n;
		int a,b,c;
		cin>>a>>b>>c;
		string s;
		cin>>s;
		string ans = s;
		int tot = 0;
		forn(i,n){
			if(s[i] == 'R'){
				if(b>0){
					b--;
					tot+=1;
					ans[i] = 'P';
				}
				else ans[i] = '?';
			}
			else if(s[i] == 'P'){
				if(c>0){
					c--;
					tot+=1;
					ans[i] = 'S';
				}
				else ans[i] = '?';
			}
			else if(s[i] == 'S'){

				if(a>0){
					a--;
					tot+=1;
					ans[i] = 'R';
				}
				else ans[i] = '?';
			}
		}
		if(2*tot >= n){
			cout<<"YES"<<ln;
			forn(i,n){
				if(ans[i] == '?'){
					if(a>0){
						ans[i] = 'R';
						a--;
					}
					else if(b>0){
						ans[i] = 'P';
						b--;
					}
					else{
						ans[i] = 'S';
						c--;
					}
				}
			}
			cout<<ans<<ln;
		}
		else cout<<"NO"<<ln;

	}

	return 0;
}