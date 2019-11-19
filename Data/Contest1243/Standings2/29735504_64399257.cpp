#include <bits/stdc++.h>
using namespace std;

#define N 1000012
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)

long long n;
long long p = -1, tem, sl = 0, m;

int main()
{
	#define file "huy"
	//freopen (file ".inp", "r", stdin);
	//freopen (file ".out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;

	tem = n;
    for(long long i = 2; i * i <= tem; ++i){
        if (n % i == 0){
            if (p != -1) {
                cout << 1;
                return 0;
            }
            while (tem % i == 0) tem /= i;
            p = i;
        }

    }

    p *= 10;
    if (p >= 0 && tem > 1) {
        cout << 1;
        return 0;
    }
    p /= 2; p /= 5;
    if (p == -1) {
        cout << n;
        return 0;
    }
    p = ~p; p = ~p;
    cout << p;

	return 0;
}

