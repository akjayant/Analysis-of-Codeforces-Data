///////////////////////////
//         INFO          //
//                       //
//    Handle -> Scayre   //
//                       //
//   Template vers. 1.7  //
//                       //
//   It'll be accepted   //
//                       //
///////////////////////////

///////////////////////////////////////////////////////
//████╗████████╗██╗███████╗══███╗═══███╗████████╗════//
//═██╔╝═══██╔══╝╚█║██╔════╝══████╗═████║██╔═════╝═══//
//═██║════██║════╚╝███████╗══██╔████╔██║█████╗══════//
//═██║════██║══════╚════██║══██║╚██╔╝██║██╔══╝══════//
//████╗═══██║══════███████║══██║═╚═╝═██║███████╗═════//
///////////////////////////////////////////////////////

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <complex>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define ll long long
#define ld long double
#define ull unsigned ll
#define ioi exit(0);

#define f first
#define s second

#define inf (int)1e9 + 7

#define NFS ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define mp(x,y) make_pair(x,y)

#define lb(x) lower_bound(x)
#define ub(x) upper_bound(x)

#define pb push_back
#define ppb pop_back

#define bitcoin __builtin_popcount

#define endl "\n"

#define in(x) insert(x)

#define sz(x) (int)x.size()

#define all(x) x.begin(),x.end()

#define pw2(x) (1ll<<x) //2^x

#define forit(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); ++it)

#define sqr(x) ((x) * 1ll * (x))

#define UpdateRandom srand (time(NULL));

using namespace std;

const int N = (int)5e5 + 7, MOD = (int)1e9 + 7;

int n,m;

vector<pair<int,int> > v;

string s,t;

int a[N];

int main(){

	#ifdef IOI2019
		freopen ("in.txt", "r", stdin);
	#endif

	NFS

	int q;

	cin >> q;

	while(q--){
		cin >> n;
		cin >> s;
		cin >> t;
		for(int i=0;i<sz(s);i++){
			a[s[i]]++;
			a[t[i]]++;
		}
		bool ok=1;
		for(int i='a';i<='z';i++){
			if(a[i]%2!=0){
				ok=0;
				//break;
			}
			a[i]=0;
		}
		if(!ok){
			cout << "No" << endl;
			continue;
		}
		for(int i=0;i<sz(s);i++){
			if(s[i]==t[i])continue;
			bool cur=0;
			for(int j=i+1;j<sz(s);j++){
				if(s[i]==s[j]){
					cur=1;
					v.pb({j+1,i+1});
					swap(s[j],t[i]);
					break;
				}
			}
			if(cur)continue;
			for(int j=i+1;j<sz(s);j++){
				if(s[i]==t[j]){
					v.pb({j+1,j+1});
					swap(s[j],t[j]);
					v.pb({j+1,i+1});
					swap(s[j],t[i]);
					break;
				}
			}
		}
		if(sz(v)<=n*2){
			cout << "Yes" << endl;
			cout << sz(v) << endl;
			for(int i=0;i<sz(v);i++){
				cout << v[i].f << ' ' << v[i].s << endl;
			}
		}
		else cout << "No" << endl;
		v.clear();
	}

	#ifdef IOI2019
		cout << "\nTime Elapsed : " << clock () * 1.0 / CLOCKS_PER_SEC << endl;
	#endif

	ioi
}
