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

int v[100010];
int main(){
	int t;
	cin >> t;
	while(t--) {
		int ret = 1;
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> v[i];
		sort(v, v+n);
		int tot = 0;
		for(int i = n - 1; i >= 0; i--){
			tot ++;
			if(v[i] >= tot)
				ret = max(ret, tot);
		}
		cout << ret << endl;
	}
	exit(0);
}
