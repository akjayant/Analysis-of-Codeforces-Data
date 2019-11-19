#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ifstream fin("AAtest.in.txt");
ll n,arv[1000005],l;
vector<ll> teg;
bool b;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
    cin>>n;
    for(int i=2; i<=sqrt(n)+1; i++) if(!arv[i]){
        b=0;
        while(n%i==0) n/=i,b=1;
        if(b) teg.push_back(i);
        l=2*i;
        while(l<=sqrt(n)+1){
            arv[l]=1;
            l+=i;
        }
    }
    if(n>1) teg.push_back(n);
    if(teg.size()==1) cout<<teg[0]<<"\n";
    else cout<<1;
}
