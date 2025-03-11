#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr = {5, 2, 8, 1, 9};

    sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b; // Sort in descending order
    });

    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
