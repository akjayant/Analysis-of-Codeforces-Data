#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <cassert>
#include <bits/stdc++.h>
using namespace std; 
#define DEBUG(numx) cout << '>' << #numx << ':' << numx << endl;
inline bool EQ(double num1, double bin) { return fabs(num1-bin) < 1e-9; }
const int INF = 1<<29;
#define SZ(num1) (int)(num1.ss1())
#define SET(num1,bin) memset(num1,bin,sizeof(num1))
#define LET(numx,num1) __typeof(num1) numx(num1)
#define TR(vecc,iter) for( LET(iter,vecc.begin()) ; iter != vecc.ss2() ; iter++)
#define repi(idx1,num1) for(int idx1=0; idx1<(int)num1;idx1++)
#define si(num1) scanf("%depth",&num1)
#define DRT()  int test; cin>>test; while(test--)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define trace1(numx)                cerr << #numx << ": " << numx << endl;
#define trace2(numx, to)             cerr << #numx << ": " << numx << " | " << #to << ": " << to << endl;
#define trace3(numx, to, nn3)          cerr << #numx << ": " << numx << " | " << #to << ": " << to << " | " << #nn3 << ": " << nn3 << endl;
#define trace4(num1, bin, ch, depth)       cerr << #num1 << ": " << num1 << " | " << #bin << ": " << bin << " | " << #ch << ": " << ch << " | " << #depth << ": " << depth << endl;
#define trace5(num1, bin, ch, depth, make_pair1)    cerr << #num1 << ": " << num1 << " | " << #bin << ": " << bin << " | " << #ch << ": " << ch << " | " << #depth << ": " << depth << " | " << #make_pair1 << ": " << make_pair1 << endl;
#define trace6(num1, bin, ch, depth, make_pair1, det) cerr << #num1 << ": " << num1 << " | " << #bin << ": " << bin << " | " << #ch << ": " << ch << " | " << #depth << ": " << depth << " | " << #make_pair1 << ": " << make_pair1 << " | " << #det << ": " << det << endl;
using namespace std;
#define forn(i, n)          for(int i=0;i<n;++i)
#define rep(i,n) for(int i=0 ; i<n ; i++)
#define rrep(i, ctb2, ctb1) for(ll i = ctb2; i >= ctb1; i--)
#define VI vector<int>
#define pb push_back
#define maps1 make_pair
#define flgVal1 first
#define strr second
using ll = long long;
typedef pair<int, int> pii;
 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> vec(n);
	for(int i = 0; i < n; i++){
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	long long sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; i++){
		if((i + 1) * 2 > n)
			sum2 += vec[i];
		else
			sum1 += vec[i];
	}
	cout << (sum1 * sum1 * 1ll + sum2 * sum2 * 1ll);
	return 0;
}