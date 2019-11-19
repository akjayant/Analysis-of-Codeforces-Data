#include<bits/stdc++.h>
using namespace std;
bool data[20][20];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool israndom(int mask, int n,int m) {
	int c,I,J,t = n*m;
	for(int i=0;i<t;++i) {
		data[i/m][i%m] = (mask & (1<<i)) > 0;
	}
	/*
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j){
			cout <<data[i][j];
		}
		cout << endl;
	}
	cout << endl;*/
	for(int i=0;i<n;++i) {
		for(int j=0;j<m;++j) {
			c = 0;
			for(int k=0;k<4;++k) {
				I = i + dx[k];
				J = j + dy[k];
				if(I<n)
					if(I>=0)
						if(J<m)
							if(J>=0) 
								if(data[i][j] == data[I][J])
									c++;
			}
			if(c>1) return false;
		}
	}
	//cout << "ok" << endl;
	return true;
}
int a[100001];
int main(int argc, char const *argv[]){
	/*long long ans;
	int n,m;
	while(true) {
		cin >>n >>m ;
	int t = n*m;
	ans = 0;
	for(int mask = 0;mask < (1<<t); ++mask) {
		if(israndom(mask,n,m))
			ans++;
	}
	cout << ans << endl;
	}*/
	int t,n,m, modulo = 1e9+7;
	scanf("%d %d", &n,&m);
	a[1] = 2;
	a[2] = 2;
	t = max(n,m);
	for(int i=3;i<=t;++i) 
		a[i] = (a[i-1] +a[i-2]) % modulo;
	t = 2;
	for(int i=1;i<n;++i)
		t = (t + a[i]) % modulo;
	for(int i=1;i<m;++i)
		t = (t + a[i]) % modulo;
	printf("%d\n", t);	
	return 0;
}	