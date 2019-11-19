#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define qaq std::ios::sync_with_stdio(false);
#define qwq cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int N=1e5+5;
inline void fast(){qaq qwq;}
int T,n,m,x[N],y[N];
ll ans;
int main()
{
	fast();
	cin>>T;
	while(T--)
	{
		ll a1=0,b1=0,a2=0,b2=0;
		cin>>n;
		for(int i=0;i<n;i++)cin>>x[i],a1+=(x[i]%2==0),b1+=(x[i]%2==1);
		cin>>m;
		for(int j=0;j<m;j++)cin>>y[j],a2+=(y[j]%2==0),b2+=(y[j]%2==1);
		cout<<a1*a2+b1*b2<<endl;
	}
	return 0;
}