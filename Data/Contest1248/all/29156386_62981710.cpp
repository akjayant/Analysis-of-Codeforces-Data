/*
....................
....................
*/
#include<bits/stdc++.h>
#define ll long long int
#define here cout<<"here\n"
#define pb push_back
#define mp make_pair
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define pfi(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
using namespace std;

const ll mod = 1e9+7;

const int MAX = 100005;


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll A[n],i,j,k;
    for(i=0;i<n;i++)
        cin>>A[i];
    sort(A,A+n);
    i=0;j=n-1;
    ll x=0,y=0;
    while(i<j)
    {
      x+=A[j];
      y+=A[i];
      i++;
      j--;
    }
    if(i==j)
        x+=A[i];
    cout<<x*x+y*y<<endl;
    
    return 0;
}