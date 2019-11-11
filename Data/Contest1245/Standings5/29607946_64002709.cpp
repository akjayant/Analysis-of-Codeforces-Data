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
int main(){
	ll n = read();
	while(n--){
		ll len = read();
		ll rock = read(), paper = read() , sci = read();
		string t ; cin >> t;
		ll cur = 0;
		string ou = "";
		for(int i=0;i<t.length();i++){
			if(t[i] == 'R') {
				if(paper) {cur++;paper--;ou = ou+"P";}
				else ou = ou+" ";
			}
			else if(t[i] == 'S'){
				if(rock) {cur++;rock--;ou = ou+"R";}
				else ou  = ou + " ";
			}
			else {
				if(sci) {cur++;sci--;ou = ou + "S";}
				else ou = ou + " ";
			}
		}
		if(cur*2 >= len) {
			puts("YES");
			for(int i=0;i<len;i++){
				if(ou[i] != ' ') cout << ou[i];
				else if(rock) {cout << "R";rock--;}
				else if(paper) {cout << "P";paper--;}
				else {cout << "S";sci--;}
			}
			puts("");
		}
		else puts("NO");
	}
}