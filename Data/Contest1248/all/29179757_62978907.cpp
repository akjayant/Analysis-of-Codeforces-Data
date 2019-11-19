#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define rep(i,s,t) for(int i = s;i <= t;i++)
#define per(i,t,s) for(int i = t;i >= s;i--)
#define mst(s) memset(s,0,sizeof(s))
#define ls(x) x<<1
#define rs(x) x<<1|1 
#define lb(x) x&-x
#define pii pair<int,int>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pi acos(-1)
#define F first
#define S second 
#define cuts printf("\n--------------\n");
#define maxn 100005
#define maxm 400005
#define mod 1000000007LL
#define inf 1LL<<60
int n ,t ,m,p,q, od1, od2; 

int main(){
    scanf("%d",&t);
    while(t--){
    	od1 = od2 = 0 ;
    	scanf("%d",&n);
    	rep(i,1,n){
    		scanf("%d",&p);
    		if(p%2) od1++;
    	}
    	scanf("%d",&m);
    	rep(i,1,m){
    		scanf("%d",&q);
    		if(q%2) od2++;
    	}
    	printf("%lld\n",(ll)od1*od2+(ll)(n-od1)*(m-od2));
    }
    return 0;
}

//Accepted! 
