#include<bits/stdc++.h> 
using namespace std;
int mod=1000000007;
#define MAXN 1000000 
  
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, temp,prime=-1;;
    cin>>n;
    temp=n;
    int p=0,ans=0;
    if(n%2==0)
        p+=1;
    while (n % 2 == 0)  
    {
        prime=2;
        n = n/2;  
    } 
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {   
        if(n%i==0)
            p+=1;
        while (n % i == 0)  
        {  
            prime=i;
            n = n/i;  
        }  
    }  

    if(n>2)
    {
        p+=1;
        if(p>=2)
            ans=1;
        prime=n;
    }
    if(p>=2)
        ans=1;

    if(temp==1)
        ans=1;
    if(ans==1)
        cout<<"1"<<endl;
    else
    {
        if(p==1)
            cout<<prime<<endl;

        
    }
}