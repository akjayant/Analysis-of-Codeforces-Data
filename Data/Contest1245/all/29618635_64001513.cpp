#include <bits/stdc++.h>
#define N 100005
typedef long long ll;
using namespace std;

int main(){
    int tt,a,b;
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d",&a,&b);
        if(__gcd(a,b)!=1) puts("Infinite");
        else  puts("Finite");
    }
}
