#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define pb push_back

#define N 100003

ll n, v[N];
ll k;

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> v[i];

	sort(v + 1, v + n + 1);
	ll l = 1, r = n, nr1 = 1, a = v[1], b = v[n], nr2 = 1;
	while(k && l != r){
		if(nr1 < nr2){
			ll dif = v[l + 1] - a;
			if(dif * nr1 > k){
				a += k / nr1;
				break;
			}
			else
				k -= dif * nr1, a = v[++l], nr1 ++;
		}
		else{
			int dif = b - v[r - 1];
			if(dif * nr2 > k){
				b -= k / nr1;
				break;
			}
			else
				k -= dif * nr2, b = v[--r], nr2 ++;
		}
	}

	cout << b - a;
}