#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
const int N = 10010;
long long p;
int main()
{
    long long n, ans = 0;
    cin>>n;
    for (long long i = 2; i <= n; ++i){
        if (i * i > n) break;
        if (n % i == 0){
            while(n % i == 0) n /= i;
            if (n == 1) ans = i;
            else ans = 1;
            break;
        }
    }
    if (ans == 0) ans = n;
    printf("%lld\n", ans);
    // system("pause");
}