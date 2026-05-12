#include <iostream>
#include <vector>
using namespace std;
 
void shellSort(vector<int>& arr)
{
    int n = arr.size();

    // Start with a large gap, then reduce it step by step
    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {

        // Perform a "gapped" insertion sort for this gap size
        for (int i = gap; i < n; i++)
        {
            
            // Current element to be placed correctly
            int temp = arr[i];  
            int j = i;

            // Shift elements that are greater than temp to make space
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j = j - gap;
            }

            // Place temp in its correct location
            arr[j] = temp;
        }
    }
}

// Utility function to print the vector
void printArray(const vector<int>& arr)
{
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {12, 34, 54, 2, 3}; 

    shellSort(arr);
    printArray(arr);

    return 0;
}