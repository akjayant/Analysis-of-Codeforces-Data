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
const int N = 5e5 + 3;
int n,m;
int p[N],q[N];
int main(){
	int T = read();
	while(T--){
		LL ji1 = 0,ou1 = 0,ji2 = 0,ou2 = 0;
		n = read();
		for(int i = 1;i <= n;++i){
			p[i] = read();	
			if(p[i] & 1) ji1++;
			else ou1++;
		}
		m = read();
		for(int i = 1;i <= m;++i){
			q[i] = read();	
			if(q[i] & 1) ji2++;
			else ou2++;
		}
		printf("%lld\n",ji1 * ji2 + ou2 * ou1);
	}
    return 0;
}

