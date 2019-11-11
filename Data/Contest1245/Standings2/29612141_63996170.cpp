#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}


void init();
void work();
int ca=1;
int main(){
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    init();
    int T;cin>>T;
    while(T--)
    work();
    return 0;
}
void work(){
    int a,b;cin>>a>>b;
    if(gcd(a,b)==1) cout<<"Finite\n";
    else cout<<"Infinite\n";
}
