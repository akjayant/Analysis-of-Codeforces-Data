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

Long ANS[MAX+9];
string aa;

int main()
{
    Long i,j,k,l,n,m,tot,temp,curr,val,prev,a,b,c,t,ans,flag,x,y,siz,ii,jj,xx,yy,root,ind,len,q,xxx,yyy,d;

    cin>>q;
    while(q--)
    {
        cin>>n;
        cin>>a>>b>>c;
        cin>>aa;

        for(i=0; i<n; i++) ANS[i] = 0;
        ans = 0;

        for(i=0; i<n; i++)
        {
            if(aa[i] == 'S')
            {
                if(a)
                {
                    a--;
                    ANS[i] = 'R';
                    ans++;
                }
            }
            else if(aa[i] == 'R')
            {
                if(b)
                {
                    b--;
                    ANS[i] = 'P';
                    ans++;
                }
            }
            else if(aa[i] == 'P')
            {
                if(c)
                {
                    c--;
                    ANS[i] = 'S';
                    ans++;
                }
            }
        }

        for(i=0; i<n; i++)
        {
            if(ANS[i] == 0)
            {
                if(a)
                {
                    ANS[i] = 'R';
                    a--;
                }
                else if(b)
                {
                    ANS[i] = 'P';
                    b--;
                }
                else
                {
                    ANS[i] = 'S';
                    c--;
                }
            }
        }

        if(ans >= ((n+1)/2))
        {
            cout<<"YES\n";
            for(i=0; i<n; i++) cout<<(char)ANS[i];
            cout<<endl;
        }
        else cout<<"NO\n";
    }
}
