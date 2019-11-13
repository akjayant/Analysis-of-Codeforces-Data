#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i,j,n;
    int t;
    cin>>t;
    while(t>0)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int max=0;
        if(c%2!=0)
            c-=1;
        c/=2;
        if(b>c)
        {
            max+=(3*c);
            b-=c;
            if(b%2!=0)
                b-=1;
            b/=2;
            if(a>b)
            {
                max+=(3*b);
            }
            else
            {
                max+=(3*a);
            }
        }
        else
        {
            max+=(3*b);
        }
        

        cout<<max<<endl;

        t--;
    }
    
}