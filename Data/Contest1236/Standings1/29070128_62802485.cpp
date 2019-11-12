#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;


//int a[90100];
int p[301][301];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			int u;
			if (i % 2 == 1) u = j; else u = n - j + 1;
			//a[(i - 1) * n + j] = u;
			p[u][i] = (i - 1) * n + j;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			printf("%d", p[i][j]);
			if (j == n) printf("\n");
				else printf(" ");
		}
	
	return 0;
}