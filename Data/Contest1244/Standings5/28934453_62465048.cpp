#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int ansc,ansd;
        ansc=a/c+(a%c!=0);
        ansd=b/d+(b%d!=0);
        if(ansc+ansd>k)
        {
            cout<<-1<<endl;
        }
        else cout<<ansc<<" "<<k-ansc<<endl;
    }
    return 0;
}
