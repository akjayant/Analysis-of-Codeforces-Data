#include <bits/stdc++.h>
#define ll long long;
const long long maxn=100005;
using namespace std;
long long t,n,x;
long long a[maxn];
long long num1=0;
long long num2=0;
int main() {
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        num2+=a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n/2;i++)
    {
        num1+=a[i];
    }
    num2-=num1;
    printf("%lld\n",num1*num1+num2*num2);
    return 0;
}