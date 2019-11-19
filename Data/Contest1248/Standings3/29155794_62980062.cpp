#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10;

long long p_even, p_odd, q_even, q_odd;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	int n, m;
	while(t--){
		p_even = p_odd = q_odd = q_even = 0;
		cin >> n;
		int x;
		for(int i=0;i<n;++i){
			cin >> x;
			if(x & 1) p_odd++;
			else p_even++;
		}

		cin >> m;
		for(int i=0;i<m;++i){
			cin >> x;
			if(x & 1) q_odd++;
			else q_even++;
		}
		cout << p_even * q_even + p_odd * q_odd << '\n';
	}

	return 0;
}