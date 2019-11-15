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
ll gcd(ll a,ll b){
	while(a%b){
		ll tmp = a%b;
		a = b;
		b = tmp;
	}
	return b;
}
int main(){
	ll n = read();
	while(n--){
		ll x = read(),y = read();
		if(gcd(x,y) > 1) puts("Infinite");
		else puts("Finite");
	}
	return 0;
}