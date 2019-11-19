#include<bits/stdc++.h>
#define ll long long
#define N 200050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,k,wl,wr,l,r,a[N],ans,sum;
char s[N];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;i++)
	if(s[i]==s[(i+1)%n])
	a[i]=a[(i+1)%n]=(k+1)*(s[i]=='W'?1:-1);
	for(int i=0;i<n;i++)
	if(abs(a[(i+1)%n])<abs(a[i])-1)
	a[(i+1)%n]=a[i]/abs(a[i])*(abs(a[i])-1);
	for(int i=0;i<n;i++)
	if(abs(a[(i+1)%n])<abs(a[i])-1)
	a[(i+1)%n]=a[i]/abs(a[i])*(abs(a[i])-1);
	for(int i=n-1;i>=0;i--)
	if(abs(a[(i+1)%n])-1>abs(a[i]))
	a[i]=a[(i+1)%n]/abs(a[(i+1)%n])*(abs(a[(i+1)%n])-1);
	for(int i=n-1;i>=0;i--)
	if(abs(a[(i+1)%n])-1>abs(a[i]))
	a[i]=a[(i+1)%n]/abs(a[(i+1)%n])*(abs(a[(i+1)%n])-1);
	for(int i=0;i<n;i++)
	if(a[i])
	if(a[i]>0)
	cout<<'W';
	else
	cout<<'B';
	else
	if(k%2)
	if(s[i]=='W')
	cout<<'B';
	else
	cout<<'W';
	else
	cout<<s[i];
	cout<<endl;
	for(int i=0;i<n;i++)
	
	return 0;
}
