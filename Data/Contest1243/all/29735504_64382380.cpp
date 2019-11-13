#include <bits/stdc++.h>
using namespace std;

#define N 1000012

int ntest, n;
string s, t;

int main()
{
	#define file "huy"
	//freopen (file ".inp", "r", stdin);
	//freopen (file ".out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> ntest;
	while (ntest--){
        cin >> n;
        cin >> s;
        cin >> t;
        int p = -1, q = -1, dem = 0;
        for (int i = 0; i < n; i++)
            if (s[i] != t[i]){
                dem++;
                p = q;
                q = i;
            }

        if (dem > 2 || dem == 1) {cout << "No\n"; continue;}
        if (dem == 0) {cout << "Yes\n"; continue;}
        if (s[p] == s[q] && t[p] == t[q]) cout << "Yes\n";
        else cout << "No\n";
	}

	return 0;
}

