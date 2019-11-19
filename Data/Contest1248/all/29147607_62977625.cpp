// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;

#define double long double
#define Long long long
#define EPS 1e-12
#define PI acos(-1.0)

#define MAX 100000
#define MOD 1000000007

#define POS_INF (1LL << 55)
#define NEG_INF (-(1LL << 55))

#define RIGHT_MOST_INDEX (1 << 30)
#define LEFT_MOST_INDEX (-(1 << 30))

#define MEMSET(x,y) memset(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SORT(A) sort(A.begin(), A.end());
#define REVERSE(A) reverse(A.begin(), A.end());

int main()
{
    Long i,j,k,l,n,m,tot,temp,curr,val,prev,a,b,c,t,ans,flag,x,y,siz,ii,jj,xx,yy,root,ind,len,q,xxx,yyy,d;

    cin>>q;
    while(q--)
    {
        a = 0;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            scanf("%lld", &j);
            if(j % 2) a++;
        }


        b = 0;
        cin>>m;
        for(i=1; i<=m; i++)
        {
            scanf("%lld", &j);
            if(j % 2) b++;
        }

        ans = a * b + (n-a) * (m-b);
        cout<<ans<<endl;
    }
}
