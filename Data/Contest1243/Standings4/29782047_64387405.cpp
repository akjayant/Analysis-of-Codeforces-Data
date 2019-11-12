#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <set>
#include <fstream>
typedef long long ll;

using namespace std;


ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}



bool IsPrime(ll n) {
	for (ll i = 2; i*i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}

ll binpow(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

vector<ll> v;

inline void precalc(ll n, ll digit) {
	
	if (IsPrime(n)) v.push_back(n);
	else return;
	if(digit<3)
	for (ll i = 1; i <= 9; i++)
		precalc(n+ i*binpow(10,digit), digit+1);
}

const ll LIMIT = 2e5;

ll divisors(ll n) {
	int cnt = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) cnt++;
	}
	return cnt;
}

int bsort(string s) {
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < s.length()-1-i; j++) {
			if (s[j] > s[j + 1]) {
				swap(s[j], s[j + 1]);
				cnt++;
			}
		}
	}
	return cnt;
}

ll MOD = 1e9 + 7;

int main()
{
	
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		vector<ll> cnt1(26),cnt2(26);
		bool ch = false;
		bool chh = false;
		int pos = -1;
		for (int i = 0; i < n; i++) {
			if (!ch && s1[i] != s2[i]) {
				pos = i;
				ch = true;
			}
			else if (!chh && ch && s1[i] != s2[i]) {
				if (s1[i] == s1[pos] && s2[i] == s2[pos]) {
					chh = true;
				}
				else break;
			}
			else if (chh && s1[i] != s2[i]) {
				chh = false;
				break;
			}
		}

		
		


		/*for (int i = 0; i < 26; i++) {
			if (abs(cnt1[i]-cnt2[i]) == 2) ch++;
		}*/

		if (chh) {
			cout << "Yes" << endl;

		}
		else cout << "No" << endl;



		

	}

}


