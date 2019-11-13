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

const int mod = 1000000007;

int dp[N];
int main() {
    string s;
    cin>>s;

    dp[0]= 1;
    dp[1] = 1;
    if(s[0]=='w'||s[0]=='m')dp[1] = 0;

    for(int i = 1; i <s.size();++i) {
        if(s[i]=='u'&&s[i-1]=='u') {
            dp[i+1] = (dp[i+1] + dp[i-1])%mod;
        }
        else if(s[i]=='n'&&s[i-1]=='n') {
            dp[i+1] = (dp[i+1] + dp[i-1])%mod;
        }
        if(s[i]=='w'||s[i]=='m') {
            dp[i+1] = 0;
        }
        else {
            dp[i+1] = (dp[i+1] + dp[i])%mod;
        }
    }
    cout<<dp[s.size()]<<endl;
}