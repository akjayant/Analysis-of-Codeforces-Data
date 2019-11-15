#include <bits/stdc++.h>
using namespace std;
/* Written by Nishant Mittal aka nishantwrp */
#define FAST std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define modnum 1000000007
#define mp make_pair
#define pb push_back
#define PB pop_back
#define sl(a) (int)a.length()
#define sz(a) (int)a.size()
#define lcase(a) (char)tolower(a)
#define ucase(a) (char)toupper(a)
#define precise(a) fixed<<setprecision(a)<<
#define F first
#define S second
#define I insert
#define pii pair<int,int>
#define trav(a, x) for(auto& a : x)
#define rep(n) for(int i = 0;i<n;i++)
#define rrep(n) for(int i = n-1;i>=0;i--)
#define time cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
#define invect(data,n,commands) for(int i = 0;i<n;i++){int tmp;cin>>tmp;data.pb(tmp);commands}
#define inset(data,n,commands) for(int i = 0;i<n;i++){int tmp;cin>>tmp;data.I(tmp);commands}
#define display(x) trav(a,x) cout<<a<<" "; cout<<endl;
#define ingrid(data,n,commands) for(int i = 0; i<n; i++){cin>>data[i];commands}
#define section(a,b,w) set_intersection(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
#define union(a,b,w) set_union(a.begin(), a.end(),b.begin(), b.end(),back_inserter(w));
#define copy(a,w) copy(a.begin(), a.end(),back_inserter(w));
#define all(data) data.begin(), data.end()
#define PI 3.14159265358979323844
#define endl '\n'
#define last(a) a[sz(a)-1]
#define INF 1000000000000000000

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// Graph DFS
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};

//primes for hashing 937,991,1013,1409,1741

//Returns index of first element not less than key and more than key respectively
#define lb(data,key) lower_bound(all(data),key) - data.begin();
#define up(data,key) upper_bound(all(data),key) - data.begin();
#define fnd(data,key) find(all(data),key) - data.begin();
/* Long Long Int */
#define int long long int
/*

███╗   ██╗██╗███████╗██╗  ██╗ █████╗ ███╗   ██╗████████╗██╗    ██╗██████╗ ██████╗ 
████╗  ██║██║██╔════╝██║  ██║██╔══██╗████╗  ██║╚══██╔══╝██║    ██║██╔══██╗██╔══██╗
██╔██╗ ██║██║███████╗███████║███████║██╔██╗ ██║   ██║   ██║ █╗ ██║██████╔╝██████╔╝
██║╚██╗██║██║╚════██║██╔══██║██╔══██║██║╚██╗██║   ██║   ██║███╗██║██╔══██╗██╔═══╝ 
██║ ╚████║██║███████║██║  ██║██║  ██║██║ ╚████║   ██║   ╚███╔███╔╝██║  ██║██║     
╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝   ╚═╝    ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     
                                                                                                       
*/
int ans = 0;

void nishantwrp(int cas) {
	int n;
	cin>>n;
	vector <int> ans[n];
	rep(n) {
		int j=0;
		while(j<n) {
			if (i % 2 == 1)
			{
				ans[n-j-1].pb((n*i) + j);
			} else {
				ans[j].pb((n*i) + j);
			}
			j++;
		}
	}
	trav(x,ans) {
		trav(y,x) {
			cout<<y+1<<" ";
		}
		cout<<endl;
	}
}

signed main()
{
FAST
int t = 1;
// cin>>t;
int cas = 1;
while(cas <= t) {
	nishantwrp(cas);
	ans = 0;
	cas++;
}
return 0;
}