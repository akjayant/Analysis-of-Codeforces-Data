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
int n,x[N];
ll a,b;
int main()
{
	fast();
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	sort(x,x+n);
	for(int i=0;i<n/2;i++)a+=x[i];
	for(int i=n/2;i<n;i++)b+=x[i];
	cout<<a*a+b*b<<endl;
	return 0;
}