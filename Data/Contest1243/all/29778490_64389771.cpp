#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

bool siv[1000006];
ll n;
vector<ll>v;

void gen() {

    for(ll i=2;i<=1000000;i++) {
        if(siv[i]) continue;

        if(n%i==0) {
            v.push_back(i);
        }
        while(n%i==0) {
            n/=i;
        }

        for(ll j=i+i;j<=1000000;j+=i) {
            siv[j]=1;
        }
    }
}

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("testcases.txt", "r", stdin);

    cin>>n;

    if(n==1) {
        cout<<1<<endl;
        return 0;
    }

    gen();

    if(n!=1) {
        v.push_back(n);
    }

    if(v.size()>1) {
        cout<<1<<endl;
        return 0;
    }

    cout<<v[0]<<endl;




    
    







 
    return 0;
}