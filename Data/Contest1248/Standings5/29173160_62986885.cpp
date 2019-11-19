		
#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long int
#define mem(x) memset(x,0,sizeof(x))
#define setbits(x)  __builtin_popcount(x)
#define ull unsigned long long int
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rep1(i,a,b)  for(int i=a;i<=b;i++)
#define fun(s,e,c) for(int i=s;i<e;i+=c)
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
using namespace std;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef pair<ll,int> li;
inline void fast()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int main()
{
	fast();
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{cin>>a[i];
		/* code */
	}
	sort(a,a+n);
	ll sum1=0,sum2=0;
	for(int i=0;i<n/2;i++)
		sum1+=a[i];
	for(int i=n/2;i<n;i++)
		sum2+=a[i];

   ll ans=(sum1+sum2)*(sum1+sum2)-2LL*sum1*sum2;
   cout<<ans<<"\n";


}