#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
inline void minimize(int &x,int y) { x = min(x,y); }
inline void maximize(int &x,int y) { x = max(x,y); }

const int maxN=10000+1067;
int t,n;
char res[maxN];



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("dream_hyojooslh.txt","r",stdin);
    cin>>t;
    For(test,1,t) {
        int a,b,c;
        cin>>n;
        cin>>a>>b>>c;
        int m=n/2+n%2;
        For(i,1,n) res[i]='D';
        For(i,1,n) {
            char x;
            cin>>x;
            if (x=='R') {
                if (b) --m,--b,res[i]='P';
            } else if (x=='P') {
                if (c) --m,--c,res[i]='S';
            } else
                if (a) --m,--a,res[i]='R';
        }
        if (m>0) {
            cout<<"no"<<endl;
            continue;
        }
        cout<<"yes"<<endl;
        For(i,1,n) {
            if (res[i]!='D') cout<<res[i]; else {
                if (a) res[i]='R',--a;
                else if (b) res[i]='P',--b;
                else res[i]='S';
                cout<<res[i];
            }
        }
        cout<<endl;
    }
    return 0;
}
