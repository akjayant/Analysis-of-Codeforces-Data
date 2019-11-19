#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
#include<limits>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n;
    cin>>n;

    if(n==1) {
        cout<<1<<endl;
        return 0;
    }

    vector<long long>num;

    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            num.push_back(i);
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n>1) num.push_back(n);

    if(num.size()==1){
        cout<<num[0]<<endl;
    }else{
        cout<<1<<endl;
    }


    return 0;
}
