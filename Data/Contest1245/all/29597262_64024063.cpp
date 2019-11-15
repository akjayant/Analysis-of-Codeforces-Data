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

ll gcd(ll a, ll b) {
    while(b!=0) {
        ll t = b;
        b=a%b;
        a=t;
    }
    return a;
}

int main() {
    int T;
    cin>>T;
    for(int t=1;t<=T;t++) {
        int a,b;
        cin>>a>>b;
        if (gcd(a,b)==1)
            printf("Finite\n");
        else
            printf("Infinite\n");

        
        
    }
    
}
