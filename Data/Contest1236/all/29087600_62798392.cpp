#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define ll long long
#define ull unsigned long long
#define sscc ios::sync_with_stdio(false);cin.tie(0);
#define ms(a) memset(a,0,sizeof(a))
#define mss(a) memset(a,-1,sizeof(a))
#define msi(a) memset(a,inf,sizeof(a))
using namespace std;

int a[305][305];

int main()
{
	sscc;
	int n;
	cin>>n;
	int cnt=1;
	int flag=1;
	for(int i=1;i<=n;i++){
		if(flag==1)	for(int j=1;j<=n;j++)	a[j][i]=cnt++;
		if(flag==0)	for(int j=n;j>=1;j--)	a[j][i]=cnt++;
		flag^=1;	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d%c",a[i][j]," \n"[j==n]);
		}
	}
	return 0;
}
/*
1 6 7
2 5 8
3 4 9
*/
