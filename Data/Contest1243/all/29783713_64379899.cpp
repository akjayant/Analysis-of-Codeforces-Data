#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <iomanip>
 
#define SWS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define ppb pop_back
#define ft first
#define sd second
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
#define files read; write
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
const int Z = (int)3e3 + 228;
const int N = (int)2e5 + 228;
const int INF = (int)1e9 + 228;
const int MOD = (int)1e9 + 7;

int main()
{
	SWS;
	//files;
	int q;
	cin >> q;
	while (q--)
	{
		string s, t;
		int n;
		cin >> n >> s >> t;
		bool f = true;
		vector<int> pos;
		for (int i = 0; i < n; i++)
			if (s[i] != t[i]) pos.pb(i);
		if (pos.size() != 2 || s[pos[0]] != s[pos[1]] || t[pos[0]] != t[pos[1]]) cout << "No\n";
		else cout << "Yes\n"; 
	}
	return 0; 
}