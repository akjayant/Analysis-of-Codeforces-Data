#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#define ls root<<1
#define rs root<<1|1
using namespace std;
const int maxn=1e5+7;
const double eps=1e-6;
typedef long long ll;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==1 || b==1){
            printf("Finite\n");
            continue;
        }
        int d=gcd(a,b);
        if(d!=1){
            printf("Infinite\n");
        }
        else{
            printf("Finite\n");
        }
    }
    return 0;
}
