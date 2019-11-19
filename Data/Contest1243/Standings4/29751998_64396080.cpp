#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long t,m,n,d,x,y;
    cin>>n;
    long long p=2;
    vector<int>k;
    while (p<=sqrt(n)+1){
        if (n%p==0){
            n=n/p;
            k.push_back(p);
            if (k[k.size()-1]%k[0]!=0){
                cout<<1;
                return 0;
            }
        }else{
            p++;
        }
    }
    if (k.size()!=0 and n!=1){
        k.push_back(n);
            if (k[k.size()-1]%k[0]!=0){
                cout<<1;
                return 0;
            }
    }
    if (k.size()==0){
        cout<<n;
    }else{
    cout<<k[0];
    }
}
