#include <iostream>

using namespace std;

int t,a,b,c,ans;

int main()
{
    cin>>t;
    while(t--){
      cin>>a>>b>>c;
      ans=0;
      for(int i=0;i<=a;i++)
        if(2*i<=b)
          ans=max(ans,3*i+3*(min(b-2*i,c/2)));
      cout<<ans<<'\n';
    }
    return 0;
}
