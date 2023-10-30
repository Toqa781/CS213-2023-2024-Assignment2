#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n-1];
    for (int i = 0; i < n-1 ; i++) {
        arr[i] = i + 2;
    }
    for (int i = 0; i < n-1; i++) {
            if (arr[i] != 0) {
                for (int j = i + 1; j < n-(i+1); j++) {
                    if (arr[j] % arr[i] == 0) {
                        arr[j] = 0;
                    }
                }
            }
    }
    for (int i = 0; i < n-1; i++) {
        if (arr[i] != 0) {
            cout << arr[i] << ' ';
        }
    }

    return 0;
}
