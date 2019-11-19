#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

vector < long long > factors(long long n){
	vector < long long > ret;
	for(long long i = 2; i * i <= n; i++)
		if(n % i == 0)
			ret.push_back(i), ret.push_back(n / i);
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin); //freopen("output.txt", "w", stdout);
	long long n;
	cin >> n;
	vector < long long > fc = factors(n);
	long long ret = n;
	for(long long f : fc)
		ret = __gcd(ret, f);
	cout << ret << endl;
	return 0;
}
