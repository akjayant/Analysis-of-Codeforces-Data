#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define modulo 1000000007
#define int long long int
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        int cnt=0;
        int x=min(c/2,b);
        cnt+=3*x;
        b-=x;
        x=min(b/2,a);
        cnt+=3*x;
        cout<<cnt<<"\n";
    }
}

