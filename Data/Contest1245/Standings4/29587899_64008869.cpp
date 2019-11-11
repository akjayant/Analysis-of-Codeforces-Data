#include<bits/stdc++.h>
#define numm ch-48
#define pd putchar(' ')
#define pn putchar('\n')
#define pb push_back
#define debug(args...) cout<<#args<<"->"<<args<<endl
#define bug cout<<"************"
using namespace std;
template <typename T>
void read(T &res) {
    bool flag=false;char ch;
    while(!isdigit(ch=getchar())) (ch=='-')&&(flag=true);
    for(res=numm;isdigit(ch=getchar());res=(res<<1)+(res<<3)+numm);
    flag&&(res=-res);
}
template <typename T>
void write(T x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
typedef long long ll;
typedef long double ld;
const int maxn=2e5+10;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const double alpha=0.7;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
char ss[110],t[110];
int main()
{
    int _,n,k,m;
    read(_);
    vector<int>R,S,P;
    while(_--) {
        int r=0,s=0,p=0,ans=0;
        read(n);
        read(r);read(p);read(s);
        scanf("%s",ss);
        t[n]='\0';
        R.clear();
        P.clear();
        S.clear();

        for(int i=0;i<n;i++)
            t[i]='X';
        for(int i=0;i<n;i++) {
            if(ss[i]=='R') R.pb(i);
            else if(ss[i]=='P') P.pb(i);
            else if(ss[i]=='S') S.pb(i);
        }
        for(int i=0;i<R.size();i++) {
            if(p) t[R[i]]='P',p--,ans++;
            else break;
        }
        for(int i=0;i<S.size();i++) {
            if(r) t[S[i]]='R',r--,ans++;
            else break;
        }
        for(int i=0;i<P.size();i++) {
            if(s) t[P[i]]='S',s--,ans++;
            else break;
        }
        if(ans<(n+1)/2) puts("NO");
        else {
            puts("YES");
            for(int i=0;i<n;i++)
                if(t[i]!='X') cout<<t[i];
                else {
                    if(p) {
                        p--;
                        cout<<'P';
                    }
                    else if(r) {
                        r--;
                        cout<<'R';
                    }
                    else if(s) {
                        s--;
                        cout<<'S';
                    }
                }
            cout<<endl;
        }
    }
    return 0;
}
