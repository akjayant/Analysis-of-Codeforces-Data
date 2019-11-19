#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;

LL n,k;
LL a[500005];
LL seq[500005] = {0},cnt = 0;
LL ans = 0;
map <LL,LL> mp;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(LL i = 1;i <= n;i ++){
		cin >> a[i];
		if(mp.find(a[i]) == mp.end()) seq[++ cnt] = a[i];
		mp[a[i]] = 0;
	}
	for(LL i = 1;i <= n;i ++) mp[a[i]] ++;
	sort(seq + 1,seq + 1 + cnt);
//	for(LL i = 1;i <= cnt;i ++) cout << i << ' ' << seq[i] << ' ' << mp[seq[i]] << endl;
	LL l = 1,r = cnt;
	while(1){
		if(l == r) break;
		if(!k) break;
		if(mp[seq[l]] < mp[seq[r]]){
			LL tmp = mp[seq[l]] * (seq[l + 1] - seq[l]);
			LL num = mp[seq[l]];
			if(tmp <= k){
				k -= tmp;
				l ++;
				mp[seq[l]] += num;
			}
			else{
				seq[l] += k / mp[seq[l]];
				k = 0;
				break;
			}
		}
		else{
			LL tmp = mp[seq[r]] * (seq[r] - seq[r - 1]);
			LL num = mp[seq[r]];
			if(tmp <= k){
				k -= tmp;
				r --;
				mp[seq[r]] += num;
			}
			else{
				seq[r] -= k / mp[seq[r]];
				k = 0;
				break;
			}
		}
	}
	cout << seq[r] - seq[l] << endl;
	return 0;
}
/*
10 100000000000
1000000 1 1000000 10000 100 10000 100000000 10000000 100 10 2 2
*/