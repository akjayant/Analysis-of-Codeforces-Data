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
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll o1=0,e1=0;
        fpr(i,0,n)
        {
            cin>>a[i];
            if(a[i]&1)
            {
                o1++;
            } else{
                e1++;
            }
        }
        ll m;
        cin>>m;
        ll b[m];
        ll o2=0,e2=0;
        fpr(i,0,m)
        {
            cin>>b[i];
            if(b[i]&1)
            {
                o2++;
            } else{
                e2++;
            }
        }
        cout<<o1*o2+e1*e2<<'\n';
    }
    return 0;
}



