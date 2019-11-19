#include <cstring>
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX (100005)
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define int long long
#define ll long long
#define lson (p<<1)
#define rson (lson | 1)
#define ALL(x) x.begin(),x.end()

const long long mod = 1e9 + 7;

int arr[MAX];

signed main(void)
{
   int n; scanf("%lld", &n);
   for(int i = 1; i <= n; i++){
        scanf("%lld", arr + i);
   }
   sort(arr + 1, arr + 1 + n);
   int sum1 = 0, sum2 = 0;
   int p1 = n / 2 + 1;
   int p2 = 1;
   for(int i = 1; i <= n; i++){
        if(i % 2) sum1 += arr[p1++];
        else sum2 += arr[p2++];
   }
   cout << sum1 * sum1 + sum2 * sum2 << endl;
}
