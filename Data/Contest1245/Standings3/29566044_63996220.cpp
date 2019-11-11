#include<bits/stdc++.h>
using  namespace std;

typedef  pair<int,int> pii;
void solve(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(__gcd(a,b)==1) printf("Finite");
    else printf("Infinite");
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();

}
