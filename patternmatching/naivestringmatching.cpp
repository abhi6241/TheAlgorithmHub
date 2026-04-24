#include<iostream>
#include <vector>
using namespace std;

// Function to search for all occurrences of 'pat' in 'txt' using Naive Approach
vector<int> search(const string &pat, const string &txt)
{
    // Length of the pattern
    int m = pat.length();

    // Length of the text
    int n = txt.length();

    vector<int> ans;

    // Slide the pattern over text one by one
    for (int i = 0; i <= n - m; i++)
    {
        int j;

        // Check for pattern match at index i
        for (j = 0; j < m; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }

        // If pattern matches, store index
        if (j == m)
            ans.push_back(i);
    }

    return ans;
}

int main()
{
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = search(pat, txt);

    for (auto it : res)
    {
        cout << it << " ";
    }

    return 0;
}