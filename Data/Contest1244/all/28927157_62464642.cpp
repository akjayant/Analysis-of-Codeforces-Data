#include<bits/stdc++.h>
using namespace std;



void f(){
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    
    int x = (a+c-1)/c;
    int y = (b+d-1)/d;
    
    if(x+y > k){
        cout<<-1<<"\n";
    }else{
        cout<<x<<" "<<y<<"\n";
    }
}

int main(int argc, char *argv[]){
    int t;cin>>t;
    
    for(int i = 0;i<t;i++){
        f();
    }
    

   
    return 0;
}