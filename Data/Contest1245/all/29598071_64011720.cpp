#include<bits/stdc++.h>
int l,r,t;
typedef long long ll;
inline ll ca2(int x){
	return x ? ca2(x - 1) * 3 : 1;
}
inline ll ca(int a,int b,int i,int j){
	if(i > j) return ca(b,a,j,i);
	ll ret = ca2(i);
	for(int x = i;x < j;++x) if((a >> x & 1) == 0) ret <<= 1;
	return ret;
}
inline ll calc(int l,int r){
	ll ans = 0; ++l; ++r;
	for(int i = 30;i >= 0;--i) if(l >> i & 1)
		for(int j = 30;j >= 0;--j) if(r >> j & 1)
			if((l >> i + 1 << i + 1 & r >> j + 1 << j + 1) == 0) {
				int a = l >> i + 1 << i + 1;
				int b = r >> j + 1 << j + 1;
				ans += ca(a,b,i,j);
			}
	return ans;
}
int main(){
	std::cin >> t;
	for(;t--;){
		std::cin >> l >> r;
		std::cout << calc(r,r) - calc(l - 1,r) * 2 + calc(l - 1,l - 1) << '\n';
	}
}
