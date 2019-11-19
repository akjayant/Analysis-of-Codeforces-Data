#include<bits/stdc++.h>
#define fi first
#define se second 
#define mk make_pair
#define pb push_back
#define P pair<ll,ll>
#define INF 0x3f3f3f3f
#define mod 1000000007
#define lowbit(n) n&-n
#define mem(i) memset(i,0,sizeof(i))
#define bcnt(x) __builtin_popcount(x)
#define bcntz(x) __builtin_ctz(x)
using namespace std;
const int maxn=100010;
typedef long long ll;
typedef long double ld; 
int n,m;
int gi(){
    char a=getchar();int b=0;
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9')b=b*10+a-'0',a=getchar();
    return b;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		n=a/c+(a%c!=0);
		m=b/d+(b%d!=0);
		if(n+m<=k){
			cout<<n<<" "<<m<<endl;
		}
		else cout<<"-1"<<endl;
	}
	return 0;
}

