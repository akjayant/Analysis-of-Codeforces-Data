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
int a[maxn];
ll sum, sum1, sum2;
int main(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]), sum += a[i];
    sort(a+1,a+1+n);
    rep(i,1,n/2) sum1 += a[i];
    int j = n, count = 1;
    while(count <= n/2){
    	sum2 += a[j];
    	j--;
    	count++;
    }
    printf("%lld\n",max(sum1*sum1+(sum-sum1)*(sum-sum1),sum2*sum2+(sum-sum2)*(sum-sum2)));
    return 0;
}

//Accepted! 
