/// I won't go back on my words ... that's my ninja way !!!
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5 ;
int n ,a ;
deque<int> dq ;
long long x ,y ;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        dq.push_back(a);
    }
    bool flag = 1 ;
    sort(dq.rbegin(),dq.rend());
    while(dq.size()){
        if(flag){
            x+= dq.front() ;
            dq.pop_front();
        }
        else{
            y += dq.back() ;
            dq.pop_back();
        }
        flag = 1 - flag ;
    }
    cout << x*x + y*y ;
    return 0;
}
