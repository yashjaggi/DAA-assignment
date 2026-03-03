#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end());

        bool duplicate = false;

        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                duplicate = true;
                break;
            }
        }

        if (duplicate)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
