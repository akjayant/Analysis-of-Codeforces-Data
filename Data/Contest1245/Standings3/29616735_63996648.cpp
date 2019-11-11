#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    int i;
    for(i=0; i<n; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        if(gcd(a,b)==1) {
            printf("Finite\n");
        }
        else {
            printf("Infinite\n");
        }
    }




    return 0;
}

