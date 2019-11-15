#include <string.h>
#include <unordered_map>

#include <sstream>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <set>

#include <map>
#include <vector>
#include <string>
#include <stdlib.h>

#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define _clr(x) memset(x,-1,sizeof(x))
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define frr(i,a,b) for(int i = a; i > b; --i)
#define pb push_back
#define sf scanf

#define pf printf
#define mp make_pair
#define N 1000

using namespace std;

int mod = 1e9+7;

int g[N][N];

void sol() {
    int n;
    cin>>n;

    int s = n*n;
    for(int i = 0; i < n; ++i) {
        if(i&1) {
            for(int j = 0; j < n; ++j) {
                g[j][i] = s--;
            }
        }
        else {
            for(int j = n-1; j >=0; --j) {
                g[j][i] = s--;
            }
        }
    }

    fr(i,0,n) {
        fr(j,0,n) {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    sol();
}