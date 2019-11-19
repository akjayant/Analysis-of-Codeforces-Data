#include<bits/stdc++.h>
using namespace std;
long long n;
long long pttsnt(long long x)
{
    long long tmp=x,maxtmp=0;
    int d=0;
    for(int i=2;i<=sqrt(x);i++){
            if(tmp%i==0)
            {
                d++;
                while(tmp%i==0 && tmp>1) {maxtmp=max(maxtmp,(long long)i);tmp/=i;}
            }
            if(tmp==1) break;
    }
    if(tmp!=1) {d++;maxtmp=tmp;}
    if(d==1) return maxtmp;
    else return 1;
}
int main()
{
    cin>>n;
    long long a=pttsnt(n);
    cout<<a;
}
