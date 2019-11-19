#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t,n,i,mx,cnt;
    string str;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>str;
        cnt=mx=0;
        for(i=0;i<n;i++){
            cnt++;
            if(str[i]=='1')mx=cnt;
        }
        cnt=0;
        for(i=n-1;i>=0;i--){
            cnt++;
            if(str[i]=='1')mx = max(mx,cnt);
        }
        cout<<max(mx*2,n)<<'\n';
    }
	return 0;
}
