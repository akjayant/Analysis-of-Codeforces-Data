#include<iostream>
#include<queue>
#include <cstring>
using namespace std;


char answ[1010];
int book[1010];
int main(){
	int t;
	cin>>t;
	int n;
	int a,b,c;
	string s;
	int win;
	int nwin;
	while(t--){
		cin>>n;
		win=n/2;
		if(n%2) win++;
		cin>>a>>b>>c;
		cin>>s;
		memset(book,0,sizeof(book));
		nwin=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='R'){
			    if(b){
			        b--;
			        book[i]=1;
			        answ[i]='P';
			        nwin++;
			    }
			}
			if(s[i]=='P') {
                if(c){
                    c--;
                    book[i]=1;
                    answ[i]='S';
                    nwin++;
                }
			}
			if(s[i]=='S') {
                if(a){
                    a--;
                    book[i]=1;
                    answ[i]='R';
                    nwin++;
                }
			}
		}
        if(nwin>=win){
            cout<<"YES"<<endl;
            for(int i=0;i<s.size();i++){
                if(book[i]) continue;
                if(a){
                    answ[i]='R';
                    a--;
                }
                else if(b){
                    answ[i]='P';
                    b--;
                }
                else if(c){
                    answ[i]='S';
                    c--;
                }
            }
            for(int i=0;i<s.size();i++){
                cout<<answ[i];
            }
            cout<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
	}
	return 0;
}