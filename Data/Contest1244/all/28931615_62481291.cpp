#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

typedef  long long  int ll;
typedef  long double ld;

#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll set<ll>
#define vpll vector<pll>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ln length()
#define M 1000000007
ll n,k;
string s;
ll ch[200005],st[200005],en[200005];
vpll rgs;

ll prv(ll i) {
	if(i == 0) return n-1;
	return i-1;
}
ll nxt(ll i) {
	if( i == n-1) return 0;
	return i+1;
}
char flip(char c) {
	if(c == 'W') return 'B';
	return 'W';
}
ll distost(ll ps,ll st) {
	if(st <= ps) return ps - st + 1;
	return n-st + ps+ 1;
}
ll distto(ll ps, ll en) {
	if(ps <= en) return en - ps + 1;
	return n-ps + en + 1;
}
ll getlen(ll ps,ll st, ll en) {
	ll dtst=distost(ps,st);
	ll dten=distto(ps,en);
	return min(dtst,dten);
}
int main() {
    ios :: sync_with_stdio(false); cin.tie(0);
    cin>>n>>k>>s;
    ll tt = 0;
    rep(i,0,n-1) {
 		if(s[i] == s[prv(i)] || s[i] == s[nxt(i)]) continue;
 		ch[i] = 1;   	
    	tt++;
    }
    if(tt == n) {
    	rep(i,0,n-1) {
    		if(k%2) cout<<flip(s[i]);
    		else cout<<s[i];
    	}
    	cout<<'\n';
    	return 0;
    }

    rep(i,0,n-1) {
    	if(!ch[i]) continue;
    	ll j = i;
    	while(j <= n-1 && ch[j]) j++;
    	j--;
    	rep(kk,i,j) {
    		st[kk] = i;
    		en[kk] = j;
    	}
    	i = j;
    }
    if(ch[0] && ch[n-1]) {
    	ll v = st[n-1];
    	ll u = en[0];
    	rep(i,v,n-1) en[i] = u;
    	rep(i,0,u) st[i] = v; 
    }

    rep(i,0,n-1) {
    	if(!ch[i]) {
    		cout<<s[i];
    		continue;
    	}
    	ll chs = getlen(i,st[i],en[i]);
    	char nw = s[i];
    	if(chs%2) nw = flip(nw);
    	if(k >= chs) cout<<nw;
    	else {
    		if(k%2) cout<<flip(s[i]);
    		else cout<<s[i];
    	}
    }
    cout<<'\n';
}
