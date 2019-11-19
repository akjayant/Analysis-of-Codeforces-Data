#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;
int n;
string s;

int f(int l, int r){
	string tr = s;
	swap(tr[l],tr[r]);
	vector<int> mn(n+1,0);
	vector<int> bal(n+1,0);
	int bl = 0;
	for(int i = 0; i < n; i++){
		if(tr[i]==')') bl--;
		if(tr[i]=='(') bl++;
		mn[i+1] = min(mn[i],bl);
		bal[i+1] = bl;		
	}
	
	int ans = 0;
	int mnx = 1e9;
	for(int i = n-1; i>=0; i--){
		int bal_here = bal[n] - bal[i];
		mnx = min(bal[i+1],mnx);
		if(mnx - bal[i] >= 0 && mn[i]+bal_here>=0) ans++;
		
	}
	return ans;
}


main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	int bal = 0;
	for(int i = 0; i < n; i++){
		if(s[i]==')') bal--;
		if(s[i]=='(') bal++;
	}
	if(bal!=0){
		cout<<"0\n1 1";
		return 0;
	}
	int ans = -1;
	int l = -1;
	int r = -1;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int tr = f(i,j);
			if(tr>ans){
				l = i;
				r = j;
				ans = tr;
			}
		}
	}
	cout<<ans<<"\n"<<l+1<<" "<<r+1;
}

