#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int main() {
    int t;
    scanf("%d",&t);
    while(t--){

        int a,b;
        scanf("%d%d",&a,&b);
        if(__gcd(a,b)==1)printf("Finite\n");
        else printf("Infinite\n");
    }
    return 0;
}
