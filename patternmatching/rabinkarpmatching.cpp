#include<iostream>
#include <vector>
using namespace std;

// Function to search for all occurrences of 'pat' in 'txt' using Rabin-Karp
vector<int> search(const string &pat, const string &txt)
{

    // Number of characters in the input alphabet (ASCII)
    int d = 256;

    // A prime number for modulo operations to reduce collisions
    int q = 101;

    // Length of the pattern
    int m = pat.length();

    // Length of the text
    int n = txt.length();

    // Hash value for pattern
    int p = 0;

    // Hash value for current window of text
    int t = 0;

    // High-order digit multiplier
    int h = 1;

    vector<int> ans;

    // Precompute h = pow(d, M-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Compute initial hash values for
    // pattern and first window of text
    for (int i = 0; i < m; i++)
    {

        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++)
    {

        // If hash values match, check characters one by one
        if (p == t)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {

                if (txt[i + j] != pat[j])
                {

                    match = false;
                    break;
                }
            }
            if (match)
                ans.push_back(i);
        }

        // Calculate hash value for the next window
        if (i < n - m)
        {

            t = (d * (t - txt[i] * h) + txt[i + m]) % q;

            // Ensure hash value is non-negative
            if (t < 0)
                t += q;
        }
    }
    return ans;
}

int main()
{

    string txt = "Abhiram";
    string pat = "ram";
    vector<int> res = search(pat, txt);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}
