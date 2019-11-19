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

int a[maxn];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	LL sum1 = 0;
	for(int i = 1; i <= n / 2; i++){
		sum1 += a[i];
	}
	LL sum2 = 0;
	for(int i = n / 2 + 1; i <= n; i++){
		sum2 += a[i];
	}
	printf("%lld\n", sum1 * sum1 + sum2 * sum2);
}