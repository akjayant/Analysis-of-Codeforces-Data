#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int maxn=2e5;
const int mod=1e9+7;
int n;
int cal(int a,int b)
{
    if(a%b==0) return a/b;
    return a/b+1;
}
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int x=cal(a,c);
        int y=cal(b,d);
        if(x+y>k) cout<<-1<<endl;else cout<<x<<" "<<y<<endl;
    }
    return 0;
}
