#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define int long long

int n,p,w,d;
int fl;

void rd()
{
	cin >> n >> p >> d >> w;
/*	if(w > d) 
	{
		fl = 1;
		swap(w,d);
	}*/
}

int x = -1,y = 0,z = 0;

signed main()
{
	rd();
	for(int i = 0; i < d; i ++)
	if(i*w%d == p%d) {
		x = i;
		break;
	}
	if(x == -1) {
		cout<<"-1";
		return 0;
	}
	y = (p-x*w)/d;
	z = n-x-y;
	if(z < 0 || y < 0) {
		cout<<-1;
		return 0;
	}
//	if(fl) swap(x,y);
	cout<<y<<" "<<x<<" "<<z<<"\n";
	return 0;
}
/*
9 6 3 7

*/