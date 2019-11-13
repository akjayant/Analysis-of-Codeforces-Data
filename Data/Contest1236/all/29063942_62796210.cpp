#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define pb push_back
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define inp(n) for(i=0;i<n;i++) cin>>A[i];
#define inz(A) memset(A,0,sizeof(A))
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(),v.end()
#define T 1000000
#define F first
#define S second
#define pi pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define vp vector<pair< int,int> >
#define mpi map<pair<int,int> ,int>
#define mip map<int, pair<int,int> >
#define inf INT_MAX
#define inf1 LONGLONG_MAX
#define sz(v) v.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define deb(x) cout<<#x<<"is "<<x<<endl;
#define lower(s) transform(all(s),s.begin(),::tolower)
#define endl "\n"
vector<int>adj [T];
			/*brownsands IIITA*/

void solve()
{	int n,i,j,k;
	cin>>n;
	int A[n+5][n+5];
	k=1;
	for(i=1;i<=n;i+=2)
	{
		for(j=1;j<=n;j++)
		{
			A[j][i]=k++;
		}
		k+=n;
	}
	k=n+1;
	for(i=2;i<=n;i+=2)
	{
		for(j=n;j>=1;j--)
		{
			A[j][i]=k++;
		}
		k+=n;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		cout<<A[i][j]<<" ";
		cout<<endl;
	}
}
signed main()
{
   boost
        int test=0,t;
		//cin>>t;
		t=1;
		while(test++ <t){
            //cout<<"Case "<<test<<": ";
            solve();
            //cerr << "\nTime : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
               }		
} 
               
			
 

				
		
		


