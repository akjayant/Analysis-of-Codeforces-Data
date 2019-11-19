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
	inpa(a,n)
	sort(all(a));
	int c1=0,c2=0;
	int i=0,j=n-1;
	while(i<j)
	{
		c1+=a[i];
		c2+=a[j];
		i++;
		j--;
	}
	if(i==j)
		c2+=a[j];
	cout<<c1*c1+c2*c2<<'\n';
	printclock;
}