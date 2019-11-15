/*
* @Author: wxyww
* @Date: 2019-11-01 22:01:43
* @Last Modified time: 2019-11-01 22:38:31
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstring>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

ll read() {
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int main() {
	int T = read();
	while(T--) {
		int a = read(),b = read();
		puts(__gcd(a,b) == 1 ? "Finite" : "Infinite");
	}

	return 0;
}