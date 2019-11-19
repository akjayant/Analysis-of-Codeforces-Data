#include<bits/stdc++.h>
using namespace std;

#define db double
#define MAXN 200005
#define int long long

inline int read()
{
    register int x = 0 , ch = getchar();
    while( !isdigit( ch ) ) ch = getchar();
    while( isdigit( ch ) ) x = x * 10 + ch - '0' , ch = getchar();
    return x;
}

int n,m;
int x,y;
int l,r;
int f[105][4][4];

int getans(int x,int y) {
	memset(f,0,sizeof(f));
	f[0][0][0] = f[0][1][0] = f[0][0][1] = f[0][1][1] = 1;
//	cout<<"------"<<x<<" "<<y<<"-------\n";
	
	for(int i = 1; i <= 31; i ++) {
		bool a = x&(1ll<<(i-1)),b = y&(1ll<<(i-1));
/*	if(i <= 5) {
			cout<<a<<" "<<b<<"\n";
		}
*/		f[i][0][0] =  3*f[i-1][0][0];
		//cout<<f[i][0][0]<<"?\n";
		if(b == 1) {
			f[i][0][1] = 2*f[i-1][0][0] + f[i-1][0][1];
		} else {
			f[i][0][1] = f[i-1][0][1]*2;
		}
		
		if(a == 1) {
			f[i][1][0] = 2*f[i-1][0][0] + f[i-1][1][0];
		} else {
			f[i][1][0] = f[i-1][1][0]*2;
		}
		
		if(a == 0 && b == 0) {
			f[i][1][1] = f[i-1][1][1];
		}
		if(a == 0 && b == 1) {
			f[i][1][1] = f[i-1][1][0] + f[i-1][1][1];
		}
		if(a == 1 && b == 0) {
			f[i][1][1] = f[i-1][0][1] + f[i-1][1][1];
		}
		if(a == 1 && b == 1) {
			f[i][1][1] = f[i-1][0][0] + f[i-1][1][0] + f[i-1][0][1];
		} 
	//	if(i <= 5)
	//		cout<<i<<" "<<f[i][0][0]<<" "<<f[i][0][1]<<" "<<f[i][1][0]<<" "<<f[i][1][1]<<"\n";
	}
	return f[31][1][1];
}

void rd()
{
	cin >> l >> r;
//	cout<<getans(l-1,r)<<"\n";
//	return;
//	cout<<getans(r,r) <<" "<< getans(l-1,r) <<" "<< getans(r,l-1) <<" "<< getans(l-1,l-1)<<"\n";
//	cout<<getans(99,99)<<"\n";
	int ans = 0;
	if(l == 0) ans = getans(r,r);
	else ans = getans(r,r) - getans(l-1,r) - getans(r,l-1) + getans(l-1,l-1);
	cout<<ans<<"\n";
}

signed main()
{
	int T;
	cin >> T;
	while(T --) {
		rd();
	}
	return 0;
}
/*
3
1 4
323 323

1
2 4 

1
1 1925

1
1926 3243
*/