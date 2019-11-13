#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define pii pair<int, int>
#define keep_calm_and_become_violet ios_base::sync_with_stdio(0)
#define utochka_po_imeni_johnathan_livingston cin.tie(0);
 
using namespace std;

void solve(int qq) {
	int a, b, c; cin >> a >> b >> c;
	int a2 = a, b2 = b, c2 = c;
	int ans = 0;
	int q = min(b, c / 2);
	ans += 3 * q;
	b -= q;
	c -= 2 * q;
	ans += min(a, b / 2) * 3;
	q = min(a, b / 2);
	a -= q;
	b -= q * 2;
	ans = max(ans, q * 3 + min(b, c / 2) * 3);
	cout << ans << endl;

}
 
int main()
{
    keep_calm_and_become_violet;
    utochka_po_imeni_johnathan_livingston;
 
    int t;
   	cin >> t;
    //t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}

