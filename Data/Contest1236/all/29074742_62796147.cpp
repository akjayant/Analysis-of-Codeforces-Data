#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
inline int read(){
	register int res=0, c;
	while(c=getchar(), c<'0'||c>'9');
	do{
		res=(res*10)+(c^48);
	} while(c=getchar(), c>='0'&&c<='9');
	return res;
}
const int mod = 1e9+7;
int res[330][330], cmp[330][330], N;
int F(int(* s)[330], int x, int y){
	int ans = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(s[x][i]<s[y][j])ans++;
		}
	}
	return ans;
}
int main() {
	N=read();
	for(int i=1; i<=N; i++)for(int j=1; j<=N; j++){
		if(i&1)res[j][i]=(i-1)*N+N+1-j;
		else res[j][i]=(i-1)*N+j;
	}
	/*while(true){
		memcpy(cmp, res, sizeof res);
		for(int t=1; t<1000; t++){
			int i = rand()%N+1, x = rand()%N+1, y = rand()%N+1;
			swap(cmp[x][i], cmp[y][i]);
		}
		int sR=1110, sC=1110;		
		for(int x=1; x<=N; x++)for(int y=1; y<=N; y++){
			sR=min(sR,F(res, x, y));
			sC=min(sC,F(cmp, x, y));
		}
		if(sR!=sC){
			return 0;
		}
	}*/
	for(int i=1; i<=N; i++)for(int j=1; j<=N; j++){
		printf("%d%c", res[i][j], j==N?'\n':' ');
	}
	return 0;
}