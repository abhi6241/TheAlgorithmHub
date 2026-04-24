#include <iostream>
#include <vector>
using namespace std;

// Z-function to compute Z-array
vector<int> zFunction(string &s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (i <= r) {
            int k = i - l;
            
            // Case 2: reuse the previously computed value
            z[i] = min(r - i + 1, z[k]);
        }

        // Try to extend the Z-box beyond r
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        // Update the [l, r] window if extended
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}


// Function to find all occurrences of pattern in text
vector<int> search(string &text, string &pattern) {
    string s = pattern + '$' + text;
    vector<int> z = zFunction(s);
    vector<int> pos;
    int m = pattern.size();

    for (int i = m + 1; i < z.size(); i++) {
        if (z[i] == m){
            // pattern match starts here in text
            pos.push_back(i - m - 1); 
        }
    }
    return pos;
}

int main() {
    string text = "aabxaabxaa";
    string pattern = "aab";

    vector<int> matches = search(text, pattern);

    for (int pos : matches)
        cout << pos << " ";

    return 0;
}