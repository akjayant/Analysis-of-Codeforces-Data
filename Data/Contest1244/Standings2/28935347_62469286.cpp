#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

#define N 100003

int main(){
	int t, a, n ,c ,d;
	string s;
	cin >> t;
	while(t --){
		cin >> n;
		cin >> s;
		a = n;
		for(int i = 0; i < n; i ++)
			if(s[i] == '1')
				a = max(a, 2 * max(i + 1, n - i));
		cout << a << "\n";
	}
}