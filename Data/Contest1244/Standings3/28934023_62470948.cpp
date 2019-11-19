#include <iostream>
#include <string>

using namespace std;

int T,N;
string ST;
int main(){
    cin >> T;
    while (T--){
        cin >> N;
        cin >> ST;
        int BG=N,ED=-1;
        for (int i=0;i<ST.size();i++)
            if (ST[i]=='1') {
                BG=min(BG,i);
                ED=max(ED,i);
            }
        cout << max(N,max(2*(N-BG),2*(ED+1))) << endl;
    }
}