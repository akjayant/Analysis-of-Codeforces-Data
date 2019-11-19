#include <iostream>
#include <string>
using namespace std;

int n,mn,c;
string s;

int cnt(){
    mn=c=0;
    for(int i=0;i<n;i++){
        if(s[i]=='(') c++;
        else c--;
        mn=min(mn,c);
    }
    int res=0;
    if(mn==0) res++;
    for(int i=n-1;i>0;i--){
        if(s[i]=='('){
            mn=min(0,mn+1);
            if(mn==0) res++;
        }
        else mn--;
    }
    return res;
}

int main() {
    cin >> n >> s;
    int c1, c2, pos1 = -1, pos2 = -1;
    c1 = c2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            c1++;
            if (pos1 == -1) pos1 = i;
        } else {
            c2++;
            if (pos2 == -1) pos2 = i;
        }
    }
    if (c1 != c2) {
        cout << "0\n1 1\n";
    } else {
        int mx = cnt();
        int i1 = 1, i2 = 1, temp;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] != s[j]) {
                    if (s[i] == '(') s[i] = ')';
                    else s[i] = '(';
                    if (s[j] == '(') s[j] = ')';
                    else s[j] = '(';

                    temp = cnt();
                    if (temp > mx) {
                        mx = temp;
                        i1 = i, i2 = j;
                    }

                    if (s[i] == '(') s[i] = ')';
                    else s[i] = '(';
                    if (s[j] == '(') s[j] = ')';
                    else s[j] = '(';
                }
            }
        }
        cout << mx << "\n";
        cout << i1 + 1 << " " << i2 + 1 << "\n";
    }
    return 0;
}