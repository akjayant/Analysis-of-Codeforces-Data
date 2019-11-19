#include<bits/stdc++.h>

using namespace std;
const int MAXN = 100100;
#define int long long

int a,b;
int memo[50][2][2][2][2];

int pd(int pos,int a1,int a2,int b1,int b2){
	
	if(pos < 0) return 1;
	if(memo[pos][a1][a2][b1][b2] != -1) return memo[pos][a1][a2][b1][b2];
	
	int g = ((long long) 1 << pos);
	g = (g & a);
	if(g > 0) g = 1;
	
	int h = ((long long) 1 << pos);
	h = (h & b);
	if(h > 0) h = 1;
	
	int r = 0;
	
	for(int i = 0;i <= 1;i++){
		for(int j = 0;j <= 1;j++){
			int x,y,w,z;
			x = a1 , y = a2 , w = b1 , z = b2; 
			
			if(i == 1 && j == 1) continue;
			if(i == 1 && h == 0 && a2 == 1) continue;
			if(j == 1 && h == 0 && b2 == 1) continue;
			if(i == 0 && g == 1 && a1 == 1) continue;
			if(j == 0 && g == 1 && b1 == 1) continue;
			
			if(i == 0 && h == 1) y = 0;
			if(j == 0 && h == 1) z = 0;
			if(i == 1 && g == 0) x = 0;
			if(j == 1 && g == 0) w = 0;
			
			r += pd(pos - 1,x,y,w,z); 
		}
	}  
	
	return memo[pos][a1][a2][b1][b2] = r;
}

signed main(){
	int t;
	cin >> t;
	
	while(t --){
		memset(memo,-1,sizeof memo);
		cin >> a >> b;
		cout << pd(32,1,1,1,1) << endl;
	}
}