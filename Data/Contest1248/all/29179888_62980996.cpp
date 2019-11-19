#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<vector>
#include<ctime>
#define LL long long
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 3;
int n;
int a[N];
inline int read(){
	int v = 0,c = 1;char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') c = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		v = v * 10 + ch - 48;
		ch = getchar();
	}
	return v * c;
}
int main(){
	n = read();
	for(int i = 1;i <= n;++i) a[i] = read();
	LL sum1 = 0,sum2 = 0;
	sort(a + 1,a + n + 1);reverse(a + 1,a + n + 1);
	int l = 1,r = n;
	int x = (n & 1) ? n / 2 + 1 : n / 2;
	for(int i = 1;i <= x;++i) sum1 += 1ll * a[i];
	for(int i = x + 1;i <= n;++i) sum2 += 1ll * a[i];
	printf("%lld\n",sum1 * sum1 + sum2 * sum2);
    return 0;
}

