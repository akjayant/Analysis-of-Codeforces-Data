// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;

#define double long double
#define Long long long
#define EPS 1e-12
#define PI acos(-1.0)

#define MAX 2000000
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

Long ar[MAX+9];
Long FIB[MAX+9];
char aa[MAX+9];

int main()
{
    Long i,j,k,l,n,m,tot,temp,curr,val,prev,a,b,c,t,ans,flag,x,y,siz,ii,jj,xx,yy,ind,len,q,xxx,yyy,d;

    FIB[0] = 1;
    FIB[1] = 1;

    for(i=2; i<=MAX; i++)
    {
        FIB[i] += FIB[i-1];
        FIB[i] += FIB[i-2];
        FIB[i] %= MOD;
    }

    scanf("%s", aa);
    n = strlen(aa);
    ans = 1;

    for(i=0; i<=n+5; i++) ar[i] = 0;
    for(i=0; i<n; i++) if(aa[i] == 'u') ar[i+1] = 1;

    temp = 0;
    for(i=0; i<=n+2; i++)
    {
        if(ar[i]) temp++;
        else
        {
            ans *= (FIB[temp]);
            ans %= MOD;
            temp = 0;
        }
    }

    for(i=0; i<=n+5; i++) ar[i] = 0;
    for(i=0; i<n; i++) if(aa[i] == 'n') ar[i+1] = 1;

    temp = 0;
    for(i=0; i<=n+2; i++)
    {
        if(ar[i]) temp++;
        else
        {
            ans *= (FIB[temp]);
            ans %= MOD;
            temp = 0;
        }
    }

    for(i=0; i<n; i++) if(aa[i] == 'm') ans = 0;
    for(i=0; i<n; i++) if(aa[i] == 'w') ans = 0;

    cout<<ans<<endl;
}
