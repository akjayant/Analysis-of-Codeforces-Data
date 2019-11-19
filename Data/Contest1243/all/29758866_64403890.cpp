#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long int n, first=0;
    cin>>n;
    for(int i=2;i<=int(sqrt(n))+1;i++){
        if (n%i==0){
            while (true)
            {
                n/=i;
                if (n==1){
                    cout<<i<<endl;
                    return 0;
                }
                if (n%i!=0){
                    cout<<1<<endl;
                    return 0;
                }
            }
            
        }
    }
    cout<<n<<endl;
    
    return 0;
}