#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << " _ " <<

using namespace std;

int test, n;
int a[1007];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);

	cin >> test;
	while (test--){
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		for (int i = n; i >= 1; i--){
			if (a[i] >= i){
				cout << i << endl;
				break;
			}
		}
	}
}