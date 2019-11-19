#include <bits/stdc++.h>
using namespace std;

vector <int> factors;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n;
	cin >> n;
	long long backup = n;
	for (long long i = 2; i*i <= n; ++i){
		while (n % i == 0){
			factors.push_back(i);
			n /= i;
		}
	}
	if (n != 1 && n != backup)
		factors.push_back(n);

	if (factors.size() == 0){
		cout << backup << "\n";
		return 0;
	}
	bool diff = false;
	int p = factors[0];
	for (int i = 1; i < factors.size(); ++i){
		if (factors[i] != p)
			diff = true;
	}
	if (diff){
		cout << "1\n";
		return 0;
	}
	cout << p << "\n";
}