#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>

using namespace std;

int f[110][110][110];
int main(){

	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			for (int k = 0; k <= 100; k++){
				if (i >= 1 && j >= 2) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 2][k] + 3);
				if (j >= 1 && k >= 2) f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - 2] + 3);
			}
	int T;
	cin >> T;
	while (T--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		printf("%d\n", f[a][b][c]);
		
	}
	return 0;
}