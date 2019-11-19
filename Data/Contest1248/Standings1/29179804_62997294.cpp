#include <bits/stdc++.h>

using namespace std;
const int N=1e5+10;

int n;
char s[N];
int pre[N], suf[N];

int solve() {
	stack<char> st;
	pre[0]=1;
	for(int i=1; i<=n; i++) {
		if (s[i]==')') {
			if (st.empty()) ;
			else {
				st.pop();
			}
		}
		else {
			st.push('(');
		}
		if (st.empty()) pre[i]=1;
		else pre[i]=0;
	}
	suf[n+1]=1;
	while(!st.empty()) st.pop();
	for(int i=n; i>=1; i--) {
		if (s[i]=='(') {
			if (st.empty()) ;
			else st.pop();
		}
		else {
			st.push(')');
		}
		if (st.empty()) suf[i]=1;
		else suf[i]=0;
	}
	int ret=0;
//	cout<<(s+1)<<endl;
//	for(int i=1; i<=n; i++) {
//		cout<<pre[i]<<':';
//	}
//	cout<<endl;
//	for(int i=1; i<=n; i++) {
//		cout<<suf[i]<<':';
//	}
//	cout<<endl;
	for(int i=1; i<=n; i++) {
		if (pre[i-1]&&suf[i]) ret++;
	}
//	cout<<ret<<endl;
	return ret;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if (s[i]=='(') cnt++;
		else cnt--;
	}
	if (cnt) {
		cout<<0<<endl;
		cout<<1<<' '<<1<<endl;
		return 0;
	}
	int ans=-1, L, R;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			swap(s[i], s[j]);
//			cout<<i<<' '<<j<<endl;
			int cur=solve();
			if (cur>ans) {
				ans=cur;
				L=i;
				R=j;
			}
			swap(s[i], s[j]);
		}
	}
	cout<<ans<<endl;
	cout<<L<<' '<<R<<endl;
	return 0;
}