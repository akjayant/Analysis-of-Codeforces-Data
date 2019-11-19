#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define m_p make_pair
#define p_i pair<int, int> 
#define maxn 12
#define maxm 505
#define _for(i, a) for(LL i = 0; i < (a); i++)
#define _rep(i, a, b) for(LL i = (a); i <= (b); i++)
#define outval(a) cout<<#a<<": "<<a<<"\n"
using namespace std;
typedef long long LL;
const LL MAXN = 110;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
typedef vector< double > vec;
typedef vector< vec > mat;

const double eps = 1e-8;

vector<LL> a;

void init() {

}



int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);

	int n;
	cin >> n;
	a.resize(n);
	_for(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	LL sum = 0, tem = 0;
	_for(i, a.size()) sum += a[i];
	_for(i, a.size() / 2) tem += a[i];
	sum -= tem;
	cout << tem * tem + sum * sum << "\n";
	//cout << a[0] * a[0] + sum * sum << "\n";
	return 0;
}

/*

*/
