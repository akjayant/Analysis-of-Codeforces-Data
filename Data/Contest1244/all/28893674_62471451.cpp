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

using namespace std;
const int N = 2e3 + 3;
char s[N];
int n;
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
		n = read();
		scanf("%s",s + 1);
		int las = 0,fir = 0;
		for(int i = 1;i <= n;++i){
			if(!fir && s[i] == '1') fir = i;
			if(s[i] == '1') las = i;
		} 
		if(!fir){
			printf("%d\n",n);
			continue;	
		}
		else{
			int ans = las + max(n - las,las - 1) + 1;
			ans = max(ans,n - fir + 1 + max(n - fir,fir - 1) + 1);
			printf("%d\n",ans);	
		}
	}
	return 0;
}

