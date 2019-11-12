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
    int t,m,n,d,x,y;
    cin>>t;
    string a,b;
    while (t--){
        cin>>n;
        cin>>a>>b;
        vector<int>k;
        for (int i=0;i<n;i++){
            if (a[i]!=b[i]){
                k.push_back(i);
            }
        }
        if (k.size()>2 or k.size()==1){
            cout<<"No";
        }else if (k.size()==0){
            cout<<"Yes";
        }else{
            x=k[0];
            y=k[1];
            if (b[y]==b[x] and a[x]==a[y]){
                cout<<"Yes";
            }else{
                cout<<"No";
            }
        }
        cout<<endl;
    }
}
