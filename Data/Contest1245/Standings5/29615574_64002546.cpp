#include<bits/stdc++.h>
using namespace std;
const int N=104;
int test,a,b,c,n;
string s;
void process() {
    string t;
    t.resize(n+1);
    int w=0;
    for(int i=1;i<=n;i++) {
        if(s[i]=='R') {
            if(b>0) b--,t[i]='P',w++;
            else t[i]='?';
        }
        if(s[i]=='P') {
            if(c>0) c--,t[i]='S',w++;
            else t[i]='?';
        }
        if(s[i]=='S') {
            if(a>0) a--,t[i]='R',w++;
            else t[i]='?';
        }
    }
    if(w>=(n+1)/2) {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++) {
            if(t[i]=='?') {
                if(a>0) {
                    a--;
                    cout<<'R';
                }
                else if(b>0) {
                    b--;
                    cout<<'P';
                }
                else c--,cout<<'S';
            }
            else cout<<t[i];
        }
    }
    else cout<<"NO";
    cout<<endl;
}

void reset() {

}

int main() {
    //freopen("A.INP","r",stdin);
    //freopen("A.OUT","w",stdout);
    cin>>test;
    while(test--) {
        cin>>n>>a>>b>>c>>s;
        s=" "+s;
        process();
        reset();
    }
}
