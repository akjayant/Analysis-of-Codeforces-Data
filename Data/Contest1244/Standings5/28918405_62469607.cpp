#include <bits/stdc++.h>

using namespace std;

long long t,a,b,c,d,k,x,y,n;
string s;

int main()
{
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        cin>>s;
        x=0;
        y=0;
        for(int j=0;j<=n;j++){
            if(s[j]=='0')x++;
            else break;
        }
        for(int j=n-1;j>=0;j--){
            if(s[j]=='0')y++;
            else break;
        }
        if(x==n)cout<<n<<endl;
        else cout<<max((n-y)*2,(n-x)*2)<<endl;
    }
    return 0;
}
