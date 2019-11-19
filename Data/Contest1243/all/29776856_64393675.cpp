/*
* @Author: SajidZakaria
* @Date:   2019-11-06 21:02:24
* @Last Modified by:   SajidZakaria
* @Last Modified time: 2019-11-06 21:50:53
*/

#include<bits/stdc++.h>
using namespace std;

map<long long, bool> mp;

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main(){
	long long n, m;
	cin >> n;

	m = n;
	vector<long long> v;
	for(long long i=2, sr = sqrt(n); i<=sr; i++) {
		if(m % i == 0) {
			v.push_back(i);
			while(m % i == 0) m /= i;
		}
	}
	if(m != 1) v.push_back(m);
	
	if(v.size() > 1 or n == 1) cout << 1 << endl;
	else cout << v[0];
}