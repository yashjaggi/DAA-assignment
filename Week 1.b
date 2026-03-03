#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    int comparisons = 0;
    bool found = false;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;  // comparing arr[mid] with key

        if(arr[mid] == key) {
            found = true;
            break;
        }
        else if(key < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if(found)
        cout << "Present\n";
    else
        cout << "Not Present\n";

    cout << "Total Comparisons: " << comparisons << endl;

    return 0;
}
