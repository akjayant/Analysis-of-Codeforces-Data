#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pb push_back
#define pf pop_front
#define mp make_pair
#define mod 1000000007
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mat vector<vector<int>>
#define all(x) x.begin(),x.end()
#define F first
#define S second
#define fo(i,n) for(int i=0;i<n;i++)
#define inp(a) int a;cin>>a;
#define inpa(a,n)vector<int> a(n);fo(i,n)cin>>a[i];
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
using namespace std;
#define int ll


auto max(auto a){auto ans=a[0];for(auto i:a)if(i>ans)ans=i;return ans;}
auto min(auto a){auto ans=a[0];for(auto i:a)if(i<ans)ans=i;return ans;}
void print(auto a){for(auto i:a)cerr<<i<<' ';cerr<<'\n';}



signed main()
{
	fio
	inp(n)
	vector<char> temp(n);
	fo(i,n)
		cin>>temp[i];
	int ans=0;
	int ans1=0,ans2=0;
	fo(ind1,n)
	{
		for(int ind2=ind1;ind2<n;ind2++)
		{
			vector<char> s=temp;
			swap(s[ind1],s[ind2]);
			int count=0;
			int ct=0;
			int p1[n+1];
			p1[0]=0;
			int mi=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i-1]=='(')
					p1[i]=p1[i-1]+1;
				else
					p1[i]=p1[i-1]-1;
				mi=min(mi,p1[i]);
			}
			if(p1[n]!=0)
				continue;
			for(int i=n-1;i>=0;i--)
			{
				if(s[i]=='(')
					ct++;
				else
					ct--;
				if(ct+mi>=0)
					count++;
			}
			if(count>ans)
			{
				ans=count;
				ans1=ind1;
				ans2=ind2;
			}
		}
	}
	cout<<ans<<'\n'<<ans1+1<<' '<<ans2+1<<'\n';
	printclock;
}