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
#include <bitset>
#define MAXN 1100000
#define ll long long
using namespace std;


int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int L;
        cin>>L;
        string S;
        cin>>S;
        
        int ans = L;
        
        for(int i=0;i<L;i++) {
            if (S[i]=='1') {
                ans = max(ans, 2*(i+1));
                ans = max(ans, L+1);
                ans = max(ans, 2*(L-i));
            }
        }
        cout << ans << endl;
        
        
    }
}
