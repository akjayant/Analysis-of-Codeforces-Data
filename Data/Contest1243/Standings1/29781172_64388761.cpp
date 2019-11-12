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

int v[30];
int main(){ _
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		memset(v, 0, sizeof(v));
		for(int i = 0; i < n; i++){
			v[s[i] - 'a']++;
			v[t[i] - 'a']++;
		}
		bool val = true;
		for(int i = 0; i < 30; i++)
			if(v[i] % 2) val = false;
		if(!val) {
			cout <<"No"<<endl;
			continue;
		}
		cout << "Yes" << endl;
		vector<ii> ret;
		for(int i = 0; i < n - 1; i++){
			char c;
			c = s[i];
			int k = -1;
			for(int j = i; j < n; j++){
				if(t[j] == c)
					k = j;
			}
			if(k!= -1){
				swap(s[k], t[k]);
				ret.pb(make_pair(k, k));
				swap(s[k], t[i]);
				ret.pb(make_pair(k, i));
			}
			else {
				for(int j = i + 1; j < n; j++){
					if(s[j] == c)
						k = j;
				}
				if(k!=-1){
					swap(s[k], t[i]);
					ret.pb(make_pair(k, i));
				}
			}
		}
		cout << ret.size() << endl;
		for(ii x: ret){
			cout <<x.fi + 1 << " "<< x.se + 1 << endl;;
		}
	}
	exit(0);
}
