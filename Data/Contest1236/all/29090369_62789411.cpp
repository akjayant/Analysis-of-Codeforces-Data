#include<bits/stdc++.h>
using namespace std;
#define ten5 100000
#define ten6 1000000
#define ten7 10000000
#define ten8 100000000
#define ten9 1000000000
#define ten10 10000000000
#define ten11 100000000000
#define ten12 1000000000000
#define ten13 10000000000000
#define ten14 100000000000000
#define ten15 1000000000000000
#define ten16 10000000000000000
#define ten17 100000000000000000
#define ten18 1000000000000000000

#define ten77 10000007
#define ten79 10000009
#define ten97 1000000007
#define ten99 1000000009

#define loop(i,n) for(int i=0;i<n;i++)
#define loop2(i,x,n) for(int i=x;i<n;i++)
#define loopll(i,n) for(long long int i=0;i<n;i++)
#define loop2ll(i,x,n) for(long long int i=x;i<n;i++)
#define loopa(i,x) for(auto i : x)

#define ms(arr) memset(arr,0,sizeof(arr))
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second

#define err cout<<"\nerror\n";
//#define wait system("pause");

#define time(t) cout<<(double)(clock()-t)/CLOCKS_PER_SEC

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);

typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define vi vector<int>

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;
 
    x = x % p;  
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1;
        x = (x*x) % p;  
    }
    return res;
}

void solve()
{
	long long int a,b;
	cin>>a>>b;
	cout<<power((power(2,b,ten97)+ten97-1),a,ten97);
}

int main()
{
	IOS;
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
}
