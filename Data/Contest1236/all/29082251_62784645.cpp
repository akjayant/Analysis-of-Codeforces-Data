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
#define N 1000000

using namespace std;

void sol() {
    int a,b,c;
    cin>>a>>b>>c;
    int ans = 0;
    ans += min(b,c/2);
    b-= ans;
    ans += min(a,b/2);
    cout<<ans*3<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
        sol();
}