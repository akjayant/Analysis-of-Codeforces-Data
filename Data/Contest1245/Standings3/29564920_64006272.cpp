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
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a,b,c;
        cin>>a>>b>>c;
        string str;
        cin>>str;
        int r = 0, p = 0, s = 0;
        fr(i,0,str.size()) {
            if(str[i]=='R') r++;
            else if(str[i]=='S')s++;
            else p++;
        }

        int num = min(a,s) + min(b,r) + min(c,p);;
        if(num >= (n+1)/2) {
            printf("YES\n");
            for(int i = 0; i < str.size();++i) {
                if(str[i]=='R') {
                    if(b>0){
                        str[i] = 'P';
                        b--;
                    }
                    else {
                        str[i] = 'a';
                    }
                }
                else if(str[i]=='S') {
                    if(a>0) {
                        str[i] = 'R';
                        a--;
                    }
                    else {
                        str[i] = 'a';
                    }
                }
                else {
                    if(c>0) {
                        str[i] = 'S';
                        c--;
                    }
                    else {
                        str[i] = 'a';
                    }
                }
            }
            fr(i,0,str.size()) {
                if(str[i]=='a') {
                    if(a>0) str[i] = 'R',a--;
                    else if(b>0) str[i] = 'P',b--;
                    else str[i] = 'S', c--;
                }
            }
            cout<<str<<endl;
        }
        else {
            printf("NO\n");
        }
    }
}