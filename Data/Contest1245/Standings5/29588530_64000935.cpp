#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long int
#define fill(space,a) memset(space,a,sizeof(space))
#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);

int gcd(int a, int b){
	if (b == 0)
		return a;
	return gcd(b, a % b);

}

int main()
{
	optimize();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int tt; cin >> tt;
	while (tt--) {
		int a, b; cin >> a >> b;
		int g = gcd(a, b);
		if (g == 1) {
			cout << "Finite" << endl;
		}
		else {
			cout << "Infinite" << endl;
		}
	}

	return 0;
}