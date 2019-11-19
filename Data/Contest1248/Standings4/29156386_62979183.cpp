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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n;
        ll A[n],i,j;
        ll on=0,om=0,en=0,em=0;
        for(i=0;i<n;i++)
        {
            cin>>A[i];
            if(A[i]%2==0)
                en++;
            else
                on++;
        }
        cin>>m;
        ll B[m];
        for(i=0;i<m;i++)
        {
            cin>>B[i];
            if(B[i]%2==0)
                em++;
            else
                om++;
        }
        cout<<on*om+en*em<<endl;
    }
    
    return 0;
}