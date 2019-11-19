/****************************
Filename: FatMouse.cpp
Author: hbb
Create: 2019-10-20 17:03:40
 ****************************/
#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = INT_MAX >> 1;
typedef long long int LL;

LL a[maxn];

int main(){
	LL n, m;
	scanf("%lld %lld", &n, &m);
	a[1] = 2;
	a[2] = 4;
	for(int i = 3; i < maxn; i++){
		a[i] = (a[i - 1] + a[i - 2]) % mod;
	}
	LL temp = a[n];
	if(m == 1){
		printf("%lld\n", temp);
	}
	else{
		temp = (temp + 2) % mod;
		m--;
		if(m > 1){
			for(int i = 1; i <= m - 1; i++){
				temp = (temp + a[i]) % mod;
			}
		}
		printf("%lld\n", temp);
	}
}