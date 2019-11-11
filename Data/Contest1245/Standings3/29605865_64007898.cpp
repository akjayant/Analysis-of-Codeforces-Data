#include<iostream>
#include<string.h>
using namespace std;
char s[1010],ss[1010];
int main(){
    int i,n,t,a,b,c;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a>>b>>c;
        cin>>s;

        memset(ss,0,sizeof(ss));
        int k=0;
        for(i=0;i<n;i++){
            if(s[i]=='P'&&c){
                c--;
                ss[i]='S';
                k++;
            }
            if(s[i]=='S'&&a){
                a--;
                ss[i]='R';
                k++;
            }
            if(s[i]=='R'&&b){
                b--;
                ss[i]='P';
                k++;
            }
        }

        for(i=0;i<n;i++){
            if(ss[i]==0){
                if(a){
                    a--;
                    ss[i]='R';
                }
                else if(b){
                    b--;
                    ss[i]='P';
                }
                else if(c){
                    c--;
                    ss[i]='S';
                }
            }
        }

        if(k*2>=n){
            cout<<"YES"<<endl;
            cout<<ss<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;

}


