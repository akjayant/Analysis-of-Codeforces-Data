#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

vector<long long >a;
void getg(long long tmp){
    for(long long i=2;i<=tmp/i;i++){
        if(tmp%i==0){
            a.push_back(i);
            while(tmp%i==0)tmp/=i;
        }
    }
    if(tmp!=1)a.push_back(tmp);
}

const int maxn=1e6+10;
int num[maxn];

int main(){
    long long x;
    scanf("%lld",&x);
    getg(x);
    /*
    for(int i=0;i<(int)a.size();i++){
        printf("%lld ",a[i]);
    }printf("\n");
    */
    long long ans=x;
    if((int)a.size()==1&&ans!=a[0]){
            ans=a[0];
    }
    if((int)a.size()==1)printf("%lld\n",ans);
    else{
        printf("1\n");
    }

    return 0;
}