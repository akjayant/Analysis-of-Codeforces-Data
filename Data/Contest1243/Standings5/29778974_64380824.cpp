#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+10;

char a[N],b[N];
int c[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cin>>a+1>>b+1;
        int cnt=0;
        int bj=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i])c[cnt++]=i;
        }
        if(cnt==1||cnt>=3)bj=1;
        if(cnt==2){
            if(b[c[0]]==b[c[1]]&&a[c[0]]==a[c[1]])bj=0;
            else bj=1;
        }
        if(bj)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
