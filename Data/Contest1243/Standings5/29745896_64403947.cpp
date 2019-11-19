#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pcc pair<char,char>
using namespace std;
const int maxn=1e4+7;
vector<ll>ve;
int main()
{
    ll n;
    scanf("%lld",&n);
    ll tem=n;
    for(ll i=2;i*i<=tem;i++){
        if(tem%i==0){
            while(tem%i==0)tem/=i;
            ve.push_back(i);
            if(ve.size()>=2){
                printf("1\n");
                return 0;
            }
        }
    }
    if(tem!=1)ve.push_back(tem);
    if(ve.size()==0)printf("%lld\n",n);
    else if(ve.size()==1)printf("%lld\n",ve[0]);
    else printf("1\n");
    return 0;
}
