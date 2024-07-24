#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int size = arr.size();
    vector<int> closest;

    // Iterate through the array and find the closest elements to x
    for (int i = 0; i < size; ++i) {
        closest.push_back(arr[i]);
    }

    sort(closest.begin(), closest.end(), [x](int a, int b) {
        return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b);
    });

    // Resize the result to contain only the k closest elements
    closest.resize(k);

    // Sort the result in ascending order
    sort(closest.begin(), closest.end());

    return closest;
}
