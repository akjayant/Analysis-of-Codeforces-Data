#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned long long
const LL INF=1LL<<62;
#define PI (2.0*acos(0.0))

typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;


//// Including Policy Based DS
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;

//cout<<*X.find_by_order(1)<<endl;
//cout<<X.order_of_key(-5)<<endl;

//typedef tree<
//pll,
//null_type,
//less< pll >,
//rb_tree_tag,
//tree_order_statistics_node_update>
//ordered_set;

#define READ 		freopen("in.txt","r",stdin)
#define WRITE  		freopen("out.txt","w",stdout)
#define BOOST		ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sf 			scanf
#define pf 			printf
#define F  			first
#define S  			second
#define pb 			push_back
#define NL			pf("\n")
#define ALL(v)		v.begin(),v.end()
#define si(x)		sf("%d",&x);
#define sii(x,y)	sf("%d%d",&x,&y);
#define siii(x,y,z)	sf("%d%d%d",&x,&y,&z);
#define sl(x)		sf("%lld",&x);
#define sll(x,y)	sf("%lld%lld",&x,&y);
#define slll(x,y,z)	sf("%lld%lld%lld",&x,&y,&z);
#define mem(x,y) 	memset(x,y,sizeof x )
#define ch 			printf("Came Here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n")
#define SV(v)		sort(v.begin(),v.end())
#define SVR(v,cmp)	sort(v.begin(),v.end(),cmp)
#define FOR(i,n)	for(int i=0;i<n;i++)
#define cnd			tree[idx]
#define lc			tree[idx*2]
#define rc			tree[idx*2+1]
#define lnd 		(2*idx),(b),((b+e)/2)
#define rnd 		((2*idx)+1),(((b+e)/2)+1),(e)

// graph direction array [4]
//LL X[4]={0,0,-1,1};
//LL Y[4]={1,-1,0,0};
// graph direction array [8]
//int X[8]={0,0,1,-1,-1,1,1,-1};
//int Y[8]={1,-1,0,0,-1,-1,1,1};
// Bishop direction array [8]
//int X[8]={0,0,1,-1,-1,1,1,-1};
//int Y[8]={1,-1,0,0,-1,-1,1,1};
// Knight Direction Array
//int KX[8] = {1,1,2,2,-1,-1,-2,-2};
//int KY[8] = {2,-2,1,-1,2,-2,1,-1};

bool Check(int N,int pos){return (bool)(N & (1<<pos));} // check bit
int Set(int N,int pos){	return N=N | (1<<pos);}// set bit

const LL mod = 1e9+7;
LL modMul(LL a, LL b){

    LL ans = 0;
    a = a % mod;
    while (b > 0){
        if ( b % 2 )ans = (ans%mod+ a%mod) % mod;
        a = (a%mod * 2%mod) % mod;
        b /= 2;
    }
    return ans % mod;
}

LL powerMod(LL a,LL b){
	if(b==0)return 1LL%mod;
	LL x=powerMod(a,b/2);
	x = (x%mod*x%mod)%mod;
	if(b%2==1)x = (x%mod*a%mod)%mod;
	return x%mod;
}

LL lcm( LL a,LL b ){
	LL g = __gcd(a,b);
	return (a*b)/g;
}
const int mx = 1e5+7;
//-------------------------------------------------------------------------------


LL nod(LL n){

	LL m=n;
	LL cnt = 0;
	for(LL i=2;i*i<=m;i++){
		if( m%i==0 ){
			cnt++;
			while(m%i==0)m/=i;
		}
	}

	if( m==n )return 0;
	if( m>1 )return cnt+1;
	return cnt;

}

int main(){
//  READ;
//  WRITE;
//	BOOST;
	LL t,u,v,m,w,n,k;

	cin>>n;
	m = n;


	LL cc = nod(n);

////	bool fnd = 0;
//	int cc = 0;
//	LL ans = n;
//	for( LL i=2;i*i<= m; i++ ){
//		if( n%i==0 ){
//
////			cout<<i<<" "<<n<<endl;
////			fnd=1;
//			cc++;
//
//			while(n%i==0)n/=i;
//			if( cc==1 ){
//				ans = i;
//			}
//
////			LL y = n/i;
////			if( y!=i ){
////				cc++;
////			}
////
////			cout<<i<<endl;
////			cout<<y<<endl;
////			cout<<n<<endl;
//		}
//	}
//
////	cout<<cc<<endl;

	if( cc>1 )cout<<1<<endl;
	else if( cc==0 )cout<<n<<endl;
	else {
        for( LL i=2;i*i<=n;i++ ){
			if( n%i==0 ){
				cout<<i<<endl;
				return 0;
			}
        }
	}

    return 0;
}
