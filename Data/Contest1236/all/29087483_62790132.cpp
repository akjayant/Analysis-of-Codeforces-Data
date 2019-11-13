//I_love_StarnyC 
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define f first
#define s second
#define pb push_back
#define fix  cout<<std::fixed;
#define mk make_pair
#define mod 1000000007
#define time  cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
#define IOS        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
 ll n;
 cin>>n;
 ll a[n][n];
 ll l=1;
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<n;j++)
    {
        if(i%2==0)
        a[j][i]=l;
        if(i%2==1)
            a[n-j-1][i]=l;
        l++;
    }
 } 
 for(int i=0;i<n;i++)
 {
    for(int j=0;j<n;j++)
        cout<<a[i][j]<<" ";
    cout<<endl;
 }  
}