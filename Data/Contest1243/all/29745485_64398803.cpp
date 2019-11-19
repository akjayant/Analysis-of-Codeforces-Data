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

const int maxn = 1e6+7;
const long long mod = 1e9+7;

long long n;
int vis[maxn];
vector<int> prime;


int main() {
    for(int i=2;i<maxn;i++) {
        if(vis[i]) continue;
        prime.push_back(i);
        for(int j=2*i;j<maxn;j+=i) {
            vis[j] = 1;
        }
    }
    cin>>n;
    if(n == 1) {
        printf("1\n" );
        return 0;
    }
    long long sum  =-1;
    long long res = n;
    for(int i=0;i<prime.size();i++) {
        int x = prime[i];
        if(res %x != 0 ) continue;
        if(sum == -1) sum = x;
        else sum = -2;
        while(res%x ==0 ) res /= x;
    }
    if(res != 1) {
        if(sum == -1) sum = res;
        else sum = -2;
    }
    if(sum == -2) printf("1\n" );
    else printf("%lld\n",sum);
    return 0;
}