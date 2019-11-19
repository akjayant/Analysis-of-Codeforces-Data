#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000 + 10;
const int mod = 1e9 + 7;
int ansa[MAX],ansb[MAX],ansc[MAX];

int main()
{
	ansa[1] = 2 ;
	ansb[1] = 0;
	ansc[1] = 0;
	ansa[2] = 4;
	ansb[2] = 2;
	ansc[2] = 2;
	
	
	for(int i=3;i<=1e5 + 5;i++){
		ansa[i] = ansa[i-1] + ansa[i-2];
		ansa[i]%=mod;
		ansb[i] = ansb[i-1] + ansb[i-2];
		ansb[i]%=mod;
		ansc[i] = (ansc[i-1] + ansb[i])%mod;
	}
	long long x,y;
	scanf("%d%d",&x,&y);
	cout<<(ansa[x]+ansc[y])%mod<<endl;
	return 0;
 } 