#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<vector>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
#define LL long long
#define pii pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
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
	int T = read();
	while(T--){
		int a = read(),b = read(),c = read(),d = read(),k = read();
		int sum1 = (a % c == 0 ? a / c : a / c + 1);
		int sum2 = (b % d == 0 ? b / d : b / d + 1);
		if(sum1 + sum2 > k) puts("-1");
		else printf("%d %d\n",sum1,sum2);
	}
	return 0;
}

