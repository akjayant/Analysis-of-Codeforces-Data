#include<bits/stdc++.h>
#define pb(x)push_back(x)
#define all(x) x.begin(), x.end()
#define cout2(x, y) cout << x << " " << y << endl
#define cout3(x, y, z) cout << x << " " << y << " " << z << endl
#define N 100001
#define MOD 1000000007

using namespace std;

int memo[N];

int main(){	
	
	string s;
	cin >> s;
	
	int n = s.size();
	
	memo[1] = memo[0] = 1;
	for(int i = 2; i <= n; i++)memo[i] = (memo[i - 1] + memo[i - 2])%MOD;
	
	long long ans = 1;
	bool found = false;
	
	for(int i = 0, j = 0; i < n; i++){
		
		if(s[i] == 'm' || s[i] == 'w')found = true;
			
		while(j < n && s[i] == s[j])j++;
		if(s[i] == 'n' || s[i] == 'u')ans = (ans * memo[j - i])%MOD;
		i = j - 1;
	}
	
	if(found)ans = 0;
	cout << ans << endl;

}
