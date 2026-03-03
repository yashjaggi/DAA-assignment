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

        long long K;
        cin >> K;

        sort(arr.begin(), arr.end());

        int i = 0, j = 1;
        long long count = 0;

        while (j < n) {
            if (i == j) {
                j++;
                continue;
            }

            long long diff = arr[j] - arr[i];

            if (diff == K) {
                count++;
                i++;
                j++;
            }
            else if (diff < K) {
                j++;
            }
            else {
                i++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
