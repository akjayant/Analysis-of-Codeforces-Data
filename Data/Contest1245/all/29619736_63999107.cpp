#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
inline void minimize(int &x,int y) { x = min(x,y); }
inline void maximize(int &x,int y) { x = max(x,y); }

const int maxN=10000+1067;
int t;
bool check[maxN];



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    For(test,1,t) {
        int a,b;
        cin>>a>>b;
        For(i,0,b-1) check[i]=false;
        For(i,0,b-1) {
            check[a*i%b]=true;
        }
        bool st=false;
        For(i,0,b-1) if (!check[i]) st=true;
        if (st) cout<<"infinite"<<endl; else cout<<"finite"<<endl;
    }
    return 0;
}
