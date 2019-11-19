#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
long long mod=1000000007;

int main()
{
    fastio;
    long long n;
    long long smallest;
    long long count=0;
    cin>>n;
    long long temp=n;
    bool first=false;
    for(long long i=2;i*i<=n;i++){
        if(temp%i==0){
            if(!first){
            smallest=i;
            first=true;
            }
            count++;
            while(temp%i==0)
            temp/=i;
        }
    }
    if(temp!=1)
    {count++;
    if(!first){
            smallest=temp;
            first=true;
            }
    }
    if(count!=1)
    cout<<1;
    else 
    cout<<smallest;
}