#include <bits/stdc++.h>
using namespace std;

#define N 1000012
int ntest;

int Gcd(int a, int b){
    while (b != 0){
        int t = a % b;
        a = b, b = t;
    }
    return a;
}

int main()
{
	#define file "huy"
	//freopen (file ".inp", "r", stdin);
	//freopen (file ".out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> ntest;
    while (ntest--){
        int a, b;
        cin >> a >> b;
        if (Gcd(a, b) > 1) cout << "Infinite\n";
        else cout << "Finite\n";
    }

	return 0;
}

