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

string s;

int a[N];

int main(){

	#ifdef IOI2019
		freopen ("in.txt", "r", stdin);
	#endif

	NFS

	int t;

	cin >> t;

	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		for(int i=1;i<=n+1;i++){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(a[j]>=i)cnt++;
			}
			if(cnt<i){
				cout << i-1 << endl;
				break;
			}
		}
	}

	#ifdef IOI2019
		cout << "\nTime Elapsed : " << clock () * 1.0 / CLOCKS_PER_SEC << endl;
	#endif

	ioi
}
