#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t,a,b,c,d,k,x,y;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        x=a/c;
        if(a%c)x++;
        y=b/d;
        if(b%d)y++;
        if(x+y<=k)cout<<x<<' '<<y<<endl;
        else cout<<"-1\n";
    }
	return 0;
}
