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

const int maxn = 1e3+7;

int n;
int a[maxn];
int vis[maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<=n;i++) vis[i] = 0;
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            vis[a[i]]++;
        }
        int sum = 0;
        for(int i=n;i>=1;i--) {
            sum+= vis[i];
            if(sum >= i) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}