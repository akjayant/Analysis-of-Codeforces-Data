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
    int t,m,n,d;
    cin>>t;
    while (t--){
        cin>>n;
        vector<int>k(n);
        for (int i=0;i<n;i++){
            cin>>k[i];
        }
        m=0;
        sort(k.begin(),k.end());
        for (int i=n-1;i>-1;i--){
            d=min(n-i,k[i]);
            m=max(m,d);
        }
        cout<<m<<endl;
    }
}
