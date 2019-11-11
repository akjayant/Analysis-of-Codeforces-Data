#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define PB push_back
#define LL long long
#define pii pair<int,int>
#define MEM(x,y) memset(x,y,sizeof(x))
#define bug(x) cout<<"debug "#x" is "<<x<<endl;
#define FIO ios::sync_with_stdio(false);
#define ALL(x) x.begin(),x.end()
#define LOG 20
const int inf =1e9;
const int maxn =3e5+7;
const int mod = 1e9+7;

int main(){
    FIO;
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(__gcd(a,b)==1)puts("Finite");
        else puts("Infinite");
    }
    return 0;
}


