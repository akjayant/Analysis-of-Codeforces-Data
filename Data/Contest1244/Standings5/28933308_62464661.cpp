#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int > pp;

 
#define sz(x) (int)x.size() 
#define PI acos(-1)
int const N=5e5+10;
int  oo = 1e9;
int mod = oo+7;
ll OO = 3e18;


void solve(){
	int a,b,c,d,k;
	cin>>a>>b>>c>>d>>k;
	int y=(a+c-1)/c,g=(b+d-1)/d;
	if(y+g>k)cout<<-1<<'\n';
	else cout<<y<<' '<<g<<'\n';

}
int main() {
	#ifndef ONLINE_JUDGE
		freopen("a.in","r",stdin);
		freopen("a.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;

	while(t--)solve();
	
	return 0;
}

