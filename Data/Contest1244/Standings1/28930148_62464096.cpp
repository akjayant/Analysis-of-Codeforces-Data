#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long LL;

LL t,a,b,c,d,k;
LL ans = 0;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t --){
		cin >> a >> b >> c >> d >> k;
		LL flg = 0;
		for(LL i = 0;i <= k;i ++){
			if(c * i >= a && d * (k - i) >= b){
				cout << i << ' ' << k - i << endl;
				flg = 1;
				break;
			}
		}
		if(!flg) cout << -1 << endl;
	}
	return 0;
}