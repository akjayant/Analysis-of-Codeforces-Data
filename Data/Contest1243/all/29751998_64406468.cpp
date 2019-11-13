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
    long long t,n,p,ind;
    char m;
    cin>>t;
    string a,b;
    while (t--){
        cin>>n;
        cin>>a>>b;
        vector<int>x;
        vector<int>y;
        ind=0;
        for (int i=0;i<n;i++){
            m=a[i];
            if (b[i]!=m){
            p=0;
            for (int j=i+1;j<n;j++){
                //cout<<a[j]<<' '<<m<<endl;
                if (a[j]==m){
                    ind++;
                    a[j]=b[i];
                    b[i]=m;
                    //cout<<a[3]<<' '<<b[3];
                    x.push_back(j+1);
                    y.push_back(i+1);
                    p=1;
                    break;
                }
            }
            if (p==0){
                for (int j=i+1;j<n;j++){
                    if (b[j]==m){
                        b[j]=a[j];
                        a[j]=m;
                        x.push_back(j+1);
                        y.push_back(j+1);
                        x.push_back(j+1);
                        y.push_back(i+1);
                        a[j]=b[i];
                        b[i]=m;
                        ind+=2;
                        p=1;
                        break;
                    }
                }
                if (p==0){
                    //cout<<i<<' ';
                    cout<<"No"<<endl;
                    ind=-1;
                    break;
                }
            }
        }
        }
        if (ind!=-1){
            cout<<"Yes"<<endl;
        cout<<ind<<endl;
        }
        for (int i=0;i<ind;i++){
            cout<<x[i]<<' '<<y[i]<<endl;
        }
    }
}
