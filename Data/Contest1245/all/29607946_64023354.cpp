#pragma GCC optmize(2)
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;
 
#define ll long long int 
#define pb push_back
#define mp make_pair 
#define fi first 
#define se second 
#define pbb pop_back
#define pii pair<ll,ll>
 
ll read(){ 
	char ch;
 	for(ch = getchar();ch<0x30||ch>0x39;ch=getchar());
 	ll x = ch - 0x30;
	for(ch = getchar();ch>=0x30&&ch<=0x39;ch=getchar())
		x = x*10+ch-0x30;
 	return x;
}
ll check(ll x){
	ll re = 0;
	while(x){
		if(x&1) re++;
		x /= 2;
	}
	return re;
}
const ll mod = 1e9+7;
ll cnt[1000005];
int main(){
	cnt[1] = 1;cnt[2] = 2;
	for(int i=3;i<=100000;i++){
		cnt[i] = (cnt[i-1]+cnt[i-2])%mod;
	}
	string t ;cin >> t;
	t = t + "a";
	ll ans = 1;
	char cur = t[0];
	ll  c = 1;
	for(int i=1;i<t.length();i++){
		if(cur == t[i]) c++;
		else{
			if(cur == 'm'|| cur == 'w'){
				puts("0");return 0;
			}
			if(cur == 'n' || cur == 'u')
			ans = (ans*cnt[c])%mod;
			cur = t[i]; c = 1;
		}
	}
	cout << ans << endl;
}