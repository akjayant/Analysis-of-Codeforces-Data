#include <bits/stdc++.h>
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int main()
{
	
	int k;
	cin >> k;
	while(k--) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		V<pair<char, char>> v;
		for(int i=0;i<n;i++)
			if(s[i] != t[i])
				v.EB(s[i], t[i]);
		if(v.size() == 1) cout << "NO" << endl;
		else if(v.size() == 2) {
			if(v[0] == v[1]) cout << "YES" << endl;
			else cout << "NO" << endl;
		} else cout << "NO" << endl;
	}
	
}
