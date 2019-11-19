#include <iostream>
 
using namespace std;
 
long long n,p,w,d,i;
int main(){
    cin >> n >> p >> w >> d;
    long long LIMIT=(w*n-p)/(w-d);
    for (i=0;i<=min(w,p/d);i++)
        if ((p-d*i)%w==0 && (n-(p-d*i)/w-i>=0)){
            cout << (p-d*i)/w << " " << i << " " << n-(p-d*i)/w-i ;
            break;
        }
    if (i==min(p/d,w)+1)
        cout << -1;
}