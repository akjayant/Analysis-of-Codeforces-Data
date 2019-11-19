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
LL X[4]={0,0,-1,1};
LL Y[4]={1,-1,0,0};
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



int parent[mx];
void init(int n){

	FOR(i,n+2)parent[i]=i;

}

int find_set(int u){

	if( u==parent[u] )return u;
	return parent[u] = find_set(parent[u]);

}


void union_sets(int u,int v){

	int a=find_set(u);
	int b=find_set(v);
	if(a!=b)parent[b]=a;

}





vi g2[mx];
set<int> baki;
set<int> g[mx];
vi nodes;
bool cmp(int a,int b){
	return ((size_t) g[a].size() < (size_t) g[b].size());
}

bool vis[mx];

void go(int u){


//	cout<<u<<endl;
//	for(int v:baki)cout<<v<<" ";NL;
	queue<int> all;
	vi cur;
	all.push(u);
    baki.erase(u);
    vis[u] = 1;
//    ch;
    while( !all.empty() ){
		u = all.front();
		all.pop();
		cur.clear();
		if( baki.empty() )break;

//		cout<<u<<endl;
		for(int v:baki){
			if( g[u].find(v)==g[u].end() ){
				all.push(v);
				vis[v] = 1;
				cur.pb(v);
//				cout<<v<<" ";
			}
		}
//		NL;

		for(int v:cur)baki.erase(v);
    }

//    for(int v:baki)cout<<v<<" ";NL;
//    cout<<"Shesh"<<endl;

}


int main(){
//  READ;
//  WRITE;
//	BOOST;
	int t,n,m,u,v;

    cin>>n>>m;

    init(n+1);


    FOR(i,m){
		cin>>u>>v;
		g2[u].pb(v);
		g2[v].pb(u);
    }
    for(int i=1;i<=n;i++)nodes.pb(i),baki.insert(i);

    sort(nodes.begin(),nodes.end(),cmp);
    for(int i=1;i<=n;i++){
		sort(g2[i].begin(),g2[i].end(),cmp);
		FOR(j,g2[i].size()){
			g[i].insert( g2[i][j] );
		}
    }

	int cnt = 0;
	for( int x:nodes ){
		if( !vis[x] ){
			go(x);
			cnt++;
		}
	}


	cout<<cnt-1<<endl;


    return 0;
}
