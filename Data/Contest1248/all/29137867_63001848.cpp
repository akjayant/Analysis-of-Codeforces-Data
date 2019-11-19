/// I won't go back on my words ... that's my ninja way !!!
#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+5 ;
int n ;
char str[N] ;
int mx = -1e9 ,a ,b ;
int solve(){
    deque<int> needOpen ,Open ;
    int o = 0 ,no = 0 ;
    for(int i=0;i<n;++i){
        if(str[i]=='(') ++o ;
        else if(o) --o ;
        else ++no ;
        if(!o) needOpen.push_back(no);
        else needOpen.push_back(-2);
    }
    o = 0 ;
    int c = 0;
    for(int i=n-1;i>=0;--i){
        if(str[i]=='('){
            if(c) --c ;
            else ++o ;
        }
        else ++c ;
        if(!c) Open.push_front(o) ;
        else Open.push_front(-1);
    }
    int ret = needOpen[n-1]==0 ;
    for(int i=0;i+1<n;++i){
        if(needOpen[i] == Open[i+1]) ++ret ;
    }
    return ret;
}
int main(){
    scanf("%d%s",&n,str);
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            swap(str[i],str[j]) ;
            int s = solve() ;
            if(s > mx) mx = s ,a=i+1 ,b=j+1 ;
            swap(str[i],str[j]) ;
        }
    }
    printf("%d\n%d %d",mx,a,b);
    return 0;
}
