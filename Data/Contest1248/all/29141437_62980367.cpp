#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int t,n,m,kp,sp,kq,sq,i,j;
    vector <long long int> p(1000000);
    vector <long long int> q(1000000);
    cin>>t;
    for(i=0; i<t; i++){
        cin>>n;
        kp=0;
        sp=0;
        kq=0;
        sq=0;
        for (j=0; j<n; j++){
            cin>>p[j];
            if (p[j]%2==0) kp++;
            else sp++;
        }
        cin>>m;
        for (j=0; j<m; j++){
            cin>>q[j];
            if (q[j]%2==0) kq++;
            else sq++;
        }
        cout<<kp*kq+sp*sq<<endl;

    }
    return 0;
}
