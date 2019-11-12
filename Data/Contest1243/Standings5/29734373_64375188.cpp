#include <bits/stdc++.h>
using namespace std;

int main() {
   
    int q;
    cin>>q;
    while(q--)
    {
        long long j,k,n,i,sum=0,count=0,ans=0,c,d,e,m;
        cin>>n;
        long long a[n];
        for(i=0;i<n;i++)
       cin>>a[i];
         sort(a,a+n);
         ans=0;
         for(i=n-1;i>=0;i--)
         {
             if(a[i]>=(n-i))
             ans++;
         }
        
        cout<<ans<<endl;
    }
     
    
	return 0;
}