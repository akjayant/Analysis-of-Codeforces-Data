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

int main()
{
    Long i,j,k,l,n,m,tot,temp,curr,val,prev,a,b,c,t,ans,flag,x,y,siz,ii,jj,xx,yy,ind,len,q,xxx,yyy,d;

    cin>>n;
    if(n == 1)
    {
        cout<<1<<endl;
        return 0;
    }

    temp = 0;
    for(i=2; i*i<=n; i++)
    {
        flag = 0;
        while(n % i == 0)
        {
            n /= i;
            flag = 1;
        }

        if(flag) ans = i;
        if(flag) temp++;
    }

    if(n > 1)
    {
        temp++;
        ans = n;
    }

    if(temp > 1) ans = 1;
    cout<<ans<<endl;
}
