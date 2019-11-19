#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << " _ " <<

using namespace std;

const int N = 1e6 + 7;

long long n, c;
int col[N];
set <long long> s;

void dfs(int u, int c){
	col[u] = c;
	for (int i = 2; i <= n; i++)
		if (n % i == 0){
			if (u + i <= n && !col[u + i])
				dfs(u + i, c);
			if (u - i >= 1 && !col[u - i])
				dfs(u - i, c);
		}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);

	cin >> n;

	long long saven = n;
	for (int i = 2; i <= trunc(sqrt(saven)); i++)
		if (n % i == 0){
			s.insert(i);
			while (n % i == 0) 
				n /= i;
		}

	if (n != 1)
		s.insert(n);

	if (s.size() > 1){
		cout << 1 << endl;
	}
	if (s.size() == 0){
		cout << n << endl;
	}
	if (s.size() == 1){
		cout << *s.begin() << endl;
	}
}