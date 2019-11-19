#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iterator>

#define mod 1000000007

using namespace std;




int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int temp_sum = 0;
    for (int i = 0; i<n; i++) {
        if (s[i]==')') temp_sum++;
        else temp_sum--;
    }
    if (temp_sum != 0) {
        cout << 0 << endl;
        cout << "1 1"<<endl;
        return 0;
    }
    int max_cyc = 0;
    int max_i = 0;
    int max_j = 0;
    for (int i = 0; i<n; i++) {
        for (int j = i; j<n; j++) {
            string temp = s;
            swap(temp[i], temp[j]);
            int sum = 0;
            int min_s = 0;
            int max_temp = 0;
            for (int k = 0; k<n; k++) {
                if (temp[k] == '(') sum++;
                else sum--;
                min_s = min(sum, min_s);
            }
            sum = 0;
            for (int k = 0; k<n; k++) {
                if (temp[k] == '(') sum++;
                else sum--;
                if (sum == min_s) max_temp++; 
            }
            if (max_temp>max_cyc) {
                max_cyc = max_temp;
                max_i = i+1;
                max_j = j+1;
                // cout << temp << endl;
            }
        }
    }
    cout << max_cyc << endl;
    cout << max_i << " " << max_j << endl;
    return 0;
}