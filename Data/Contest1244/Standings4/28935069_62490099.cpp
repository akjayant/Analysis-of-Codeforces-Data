#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int n,k;
    cin>>n>>k;
    unsigned long long int i,array[n],aray[n];
    for(i=0;i<n;i++)
        cin>>array[i];
    sort(array,array+n);
    unsigned long long int x=1;
    aray[0]=array[1]-array[0];
    while(x!=(n-1))
    {
        if((x%2)==0)
            aray[x]=aray[x-1]+(array[x/2+1]-array[x/2])*(x/2+1);
        else
            aray[x]=aray[x-1]+(array[n-(x+1)/2]-array[n-(x+3)/2])*(x+1)/2;
        x++;
    }
    if(k<=aray[0])
        cout<<array[n-1]-array[0]-k<<"\n";
    else if(k>=aray[n-2])
        cout<<"0\n";
    else
    {
        for(i=n-1;i>0;i--)
        {
            if((k<aray[i])&&(k>=aray[i-1]))
                break;
        }
        unsigned long long int y=k-aray[i-1];
        if((i%2)==0)
            cout<<array[n-1-i/2]-array[i/2]-y/(i/2+1)<<"\n";
        else
            cout<<array[n-(i+1)/2]-array[(i+1)/2]-2*y/(i+1)<<"\n";
    }
    return 0;
}