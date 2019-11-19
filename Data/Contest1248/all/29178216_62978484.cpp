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


int n,m;
int s1,s2;


int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        long long ans = 0;
        s1 = s2 = 0;
        cin>>n;
        for(int i=0;i<n;i++) {
            int a;
            cin>>a;
            if(a%2 ==0) {
                s1++;
            }
            else {
                s2++;            
            }
        } 
        cin>>m;
        for(int i=0;i<m;i++) {
            int a;
            cin>>a;
            if(a%2==0) ans += s1;
            else ans += s2;
        }
        cout<<ans<<endl;
    }
    return 0;
}