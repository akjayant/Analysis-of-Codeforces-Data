#include<iostream>
using namespace std;
int main()
{
    long long int n,m;
    cin>>n>>m;
    int array[max(n,m)+1];
    long long int z=1000000007,i;
    array[1]=2;
    array[2]=4;
    for(i=3;i<=max(n,m);i++)
        array[i]=(array[i-1]+array[i-2])%z;
    cout<<(array[n]+array[m]+z-2)%z<<"\n";
    return 0;
}