#include<stdio.h>
#include<bits/stdc++.h>
#define LL long long
#define rel(i,s,n) for(int i=s;i<n;i++)
#define rep(i,s,n) for(int i=s;i<=n;i++)
#define red(i,s,n) for(int i=s;i>=n;i--)
#define res(i,x) for(int i=Last[x];i;i=Next[i])
using namespace std;
int t,n,m,tmp;
int p[100005],q[100005];
int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		LL ans = 0, cnt1 = 0, cnt2 = 0;
		cin >> n;
		rep(i,1,n){
			cin >> p[i];
			if(p[i]%2==0)cnt1++;
	   		else cnt2++;
		}
		cin>>m;
		rep(i,1,m){
			cin >> q[i];
			if(q[i]%2==1)ans+=cnt2;
	   		else ans+=cnt1;
		}
		cout << ans << endl;// << endl;
	}
}