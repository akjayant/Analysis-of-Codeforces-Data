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

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    vector<vector<int> > z(n);
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            int k=i*n+j;
            if(i<n/2) {
                z[j].push_back(k);
            }
            else {
                z[n-1-j].push_back(k);
            }
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", z[i][j]+1);
        }
        printf("\n");
    }


    return 0;
}
