#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define endl '\n'
#define pw(x) (1ll<<(x))
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n;
 
int main() 
{
    //std::ios::sync_with_stdio(0);
	//std::cin.tie(0);
	
	while(cin>>n)
	{
		ll tn=n;
		rep(i,2,sqrt(n)+1)
		{
			if(n%i==0)
			{
				while(n%i==0&&n!=0)n/=i;
				if(n==1)cout<<i<<endl;
				else cout<<1<<endl;
				break;
			}
		}
		if(n==tn)cout<<n<<endl;
	}
	
	return 0;
}