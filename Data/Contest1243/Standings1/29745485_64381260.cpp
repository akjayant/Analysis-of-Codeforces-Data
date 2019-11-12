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

int n;
string s1,s2;


int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        cin>>n>>s1>>s2;
        int p=0,dif1 = -1,dif2= -1;
        for(int i=0;i<n;i++) {
            if(s1[i] != s2[i]) {
                p++;
                int d1 = s1[i],d2=s2[i];
                if(dif1 == -1) dif1 = d1;
                else if(dif1 != d1) dif1 = -2;
                if(dif2 == -1) dif2 = d2;
                else if(dif2 != d2) dif2 = -2;
                
            }
        }
        if(p==0 || (p==2 && dif1 >=0 && dif2 >=0)) {
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}