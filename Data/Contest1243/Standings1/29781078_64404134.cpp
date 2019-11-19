#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
long long n;
vector<long long >v;

int main() {
    cin>>n;
    for(long long i=2;i*i<=n;i++){
        while(n%i==0){
            n/=i;
            v.push_back(i);
        }
    }
    if(n!=1){
        v.push_back(n);
    }
    if(v.size()==0){
        cout<<n<<endl;
        return 0;
    }
    if(v[0]!=v[v.size()-1]){
        cout<<1<<endl;
        return 0;
    }
    cout<<v[0]<<endl;

    return 0;
}