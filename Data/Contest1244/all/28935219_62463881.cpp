#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main()
{
   IO;
   int t;
   cin>>t;
   while(t--){
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    int p = (a+c-1)/c;
    int bb = (b+d-1)/d;
    if(p+bb>k){
        cout<<"-1\n";
    }
    else cout<<p<<" "<<bb<<endl;
   }
}
