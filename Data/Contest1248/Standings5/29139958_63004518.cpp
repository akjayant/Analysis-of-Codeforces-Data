#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define deb(x) cout<<#x<<" : "<<x<<"\n";
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define all(a) (a).begin(),(a).end()
#define bs binary_search
#define SZ(x) (int)(x).size()
#define vi vector<int>
#define pii pair<int,int>
#define ld long double
//#define clr fflush(stdout)
#define clr cout.flush()
#define N 100001
#define fpr(i,a,b) for(int i=a;i<b;i++)
#define fdr(i,a,b) for(int i=a;i>b;i--)
#define print_mat(dist,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<dist[i][j]<<" ";}cout<<'\n';}
#define LLMIN LLONG_MIN
#define LLMAX LLONG_MAX
#define AKASH_PATEL ios_base::sync_with_stdio(false);
#define SVNIT_SURAT cin.tie(NULL);cout.tie(NULL);
#define mset(x,a) memset(x,a,sizeof(x))
int main()
{
    AKASH_PATEL;
    SVNIT_SURAT;
    int n,m;
    cin>>n>>m;
    ll pre[max(n,m)+1];
    ll tmp=max(n,m);
    pre[0]=0;
    pre[1]=2;
    pre[2]=4;
    fpr(i,3,tmp+1)
    {
        pre[i]=(pre[i-1]+pre[i-2])%mod;
    }
    if(n==1 || m==1)
    {
        cout<<pre[max(n,m)]<<'\n';
    }
    else
    {
        cout<<(pre[n]+pre[m]-2)%mod<<'\n';
    }
    return 0;
}



