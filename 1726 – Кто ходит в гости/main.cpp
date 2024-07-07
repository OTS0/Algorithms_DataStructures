#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

unsigned long long sum = 0;
int temp;
int main() {
    unsigned long long n;

    cin >> n;
    vector<unsigned long long>arr_x(n);
    vector<unsigned long long>arr_y(n);
    for (int i = 0; i < n; i=i+1) {
        cin >> arr_x[i];
        cin >> arr_y[i];
    }
    std::sort(arr_x.begin(), arr_x.end());
    std::sort(arr_y.begin(), arr_y.end());
    for (unsigned long long i = 1; i < n; i++) {
        sum += 2 * ((arr_x[i] - arr_x[i-1]) + (arr_y[i] - arr_y[i-1])) * i * (n - i);
    }
    cout << sum/(n*(n-1));
    return 0;}







