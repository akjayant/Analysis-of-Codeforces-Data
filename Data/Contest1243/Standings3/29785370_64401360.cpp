#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

#define f first
#define se second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define lp(i, n) for (int i = 0; i < n; i++)
#define mem(a, v) memset(a, v, sizeof(a))
#define X real()
#define Y imag()
#define angle(a) (atan2(a.Y, a.X))
#define vec(a, b) ((b) - (a))
//#define length(a) (hypot(a.Y , a.X))
#define normalize(a) (a) / length(a)
#define dotP(a, b) ((conj(a) * b).X)
#define crossP(a, b) ((conj(a) * b).Y)
#define same(p1, p2) (dotP(vec(p1, p2), vec(p1, p2)) < EPS)
#define lengthSqr(a) dotP(a, a)
#define rotate0(p, ang) ((p)*exp(point(0, ang)))
#define rotateA(p, ang, about) (rotate0(vec(about, p), ang) + about)
#define reflect0(v, m) conj(v / m) * m
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const double PI = acos(-1.0);
const double EPS = (1e-10);
const long long int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
typedef long long int ll;
typedef unsigned long long ull;
typedef complex<double> point;
long long fastpow(ll n, ll x) {
  if (!x)
    return 1;
  if (x % 2)
    return n * fastpow(n, x - 1);
  ll p = fastpow(n, x / 2);
  p %= mod;
  p *= p;
  p %= mod;
  return p;
}

ll my_mod(ll num, ll mod) {
  ll ret = num % mod;
  while (ret < 0)
    ret += mod;
  return ret;
}

ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }
long double dist(pair<ll, ll> &a, pair<ll, ll> &b) {
  return sqrt(
      ((a.f - b.f) * (a.f - b.f) * 1.0 + (a.se - b.se) * (a.se - b.se)));
}
/*vector<int> ap;
bool np[MX];
void s(){
    mem(np , 1);
    np[1] = np[0] = 0;
    for(ll i = 2 ; i*i<= MX ;i++){
        if(np[i]){
            for(ll j= i*i ; j <MX; j+=i) np[j] = 0;
        }
    }
    for(ll i = 2 ; i< MX ; i++) if(np[i]) ap.pb(i);
}*/
const ll MX = 1e5+5;
set<int> av1[500],av2[500];
int main()
{
    IO;
	int tc;
	cin>>tc;
	while(tc--){
		for(int i ='a' ; i<='z' ; i++) {
			av1[i].clear();
			av2[i].clear();
		}
		int n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		for(int i = 0; i < n; i++){
			if(s[i] != t[i]){
				av1[s[i]].insert(i);
				av2[t[i]].insert(i);
			 }
		}
		vector<pair<int,int> >  ans;
		for(int i =0 ; i < n; i++){
			if(s[i] != t[i]){
				bool ok = 0;
				// if t has t[i]
				if(av2[t[i]].size()){
					set<int>::iterator it = av2[t[i]].begin();
					int ind = -1;
					if(*it == i){
						it++;
					}
					if(it != av2[t[i]].end()){
						ind = *it;
						av2[t[i]].erase(it);
						av1[s[i]].erase(i);
						av2[t[i]].erase(i);
						swap(s[i],t[ind]);
						ans.pb({i,ind});
						if(s[ind] == t[ind]){
							av1[s[ind]].erase(ind);
						}else{
							av2[t[ind]].insert(ind);
						}
						ok = 1;
					}
				}
				if(ok == 1) continue;
				if(av1[t[i]].size()){
					set<int>::iterator it = av1[t[i]].begin();
					int ind = -1;
					if(*it == i){
						it++;
					}
					if(it != av1[t[i]].end()){
						ind = *it;
						av1[t[i]].erase(it);
						av2[t[i]].erase(i);
						av2[t[ind]].erase(ind);
						av1[s[i]].erase(i);
						swap(s[i],s[ind]);
						swap(s[ind],t[ind]);
						ans.pb({ind,ind});
						ans.pb({i,ind});
						if(s[ind] != t[ind]){
							av1[s[ind]].insert(ind);
							av2[t[ind]].insert(ind);	
						}
						ok = 1;
					}
				
				}
				if(ok == 1) continue;
				if(av1[s[i]].size()){
					set<int>::iterator it = av1[s[i]].begin();
					int ind = -1;
					if(*it == i){
						it++;
					}
					if(it != av1[s[i]].end()){
						ind = *it;
						av1[s[i]].erase(it);
						av1[s[i]].erase(i);
						av2[t[i]].erase(i);
						swap(s[i],t[ind]);
						ans.pb({i,ind});
						if(s[ind] == t[ind]){
							av2[t[ind]].erase(ind);
						}else{
							av1[s[ind]].insert(ind);
						}
						ok = 1;
					}
				}
				if(ok == 1) continue;
				if(av2[s[i]].size()){
					set<int>::iterator it = av2[s[i]].begin();
					int ind = -1;
					if(*it == i){
						it++;
					}
					if(it != av2[s[i]].end()){
						ind = *it;
						av2[s[i]].erase(it);
						av2[t[i]].erase(i);
						av1[s[ind]].erase(ind);
						av1[s[i]].erase(i);
						swap(t[i],t[ind]);
						swap(s[ind],t[ind]);
						ans.pb({ind,ind});
						ans.pb({ind,i});
						if(s[ind] != t[ind]){
							av1[s[ind]].insert(ind);
							av2[t[ind]].insert(ind);	
						}
						ok = 1;
					}
				
				}
			}
		}
		if(s == t){
			cout<<"Yes\n";
			cout<<ans.size()<<"\n";
			for(auto it : ans) cout<<it.f+1<<" "<<it.se+1<<"\n";
		}else{
			cout<<"No\n";
		}
	}
   return 0;
}



