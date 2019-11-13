#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <set>
#define ll long long
#define MODD 1000000007
using namespace std;

int Solve(int pos, const string& S) {
    
    if (pos == S.size())
        return 1;
    
    if (S[pos]=='w' || S[pos]=='m')
        return 0;
    
    int ans = Solve(pos+1, S);
    
    if (pos < S.size()-1 && S[pos]==S[pos+1] && S[pos]=='u') {
        ans += Solve(pos+2, S);
        ans %= MODD;
    }
    
    if (pos < S.size()-1 && S[pos]==S[pos+1] && S[pos]=='n') {
        ans += Solve(pos+2, S);
        ans %= MODD;
    }
    
    return ans;
    
}

ll dp[111111];

int Solve(const string& S) {
    int L=S.size();
    for(int pos=L;pos>=0;pos--) {
        if (pos == L) {
            dp[pos]=1;
            continue;
        }
        
        if (S[pos]=='w' || S[pos]=='m') {
            dp[pos]=0;
            continue;
        }
        
        int ans = dp[pos+1];
        
        if (pos < S.size()-1 && S[pos]==S[pos+1] && S[pos]=='u') {
            ans += dp[pos+2];
            ans %= MODD;
        }
        
        if (pos < S.size()-1 && S[pos]==S[pos+1] && S[pos]=='n') {
            ans += dp[pos+2];
            ans %= MODD;
        }
        dp[pos]=ans;
    }
    return dp[0];
}


int main() {
    string S;
    cin>>S;
    
    cout << Solve(S) << endl;
}
