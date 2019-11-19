#include <iostream>
#include <cassert>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <time.h>
#define ll long long
#define INF 100000000000000ll
using namespace std;


int main() {
    
    // (10,1)...(10,10)
    // (9,10)...(9,1)
    vector<pair<int,int>> S;
    for(int x=10;x>=1;x--) {
        if (x%2==0) {
            for(int y=1;y<=10;y++)
                S.push_back({x,y});
        } else {
            for(int y=10;y>=1;y--)
                S.push_back({x,y});
        }
    }
    
    int n = S.size();

    int conns[111];
    for(int i=0;i<n;i++)
        conns[i]=-1;
    
    
    for(int x=1;x<=10;x++)
        for(int y=1;y<=10;y++) {
            int L;
            cin>>L;
            if (L > 0) {
                // (x,y) to (x-L, y)
                int fr=-1;
                int to=-1;
                for(int j=0;j<S.size();j++) {
                    if (S[j].first==x && S[j].second==y)
                        fr=j;
                    if (S[j].first==x-L && S[j].second==y)
                        to=j;
                }
                conns[fr]=to;
            }
        }
    
    
    double E[111];
    
    E[n-1]=0;
    const double prob = 1.0/6.0;
    for(int i=n-2;i>=0;i--) {
        
        double self_term = 0;
        double other_term = 0;
        
        for(int s=1;s<=6;s++) {
            if (i+s<=n-1) {
                
                if (conns[i+s]!=-1) {
                    other_term += prob * min(E[i+s],E[conns[i+s]]);
                } else {
                    other_term += prob * E[i+s];
                }
            } else {
                self_term += prob;
            }
        }
        
        // E[i] = 1 + self_term * E[i]+other_term
        E[i] = (1 + other_term) / (1.0 - self_term);
    }
    
    
    printf("%1.10f\n",E[0]);
    
    
    
    
}
