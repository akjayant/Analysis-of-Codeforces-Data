#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int i,array[n],sum=0,total=0;
    for(i=0; i<n; i++)
    {
        cin>>array[i];
        total+=array[i];
    }
    sort(array,array+n);
    for(i=0; i<n/2; i++)
        sum+=array[i];
    cout<<sum*sum+(total-sum)*(total-sum)<<"\n";
    return 0;
}