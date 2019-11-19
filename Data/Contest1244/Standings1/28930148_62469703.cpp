#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long LL;

LL t,n,m,k;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t --){
		cin >> n;
		LL lmx = n + 1,rmx = 0;
		cin >> s; s = ' ' + s;
		for(LL i = 1;i <= n;i ++){
			if(s[i] == '1'){
				lmx = min(lmx,i);
				rmx = max(rmx,i);
			}
		}
		if(!rmx){
			cout << n << endl;
			continue;
		}
		LL ans = (rmx - lmx + 1) * 2 + max(lmx - 1LL,n - rmx) * 2;
		cout << ans << endl;
	}
	return 0;
}