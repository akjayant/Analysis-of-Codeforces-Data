#include <bits/stdc++.h>
using namespace std;
#define asp " " 
#define aps ''
#define one 1
#define two 2
#define dif !=
typedef long long ll;
const ll mod = 1e9 + 7;
vector<ll> safe;
string s;
void preProcess(){

	safe.push_back(one);
	safe.push_back(one);

	for(int i=two;i<100005;i++){
		ll val = safe[i-one];
		val %= mod;
		val += safe[i-two];
		val %= mod;
		safe.push_back(val);
	}
}

ll solve(){

	ll ans = one;
	char last = 'X';
	int cont = 0;
	int n = s.size();

	for(int i=0;i<n;i++){
		if(last == 'X'){
			if(s[i] == 'u'){
				last = 'u';
				cont = one;
			}
			else if(s[i] == 'n'){
				last = 'n';
				cont = one;
			}
		}
		else if(s[i] == last) cont++;
		else{
			ans = ans * safe[cont];
			ans %= mod;
			last = 'X';
			i--;
			cont = 0;
		}
	}

	ans = ans * safe[cont];
	ans %= mod;
	last = 'X';
	cont = 0;

	return ans;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	preProcess();

	cin >> s;
	bool ok = false;
	int n = s.size();
	for(int i=0;i<n;i++){

		if(s[i] == 'm'){
			ok = true;
			break;
		}
		else if(s[i] == 'w'){
			ok = true;
			break;
		}
	}

	if(ok){
		cout << 0 << endl;
		return 0;
	}

	cout << solve() << endl;

}