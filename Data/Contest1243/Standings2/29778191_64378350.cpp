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

vector<int> v;

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
			if(s[i]!=t[i]){
				v.pb(i);
			}
		}
		//cout << sz(v) << endl;
		if(sz(v)>2){
			cout << "No" << endl;
		}
		else{
			bool ok=0;
			for(int i=0;i<sz(v);i++){
				for(int j=0;j<sz(v);j++){
					char x=s[v[i]],y=t[v[j]];
					s[v[i]]=y;
					t[v[j]]=x;
					if(s==t){
						ok=1;
						cout << "Yes" << endl;
						break;
					}
					s[v[i]]=x;
					t[v[j]]=y;
				}
				if(ok)break;
			}
			if(!ok){
				cout << "No" << endl;
			}
		}
		v.clear();
	}

	#ifdef IOI2019
		cout << "\nTime Elapsed : " << clock () * 1.0 / CLOCKS_PER_SEC << endl;
	#endif

	ioi
}
