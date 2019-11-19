#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const LL llinf=987654321987654321;
const int inf=987654321;
LL a;
bool is_mod(LL a, LL b)
{
    while(a>1){
        if(a%b)return false;
        a/=b;
    }
    return true;
}
bool is_prime(LL a)
{
    for(LL i=2; i*i<=a; i++){
        if(a%i==0)return false;
    }
    return true;
}
int main()
{
    scanf("%lld", &a);
    if(a==1){
        puts("1");
        return 0;
    }
    for(LL i=2; i*i<=a; i++){
        if(is_prime(i)){
            if(is_mod(a, i)){
                printf("%lld", i);
                return 0;
            }
        }
    }
    if(is_prime(a)){
        printf("%lld", a);
        return 0;
    }
    puts("1");
}
