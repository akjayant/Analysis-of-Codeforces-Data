#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define yoi cout<<"yo"<<endl;
#define debug(x) cerr << #x << " is " << x << endl;
#define all(x) x.begin(),x.end()
const lli inf=1e18;
const int mod=1e9+7;
int main(){
IOS;
int t;
cin>>t;
while(t--){
    int a,b,c;
    cin>>a>>b>>c;
    int x=c/2;
    int ans=0;
    if(b>x){
        b-=x;
        ans+=3*x;
        ans+=3*(min(a,b/2));
        cout<<ans<<endl;
    }
    else{
        cout<<3*b<<endl;
    }
}
}
