#include<bits/stdc++.h>
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define int long long int
#define modulo 1000000007
using namespace std;
int us(int a,int x){
    int t=1;
    if(x==0)return 1;
    t=us(a,x/2);
    t=t*t%modulo;
    if(x%2)t=t*a%modulo;
    return t%modulo;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int q=(us(2,m)-1+modulo)%modulo;
    cout<<us(q,n)%modulo;
}
