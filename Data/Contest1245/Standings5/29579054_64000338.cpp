#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e5+7;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(__gcd(a,b)!=1){
            printf("Infinite\n");
        }else{
            printf("Finite\n");
        }
    }
    return 0;
}
