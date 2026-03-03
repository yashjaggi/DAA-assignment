#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high, int pivot) {
    int pivotIndex;
    for (int i = low; i <= high; i++) {
        if (arr[i] == pivot) {
            pivotIndex = i;
            break;
        }
    }

    swap(arr[pivotIndex], arr[high]);
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

int kthSmallest(vector<int> &arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {

        int n = high - low + 1;

        int i;
        vector<int> median((n + 4) / 5);

        for (i = 0; i < n / 5; i++) {
            sort(arr.begin() + low + i * 5, arr.begin() + low + i * 5 + 5);
            median[i] = arr[low + i * 5 + 2];
        }

        if (i * 5 < n) {
            sort(arr.begin() + low + i * 5, arr.begin() + low + i * 5 + n % 5);
            median[i] = arr[low + i * 5 + (n % 5) / 2];
            i++;
        }

        int medOfMed;
        if (i == 1)
            medOfMed = median[0];
        else
            medOfMed = kthSmallest(median, 0, i - 1, i / 2);

        int pos = partition(arr, low, high, medOfMed);

        if (pos - low == k - 1)
            return arr[pos];

        if (pos - low > k - 1)
            return kthSmallest(arr, low, pos - 1, k);

        return kthSmallest(arr, pos + 1, high, k - pos + low - 1);
    }

    return INT_MAX;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int k;
        cin >> k;

        if (k > n || k <= 0) {
            cout << "not present" << endl;
        } else {
            int result = kthSmallest(arr, 0, n - 1, k);
            if (result == INT_MAX)
                cout << "not present" << endl;
            else
                cout << result << endl;
        }
    }

    return 0;
}
