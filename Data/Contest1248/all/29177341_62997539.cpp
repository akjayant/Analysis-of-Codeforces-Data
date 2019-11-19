#include <bits/stdc++.h>
using namespace std;

int beauty_of_string(string s) {
    int min_value = 0;
    int min_multiplicity = 0;
    int actual_value = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            actual_value++;
        } else {
            actual_value--;
        }
        if (actual_value < min_value) {
            min_value = actual_value;
            min_multiplicity = 1;
        } else if (actual_value == min_value) {
            min_multiplicity++;
        }
    }
    return min_multiplicity;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int num_left = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            num_left++;
        }
    }
    if ((n % 2 != 0) || (num_left != n / 2)) {
        cout << "0\n1 1\n";
        return 0;
    }
    int best_i = -1, best_j = -1, best_beauty = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            int beauty = beauty_of_string(s);
            if (beauty > best_beauty) {
                best_beauty = beauty;
                best_i = i;
                best_j = j;
            }
            s[j] = s[i];
            s[i] = temp;
        }
    }
    cout << best_beauty << '\n' << (best_i + 1) << ' ' << (best_j + 1) << '\n';
    return 0;
}
