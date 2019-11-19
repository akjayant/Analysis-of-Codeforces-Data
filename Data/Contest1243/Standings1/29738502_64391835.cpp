#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
int main()
{
 //freopen("bath.in","r",stdin);
 //freopen("bath.out","w",stdout);
 ios_base::sync_with_stdio(0);
 long long n;
 cin>>n;
 vector<long long> del;
 for(int i=2;i<=1e6;i++)if(a[i]==0){
    del.push_back(i);
    long long j=i+i;
    while(j<=1e6){
        a[j]=1;
        j+=i;
    }
 }
 long long kol=0,mi=0;
 for(int i=0;i<del.size();i++)if(n%del[i]==0){
    kol++;
    if (mi==0) mi=del[i];
    while(n%del[i]==0){
        n/=del[i];
    }
 }
 if (n!=1) {kol++;if (mi==0) mi=n;}
 if (kol==1) {cout<<mi;}
 else cout<<1;
}


