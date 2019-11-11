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
#define ll long long
using namespace std;


int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int n;
        cin>>n;
        int r,p,s;
        cin>>r>>p>>s;
        
        string S;
        cin>>S;
        
        string ans;
        int ct=0;
        for(int i=0;i<n;i++) {
            if (S[i]=='R') {
                if (p > 0) {
                    ans.push_back('P');
                    p--;
                    ct++;
                } else {
                    ans.push_back('#');
                }
            } else if (S[i]=='P') {
                if (s > 0) {
                    ans.push_back('S');
                    s--;
                    ct++;
                } else {
                    ans.push_back('#');
                }
            } else if (S[i]=='S') {
                if (r > 0) {
                    ans.push_back('R');
                    r--;
                    ct++;
                } else {
                    ans.push_back('#');
                }
            }
        }
        
        if (ct < (n+1)/2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for(int i=0;i<ans.size();i++) {
                if (ans[i]=='#') {
                    if (r > 0) {
                        ans[i]='R';
                        r--;
                    } else if (p > 0) {
                        ans[i]='P';
                        p--;
                    } else {
                        ans[i]='S';
                        s--;
                    }
                }
            }
            cout << ans << endl;
        }
        

    }
}
