#include <iostream>
#include <algorithm>
#include <set>
#include "vector"
#include "queue"
#include <math.h>

using namespace std;

int main() {
    //int n;
    long long int n;
    cin >> n;
    //int pr = n;
    int del = -1;
    //vector<int> del;
    for (int i = 2; i < (sqrt(n) + 1); i++) {
        if (n % i == 0) {
            del = i;
            break;
//            while(n % i == 0) {
//                n /= i;
//            }
//            del.push_back(i);
        }
    }
    if (del == -1) {
        cout << n;
        return 0;
    } else {
        long long int delBig = n/del;
        while(delBig % del == 0) {
            delBig /= del;
        }
        if (delBig == 1) {
            cout << del;
        } else {
            cout << 1;
        }
    }

//    if (del.empty()) {
//        cout << n;
//        return 0;
//    }
//    if (del.size() > 1) {
//        cout << 1;
//    } else {
//        int delS = pr/del[0];
//
//    }
}
