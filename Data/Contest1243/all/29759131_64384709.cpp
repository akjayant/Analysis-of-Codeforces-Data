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
vector<pair<int, int> > vec;

int main()
{
    int i,j,k,l,n,m,tot,temp,curr,val,prev,a,b,c,t,ans,flag,x,y,siz,ii,jj,xx,yy,root,ind,len,q,xxx,yyy,d;

    cin>>t;
    while(t--)
    {
        cin>>n;
        scanf("%s%s",aa,ss);

        aaa = aa;
        sss = ss;
        vec.clear();

        for(i=0; i<n; i++)
        {
            if(aaa[i] == sss[i]) continue;

            flag = 0;
            for(j=i+1; j<n; j++)
            {
                if(aaa[j] == aaa[i])
                {
                    swap(aaa[j], sss[i]);
                    vec.PB(MP(j, i));
                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
            {
                for(j=i+1; j<n; j++)
                {
                    if(sss[j] == aaa[i])
                    {
                        swap(aaa[j], sss[j]);
                        swap(aaa[j], sss[i]);
                        vec.PB(MP(j, j));
                        vec.PB(MP(j, i));
                        flag = 1;
                        break;
                    }
                }
            }
        }


        if(aaa == sss)
        {
            cout<<"Yes\n";
            cout<<vec.size()<<endl;
            for(i=0; i<vec.size(); i++)
            {
                printf("%d %d\n", vec[i].first + 1, vec[i].second + 1);
            }
        }
        else cout<<"No\n";
    }
}
