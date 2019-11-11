#include <bits/stdc++.h>
using namespace std;

#define N 1000012
int ntest, n, a, b, c, d[5];
int ret[N];

int main()
{
	#define file "huy"
	//freopen (file ".inp", "r", stdin);
	//freopen (file ".out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> ntest;
    while (ntest--){
        cin >> n >> a >> b >> c;
        d[1] = a, d[2] = b, d[3] = c;
        for (int i = 1; i <= n; i++) ret[i] = 0;
        for (int i = 1; i <= n; i++){
            char ch;
            cin >> ch;
            if (ch == 'R' && d[2] > 0) d[2]--, ret[i] = 2;
            if (ch == 'P' && d[3] > 0) d[3]--, ret[i] = 3;
            if (ch == 'S' && d[1] > 0) d[1]--, ret[i] = 1;
        }
        if ((a + b + c - d[1] - d[2] - d[3]) < (n + 1) / 2) {cout << "NO\n"; continue;}
        for (int i = 1; i <= n; i++){
            if (ret[i] != 0) continue;
            if (d[1] > 0) {d[1]--, ret[i] = 1; continue;}
            if (d[2] > 0) {d[2]--, ret[i] = 2; continue;}
            if (d[3] > 0) {d[3]--, ret[i] = 3; continue;}
        }
        cout << "YES\n";
        for (int i = 1; i <= n; i++){
            if (ret[i] == 1) cout << 'R';
            if (ret[i] == 2) cout << 'P';
            if (ret[i] == 3) cout << 'S';
        } cout << "\n";
    }

	return 0;
}

