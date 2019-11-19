#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,p,d,w,i,mx,rest;
    cin>>n>>p>>w>>d;
    mx = min(n,p/w);
    for(i=0;i<200000;i++){
        rest = p - (mx*w);
        if(rest%d==0 && (rest/d)+mx<=n){
            cout<<mx<<' '<<rest/d<<' '<<n-mx-rest/d<<'\n';
            return 0;
        }
        mx--;
        if(mx==-1)break;
    }
    cout<<"-1\n";
	return 0;
}
