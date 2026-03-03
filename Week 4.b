#include <bits/stdc++.h>
using namespace std;

long long comparisons = 0;
long long swapsCount = 0;

int partitionArray(vector<long long> &arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    swapsCount++;

    long long pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swapsCount++;
        }
    }

    swap(arr[i + 1], arr[high]);
    swapsCount++;

    return i + 1;
}

void quickSort(vector<long long> &arr, int low, int high) {
    if (low < high) {
        int pi = partitionArray(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        comparisons = 0;
        swapsCount = 0;

        quickSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swapsCount << endl;
    }

    return 0;
}
