#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define check(x) cout << #x << " : " << (x) << endl
#define all(v) v.begin(),v.end()
#define endl '\n'
#define show(a) for(auto i:a) cout<<i<<" ";cout<<endl
typedef long long ll; 
typedef unsigned long long ull; 
typedef long double ld;
typedef pair< int , int > mypair;
typedef priority_queue <int> max_heap;
typedef priority_queue <int, vector<int>, greater<int> > min_heap;
const ll mod=1e9+7;
const ll inf=1e9;
const ll N=5e5+10;

int main()
{
	boost;
	int t;
	cin>>t;
	while(t--)
	{
		int A,B,C;
		cin>>A>>B>>C;
		int ans=0;
		for(int i=0;i<=100;i++)
		{
			for(int j=0;j<=100;j++)
			{
				int a,b,c;
				a=A;b=B;c=C;
				bool flag=1;
				int sum=0;
				if(a>=i and b>=2*i )
				{
					sum+=3*i;
					a-=i;
					b-=2*i;
				}
				else flag=0;
				if(b>=j and c>=2*j )
				{
					sum+=3*j;
					b-=j;
					c-=2*j;
				}
				else flag=0;
				if(flag) ans=max(ans,sum);


			}
		}
		cout<<ans<<endl;
	}
   	return 0;
}