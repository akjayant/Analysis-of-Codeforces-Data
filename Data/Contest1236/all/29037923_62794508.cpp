#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x,y) memset(x,y,sizeof(x))
const int M=2e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int a[1000][1000];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i==1) {
				if(j==1)
					a[i][j]=i;
				else {
					if(j&1)
						a[i][j]=a[i][j-1]+1;
					else
						a[i][j]=a[i][j-1]+2*n-1;
				}
			} else {
				if(j&1)
					a[i][j]=a[i-1][j]+1;
				else
					a[i][j]=a[i-1][j]-1;
			}
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			printf(j==n?"%d\n":"%d ",a[i][j]);
		}
	return 0;
}
