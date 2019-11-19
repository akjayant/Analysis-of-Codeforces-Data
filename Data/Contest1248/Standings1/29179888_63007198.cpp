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
const int N = 10005;
int n;
int ans;
char s[N];
char ss[N];
int from[N];
char sss[N];
int b[N];
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
inline bool check(){
	int sum = 0;
	for(int i = 1;i <= n;++i){
		if(ss[i] == '('){
			sum++;
		}
		else sum--;
		if(sum < 0) return 0;
	}
	return 1;
}
inline void gg(){
	int id,maxx = 0,cnt = 0;
	for(int i = n;i >= 1;--i){
		b[i] = b[i + 1];
		if(ss[i] == '(') b[i]++;
		else b[i]--;
		if(b[i] > maxx) maxx = b[i],id = i;
	}
	for(int i = id;i <= n;++i) sss[++cnt] = ss[i];
	for(int i = 1;i < id;++i) sss[++cnt] = ss[i]; 
}
inline int work(){
	int from = 1;
	int sum = 0;
	int res = 0;
	for(int i = 1;i <= n;++i){
		if(ss[i] == '('){
			if(sum == 0) res++;
			sum++;
		}
		else sum--;
	}
	return res;
}
int main(){
	n = read();
	scanf("%s",s + 1);
	int num1 = 0,num2 = 0;
	for(int i = 1;i <= n;++i){
		if(s[i] == '(') num1++;
		else num2++;
	}
	if(num1 != num2){
		puts("0");
		puts("1 1");
		return 0; 
	}
	for(int i = 1;i <= n;++i) ss[i] = s[i],from[i] = i;
	while(!check()){
		char z = s[1];int zz = from[1];
		for(int i = 1;i <= n;++i) s[i] = s[i + 1],from[i] = from[i + 1];
		s[n] = z;from[n] = zz;
		for(int i = 1;i <= n;++i) ss[i] = s[i];
	}	
	
//			for(int k = 1;k <= n;++k) printf("%c",ss[k]);puts("");
//			for(int k = 1;k <= n;++k) printf("%d ",from[k]);puts(""); 	
	int x = 1,y = 1;
	int ans = work();
	for(int i = 1;i <= n;++i){
		for(int j = i + 1;j <= n;++j){
			swap(s[i],s[j]);
			for(int k = 1;k <= n;++k) ss[k] = s[k];
			if(!check()){
				gg();
				for(int k = 1;k <= n;++k) ss[k] = sss[k];	
	//			printf("GG\n");
			}
//			if(i == 7 && j == 8){
//				for(int k = 1;k <= n;++k) printf("%c",ss[k]);puts("");	
//			}
			int res = work();
//			printf("%d %d %d\n",from[i],from[j],res);
			if(res > ans) ans = res,x = from[i],y = from[j];
			swap(s[i],s[j]);
		}
	}
	printf("%d\n",ans);
	printf("%d %d\n",x,y);
    return 0;
}
/*
8
))(())((
*/ 

