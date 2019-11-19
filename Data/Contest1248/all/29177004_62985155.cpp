#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <complex>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <bitset>
#include <typeinfo>
#include <random>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int maxn = 1e6 + 10;

int n;
long long a[maxn];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    if(n % 2 == 0){
        long long x = 0, y = 0;
        for(int i = 1; i <= n / 2; i++) y += a[i];
        for(int i = n / 2 + 1; i <= n; i++) x += a[i];
        printf("%lld\n", x * x + y * y);
    }
    else{
        long long x = 0, y = 0;
        for(int i = 1; i <= n / 2; i++) y += a[i];
        for(int i = n / 2 + 1; i <= n; i++) x += a[i];
        printf("%lld\n", x * x + y * y);
    }
    return 0;
}