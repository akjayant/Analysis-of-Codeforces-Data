#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main()
{
   IO;
   int t;
   cin>>t;
   while(t--){
    int n,last = 0,first = -1;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++) if(s[i]=='1'){ first = i+1; break;}
    for(int i=0;i<n;i++) if(s[i]=='1') last = i+1;
    if(first==-1) cout<<n<<endl;
    else cout<<max(2*last,max((n-first+1)*2,n))<<endl;
   }
}
