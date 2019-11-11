#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10,mod=998244353;
string s;
char t[N];
int main()
{
    //freopen("i.txt","r",stdin);
    ll te,n,a,b,c;
    scanf("%lld",&te);
    while(te--)
    {
        scanf("%lld",&n);
        scanf("%lld %lld %lld",&a,&b,&c);
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='S'&&a)
            {
                a--;
                t[i]='R';
            }
            else if(s[i]=='R'&&b)
            {
                b--;
                t[i]='P';
            }
            else if(s[i]=='P'&&c)
            {
                c--;
                t[i]='S';
            }
            else t[i]=0;
        }
        int cc=n-a-b-c;
        if(cc>=(n+1)/2)
        {
            puts("YES");
             for(int i=0;i<n;i++)
             {
                 if(t[i])
                 printf("%c",t[i]);
                 else if(a)
                 {
                     a--;
                     printf("R");
                 }
                 else if(b)
                 {
                     b--;
                     printf("P");
                 }
                 else if(c)
                 {
                     c--;
                     printf("S");
                 }
             }
             puts("");
        }
        else puts("NO");
    }

    //for(int i=0;i<n;i++)scanf("%lld",&a[i]);

}
