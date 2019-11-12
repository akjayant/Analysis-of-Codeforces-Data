#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;

int a[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,t;
    cin>>t;
    while(t--){
        cin>> n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);
        int ma=0;
        for(int i=1;i<=n;i++){
            ma=max(ma,min(n-i+1,a[i]));
        }
        cout<<ma<<endl;
    }
    return 0;
}
