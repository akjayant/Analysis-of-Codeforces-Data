#include<bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define pb push_back
#define ms(a, x) memset(a, x, sizeof(a))

#define endl '\n'
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> pii;

const int mod=1e9+7;
const int N=1e5+5;
ll a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	string st;
	cin>>st;
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=1e5;i++){
		a[i]=(a[i-1]+a[i-2])%mod;
	}
	vector<int> cnt;
	int tmp=0;
	forn(i,st.length()){
		if(st[i]=='u'){
			if(st[i-1]=='n'){
				cnt.pb(tmp);
				tmp=0;
			}
			tmp++;
		}else if(st[i]=='n'){
			if(st[i-1]=='u'){
				cnt.pb(tmp);
				tmp=0;
			}
			tmp++;
		}else{
			if(tmp) cnt.pb(tmp);
			tmp=0;
		}
		if(st[i]=='w'||st[i]=='m'){
			cout<<0;
			return 0;
		}
	}
	if(tmp) cnt.pb(tmp);
	ll ans=1;
	for(auto it:cnt) ans=ans*a[it]%mod;
	cout<<ans;
    return 0;
}
