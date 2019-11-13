#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int MAXN = 300 + 10;

int N;
int a[MAXN][MAXN] , lasx , lasy;

int main(){
	cin >> N;
	
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(i & 1) 
			for(int j = 1; j <= N; j++) a[j][i] = ++cnt;
		else
			for(int j = N; j >= 1; j--) a[j][i] = ++cnt;
	}
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++) {
			cout << a[i][j] << " ";
			if(j == N) puts("");
		}
	return 0;
}
