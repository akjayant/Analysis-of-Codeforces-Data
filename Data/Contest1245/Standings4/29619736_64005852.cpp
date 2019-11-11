#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
inline void minimize(int &x,int y) { x = min(x,y); }
inline void maximize(int &x,int y) { x = max(x,y); }

const int maxN=100000+1067,base=1e9+7;
int t,n;
int f[maxN];
string s;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("dream_hyojooslh.txt","r",stdin);
    cin>>s;
    n=s.length();
    s='n'+s;
    f[0]=1;
    For(i,1,n) {
        f[i]=f[i-1];
        if (s[i]=='m'||s[i]=='w') {
            cout<<0<<endl;
            return 0;
        }
        if (i>1&&s[i]==s[i-1]&&(s[i]=='u'||s[i]=='n')) f[i]=(f[i]+f[i-2])%base;
    }
    cout<<f[n]<<endl;
    return 0;
}
