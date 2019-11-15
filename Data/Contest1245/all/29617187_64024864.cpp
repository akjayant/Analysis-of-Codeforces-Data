#include <bits/stdc++.h>
using namespace std;

const long long Mod = 1e9 + 7;
#define N 100002

string s;
int len;
long long d[N + 12], f[N + 12];

int main()
{
	#define file "huy"
	//freopen (file ".inp", "r", stdin);
	//freopen (file ".out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'm' || s[i] == 'w'){
            cout << 0;
            return 0;
        }
    int dem = 1;
    for (int i = 1; i < s.size(); i++){
        if (s[i] == s[i - 1] && (s[i - 1] == 'n' || s[i - 1] == 'u')) dem++;
        else {
            if (dem > 1) len++, d[len] = dem;
            dem = 1;
        }
    }

    if (dem > 1) len++, d[len] = dem;

    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= N; i++) f[i] = (f[i - 2] + f[i - 1]) % Mod;

    long long ans = 1;
    for (int i = 1; i <= len; i++){
        ans = (ans * f[d[i]]) % Mod;
    }

    cout << ans;

	return 0;
}

