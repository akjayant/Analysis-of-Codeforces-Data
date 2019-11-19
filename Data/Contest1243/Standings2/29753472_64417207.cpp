#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
typedef double db;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
ll n;

bool judge(ll x){
    if(x == 2) return 1;
    if(x % 2 == 0) return 0;
    ll sz = sqrt(x);
    for(int i=3;i<=sz;i+=2) if(x % i==0) return 0;
    return 1;
}

int main(){
    scanf("%lld", &n);
    if(n == 1) printf("1\n");
    else{
        //if(judge(n)) printf("%lld\n", n);
        //else{
        if(judge(n)) printf("%lld\n", n);
        else{
            ll m = n, res=0, p;
            for(ll i=2;i<=sqrt(m); ++i){
                if(m % i == 0){
                    res++;
                    p=i;
                    while(m%i==0) m /= i;
                }
            }
            if(res == 1 && m == 1) printf("%lld\n", p);
            else printf("1\n");
        }
        //}
    }
    return 0;
}
