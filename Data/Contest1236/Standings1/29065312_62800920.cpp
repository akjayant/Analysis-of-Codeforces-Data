#include <bits/stdc++.h>
#define VI vector<int>
#define pb push_back
#define LL long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
int A[310][310];
int main(){
	scanf("%d", &n);
	int v = 0;
	for(int i = 0; i < n; i++){
		int a = (i&1)?(n-1):(0),
		b = (i&1)?(-1):(n),
		c = (i&1)?(-1):(1);
		for(int j = a; j != b; j += c){
			A[j][i] = ++v;
		}
	}
	int worst = INF;		
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}