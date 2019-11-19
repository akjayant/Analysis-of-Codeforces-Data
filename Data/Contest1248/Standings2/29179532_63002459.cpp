//Code of C#oder Born_Clear
#include <bits/stdc++.h>
using namespace std;
#define loop(n) for(int i=0;i<n;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define ll long long
#define s(x) scanf("%d", &x)
#define sd(x) scanf("%lf", &x)
#define sl(x) scanf("%lld", &x)
#define mod 1000000007
#define fi first
#define se second
#define p(x) printf("%d",x)
#define pl(x) printf("%lld", x)
#define pd(x) printf("%lf", x)
#define pn() printf("\n")
#define vi(v) vector<int>v
#define vl(v) vector<long long int>v
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define len(s) s.length()
void input(int n,int a[]){loop(n)cin>>a[i];}
ll bin_expo(ll A, ll B, ll M){ll res = 1LL;while (B > 0){if(B % 2 == 1){res = (res * A) % M;}A = (A * A) % M; B = B / 2;}return res;}

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	string t;
	ll ans=0,l=0,r=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			t=s;
			swap(t[i],t[j]);
			int mini=INT_MAX;
			int cc=0;
			for(int k=0;k<t.length();k++)
			{
				if(t[k]=='(')
				{
					cc++;
				}
				if(t[k]==')')
				{
					cc--;
					mini=min(mini,cc);
				}
			}
			if(cc!=0)
				continue;
			int tmp=0;
			for(int k=n-1;k>=0;k--)
			{	
				if(t[k]==')')
					mini--;
				else
				{
					mini++;
					if(mini>=0)
						tmp++;
				}
			}
			// cout<<i<<" "<<j<<endl;
			// cout<<tmp<<endl;
			if(tmp>ans)
			{
				ans=tmp;
				l=i,r=j;
			}
			
		}
	}
	cout<<ans<<endl;
	cout<<l+1<<" "<<r+1<<endl;
	return 0;
}