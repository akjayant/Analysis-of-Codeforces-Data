#include<bits/stdc++.h>
using namespace std;
double p[101],q[101];
int h[101];
int a[10][10];
int b[10][10];
int jp[101];
int main(){
	ios::sync_with_stdio(false);
	for(int i=9; i>=0 ;i--){
		for(int j=0; j<10 ;j++){
			cin >> a[i][j];
			if(j==0){
				if(i%2==0) b[i][j]=i*10+1;
				else b[i][j]=i*10+10;
			}
			else{
				if(i%2==0) b[i][j]=b[i][j-1]+1;
				else b[i][j]=b[i][j-1]-1;
			}
			if(a[i][j]!=0) jp[b[i][j]]=b[i+a[i][j]][j];
		}
	}
	p[100]=0;
	for(int i=1; i<=5 ;i++){
		for(int j=100-i+1; j<=100 ;j++) p[100-i]+=p[j];
		int j=100-i;
		p[j]/=6;
		p[j]+=1;
		p[j]=p[j]*6/i;
		q[j]=p[j];
	}
	for(int i=94; i>=1 ;i--){
		for(int j=1; j<=6 ;j++) p[i]+=q[i+j];
		int j=i;
		p[j]/=6;
		p[j]+=1;
		q[j]=p[j];
		if(jp[j]) q[j]=min(q[j],p[jp[j]]);
	}
	cout << fixed << setprecision(12) << p[1] << '\n';
}