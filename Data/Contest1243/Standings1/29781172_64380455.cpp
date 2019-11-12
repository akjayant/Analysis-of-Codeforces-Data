#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define sc(a) scanf("%d", &a)
#define sc2(a, b) sc(a), sc(b)
#define pri(x) printf("%d\n", x)
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		map<pair<char, char>, int> mapp;
		pair<char, char> resp;
		for(int i = 0; i < n; i++) {
			if(s[i] != t[i]) {
				resp = make_pair(s[i], t[i]);
				mapp[resp]++;
			}
		}
		if(mapp.size() == 0 or (mapp.size() == 1 and mapp[resp] == 2)){
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	exit(0);
}
