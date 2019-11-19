#include<bits/stdc++.h>
using namespace std;



void f(){
    int n;cin>>n;
    string s;cin>>s;
    
    int data[1234] = {0,};
    int MIN = 1234;
    int MAX = -1234;
    for(int i = 0;i<n;i++){
        if(s[i] == '1'){
            MIN = min(MIN,i);
            MAX = i;
        }
    }
    
    
    if(MIN != 1234){ 
        int left = 2*(MAX+1);
        int right = 2*(n-MIN);
        cout<<max(left,right)<<"\n";
    }else{
        cout<<n<<"\n";
    }
    
}

int main(int argc, char *argv[]){
    int t;cin>>t;
    
    for(int i = 0;i<t;i++){
        f();
    }
    

   
    return 0;
}