#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Driver Code Ends

const int minRUN = 32;

// Calculate minimum run length (kept small here for demo)
int calcMinRun(int n) {
    int r = 0;
    while (n >= minRUN) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

// Insertion sort for small ranges
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge two sorted subarrays [l..m] and [m+1..r]
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

// Detect ascending/descending run starting at index "start"
int findRun(vector<int>& arr, int start, int n) {
    int end = start + 1;
    if (end == n) return end;

    if (arr[end] < arr[start]) {
        // descending
        while (end < n && arr[end] < arr[end - 1]) end++;
        reverse(arr.begin() + start, arr.begin() + end);
    } else {
        // ascending
        while (end < n && arr[end] >= arr[end - 1]) end++;
    }
    return end;
}

// Timsort main function
void timsort(vector<int>& arr) {
    int n = arr.size();
    int minRun = calcMinRun(n);
    vector<pair<int,int>> runs;

    int i = 0;
    while (i < n) {
        int runEnd = findRun(arr, i, n);
        int runLen = runEnd - i;

        if (runLen < minRun) {
            int end = min(i + minRun, n);
            insertionSort(arr, i, end - 1);
            runEnd = end;
        }
        runs.push_back({i, runEnd});
        i = runEnd;

        while (runs.size() > 1) {
            int l1 = runs[runs.size() - 2].first;
            int r1 = runs[runs.size() - 2].second;
            int l2 = runs[runs.size() - 1].first;
            int r2 = runs[runs.size() - 1].second;

            int len1 = r1 - l1;
            int len2 = r2 - l2;
            if (len1 <= len2) {
                merge(arr, l1, r1 - 1, r2 - 1);
                runs.pop_back();
                runs[runs.size() - 1] = {l1, r2};
            } else break;
        }
    }

    while (runs.size() > 1) {
        int l1 = runs[runs.size() - 2].first;
        int r1 = runs[runs.size() - 2].second;
        int l2 = runs[runs.size() - 1].first;
        int r2 = runs[runs.size() - 1].second;
        merge(arr, l1, r1 - 1, r2 - 1);
        runs.pop_back();
        runs[runs.size() - 1] = {l1, r2};
    }
}

//Driver Code Starts
int main() {
    vector<int> arr = {5, 21, 7, 23, 19, 10, 1, 3, 2};
    timsort(arr);
    for (int x : arr) cout << x << " ";
    cout << endl;
}
