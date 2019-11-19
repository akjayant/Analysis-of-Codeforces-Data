// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;

#define double long double
#define Long long long
#define EPS 1e-12
#define PI acos(-1.0)

#define MAX 1000000
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

int main()
{
    Long i,j,k,l,n,m,tot,temp,curr,val,prev,a,b,c,t,ans,flag,x,y,siz,ii,jj,xx,yy,root,ind,len,q,xxx,yyy,d;

    cin>>n;
    for(i=1; i<=n; i++)
    {
        scanf("%lld", &j);
        ar[i] = j;
    }

    sort(ar+1, ar+1+n);

    a = 0;
    b = 0;

    m = n/2;
    for(i=1; i<=n; i++) a += ar[i];
    for(i=1; i<=m; i++) b += ar[i];
    a -= b;

    cout<<a*a+b*b<<endl;
}
