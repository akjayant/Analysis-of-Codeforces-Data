#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#define fir first
#define sec second
using namespace std;

const int maxn = 1e5+7;

int n;
int a[maxn];

int main() {
    long long sum =0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    sort(a,a+n);
    long long res = 0;
    for(int i=0;i<n/2;i++) {
        sum -= a[i];
        res += a[i];
    }
    cout<<sum*sum + res*res<<endl;
    return 0;
}