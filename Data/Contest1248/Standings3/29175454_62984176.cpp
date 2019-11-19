#include <bits/stdc++.h>
 
using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
#define rfr(i,x,y) for(int i=x;i>=y;i--)
#define int long long
const int N=1e6,M=6,INF=1e9,MOD=1e9+7,L=10;
int mas[N];
void solve()
{
	int n;
	cin>>n;
	int q0=0,q1=0;
	int a;
	fr(i,0,n){cin>>a;if(a%2==0)q0++;else q1++;}
	cin>>n;
	int w0=0,w1=0;
	fr(i,0,n){cin>>a;if(a%2==0)w0++;else w1++;}
	cout<<q0*w0+q1*w1<<'\n';
}
main()
{
	int n;
	cin>>n;
	fr(i,0,n)cin>>mas[i];
	sort(mas,mas+n);
	int sum1=0,sum2=0;
	fr(i,0,n/2)sum1+=mas[i];
	fr(i,n/2,n)sum2+=mas[i];
	cout<<sum1*sum1+sum2*sum2;
}