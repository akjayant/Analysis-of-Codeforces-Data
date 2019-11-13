#include<bits/stdc++.h>
#define ll long long
#define N 1000050
#define pi acos(-1)
#define mod 1000000007
#define endl '\n'
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
using namespace std;

ll t,n,k,l,r,a,b,c,ans,sum;
char s[200],m[200];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b>>c>>s;
		m0(m);
		ans=0;
		for(int i=0;i<n;i++)
		switch(s[i])
		{
			case 'R':if(b){b--;ans++;m[i]='P';}break;
			case 'P':if(c){c--;ans++;m[i]='S';}break;
			case 'S':if(a){a--;ans++;m[i]='R';}break;
		}
		if(ans*2>=n)
		{
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++)
			if(m[i])
			cout<<m[i];
			else
			{
				if(a)
				a--,cout<<'R';
				else
				if(b)
				b--,cout<<'P';
				else
				if(c)
				c--,cout<<'S';
			}
			cout<<endl;
		}
		else
		cout<<"NO"<<endl;
	}
	return 0;
}
