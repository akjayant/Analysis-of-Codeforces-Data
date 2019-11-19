#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    long long int k,i,j,n,u,res,r,a,b,f,m;


    cin>>n;

    u=0;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0 && u==0) {u++; m=i; break;}
        else if(n%i==0) u++;
    }




    if(u==0) cout<<n<<endl;
    else
    {
        while(n%m==0) n/=m;
        if(n==1) cout<<m<<endl;
        else cout<<1<<endl;
    }


    return 0;
}
