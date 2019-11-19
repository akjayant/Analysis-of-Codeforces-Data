#include<bits/stdc++.h>
using namespace std;

#define LL long long
//#define int long long
#define MAXN 1005

int T;
char a[MAXN];
int n,m;

void rd()
{
	cin >> n;
	scanf("%s",a+1);
}

signed main()
{
	int T;
	cin >> T;
	while(T --)
	{
		//cout<<T<<"\n";
		rd();
		int l = 0,r = 0;
		for(int i = 1; i <= n; i ++) {
			if(a[i] == '0') l ++;
			else break;
		}
		for(int i = n; i >= 1 && a[i] == '0'; i --,r ++) ;
		if(l == n) {
			cout<<n<<"\n";
			continue;
		} 
		cout<<2*(n-min(l,r))<<"\n";
	}
	return 0;
}
/*
1
5
01100
*/