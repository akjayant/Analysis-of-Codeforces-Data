//#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;

int vis[1000005], vid = 0;

int main() {
   // freopen("in.txt", "rt", stdin);
    int tc;
    scanf("%d",&tc);
    while(tc--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(__gcd(a,b)==1) puts("Finite");
        else puts("Infinite");
    }
}