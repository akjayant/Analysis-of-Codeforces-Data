#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int main()
{
    int t,a,b;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d",&a,&b);
        if(__gcd(a,b)==1){
            printf("Finite\n");
        }
        else{
            printf("Infinite\n");
        }
    }
    return 0;
}
