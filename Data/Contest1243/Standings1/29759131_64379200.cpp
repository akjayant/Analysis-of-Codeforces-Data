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

char aa[MAX+9];
char ss[MAX+9];
string aaa, sss;

int main()
{
    Long i,j,k,l,n,m,tot,temp,curr,val,prev,a,b,c,t,ans,flag,x,y,siz,ii,jj,xx,yy,root,ind,len,q,xxx,yyy,d;

    cin>>t;
    while(t--)
    {
        cin>>n;
        scanf("%s%s",aa,ss);

        aaa = aa;
        sss = ss;

        if(aaa == sss) ans = 1;
        else
        {
            ans = 0;
            temp = 0;
            for(i=0; i<n; i++) if(aa[i] != ss[i]) temp++;

            if(temp == 2)
            {
                a = -1;
                b = -1;

                for(i=0; i<n; i++)
                {
                    if(aa[i] != ss[i])
                    {
                        if(a == -1) a = i;
                        else b = i;
                    }
                }

                swap(aaa[a], sss[b]);
                if(aaa == sss) ans = 1;
            }
        }

        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
