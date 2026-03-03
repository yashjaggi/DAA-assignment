#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;

    vector<int> A(m);
    for (int i = 0; i < m; i++)
        cin >> A[i];

    int n;
    cin >> n;

    vector<int> B(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];

    int i = 0, j = 0;
    bool found = false;

    while (i < m && j < n) {
        if (A[i] == B[j]) {
            cout << A[i] << " ";
            i++;
            j++;
            found = true;
        }
        else if (A[i] < B[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    if (!found)
        cout << "No Common Elements";

    return 0;
}
