#include <bits/stdc++.h>
#define fs first
#define sc second
#define mx 100005
#define mod 1000000007
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define all(a) a.begin(),a.end()
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int a[n][n];
	for(int i = 0; i<n; i++)
	{
		int val;
		if(i&1) val = (i+1)*n;
		else val = i*n+1;
		for(int j = 0; j<n; j++){
			a[j][i] = val;
			if(i&1) val--;
			else val++;
		}
	}
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}