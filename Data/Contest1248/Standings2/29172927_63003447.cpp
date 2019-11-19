#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
 
int sufl[N], sufm[N], prel[N], prem[N], a[N];

int calc(string s){
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(s[i] == '(')	a[i] = 1;
		else	a[i] = -1;
	}
	for(int i = 0; i < n; i++){
		if(i == 0){
			prel[i] = a[i];
			prem[i] = a[i];
		}
		else{
			prel[i] = a[i] + prel[i-1];
			prem[i] = min(prem[i-1], prel[i]);
		}
	}
	for(int i = n-1; i >= 0; i--){
		if(i == n-1){
			sufl[i] = a[i];
			sufm[i] = a[i];
		}
		else{
			sufl[i] = a[i] + sufl[i+1];
			if(a[i] == -1)	sufm[i] = min(-1, sufm[i+1]-1);
			else	sufm[i] = 1 + sufm[i+1];
		}
	}
	int mx = 0;
	if(prem[n-1] == 0 && prel[n-1] == 0)	mx++;
	for(int i = 0; i < n-1; i++){
		if(sufm[i+1] >= 0 && sufl[i+1] + prem[i] == 0 && sufl[i+1] + prel[i] == 0)
			mx++;
	}
	return mx;
}

signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;	cin >> n;
	string s;	cin >> s;
	int ans = 0, l = 0, r = 0;
	ans = max(ans, calc(s));
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			string t = s;
			swap(t[i], t[j]);
			int p = calc(t);
			if(p > ans){
				ans = p;
				l = i;	r = j;
			}
		}
	}	
	cout << ans << endl;
	cout << l+1 << " " << r+1 << endl;
	return 0;
}