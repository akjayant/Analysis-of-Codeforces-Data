// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;

#define double long double
#define Long long long
#define EPS 1e-12
#define PI acos(-1.0)

#define MAX 3000000
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
vector<Long> vec;
int main()
{
    Long i,j,k,l,n,m,tot,temp,curr,val,prev,a,b,c,t,ans,flag,x,y,siz,ii,jj,xx,yy,root,ind,len,q,xxx,yyy,d;

    cin>>q;
    while(q--)
    {
        cin>>a>>b;

        ans = 0;
        tot = 20000;

        vec.clear();
        for(i=1; i<=tot; i++) vec.PB((i * a) % b);
        SORT(vec);

        temp = 0;
        for(i=0; i<vec.size(); i++)
        {
            if(i) if(vec[i] == vec[i-1]) continue;
            temp++;
        }

        if(temp == b) ans = 1;

        swap(a, b);
        vec.clear();
        for(i=1; i<=tot; i++) vec.PB((i * a) % b);
        SORT(vec);

        temp = 0;
        for(i=0; i<vec.size(); i++)
        {
            if(i) if(vec[i] == vec[i-1]) continue;
            temp++;
        }

        if(temp == b) ans = 1;


        if(ans == 0) cout<<"Infinite\n";
        else cout<<"Finite\n";
    }
}
