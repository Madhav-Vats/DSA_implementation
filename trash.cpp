#include <bits/stdc++.h>
#include <numeric>

using namespace std;

// Function to calculate the product of digits of a number
int productOfDigits(const string& num) {
    return accumulate(num.begin(), num.end(), 1, [](int prod, char digit) {
        return prod * (digit - '0');
    });
}

// Function to calculate the sum of digits of a number
int sumOfDigits(const string& num) {
    return accumulate(num.begin(), num.end(), 0, [](int sum, char digit) {
        return sum + (digit - '0');
    });
}

int findValidInteger(int K) {
    string startNum(K, '1'); // Generates a string with K '1's
    int start = stoi(startNum); // Convert the starting string to an integer
    int end = pow(10, K) - 1; // 10^K - 1

    for (int N = start; N <= end; ++N) {
        string numStr = to_string(N);
        int prod_k = productOfDigits(numStr);
        int sum_k = sumOfDigits(numStr);

        if (prod_k >= sum_k) {
            return N;
        }
    }
    return -1; // Just in case no valid number is found
}

int main() {
    int K;
    cin >> K;
    if (1 <= K && K <= 100000) {
        cout << findValidInteger(K) << endl;
    } else {
        cout << "Not in Constraints" << endl;
    }
    return 0;
}


//
// vector<long long> solve(vector<int>&A)
// {
//   //using a queue
//   int n = A.size();
//   queue<pair<int,int>>q;
//
//   //first window
//   for(int i=0;i<k;i++)
//   {
//     if(A[i] <0)
//       q.push({A[i] , i});
//   }
//
//   vector<long long> ans;
//   if(q.size() == 0)
//     ans.push_back(0);
//   else
//   {
//     ans.push_back(q.front().first);
//   }
//
//   int WindowLeftInd = 0;
//
//   for(int i=k;i<n;i++)
//   {
//     //inserting the new negVal if it is
//     if(A[i]<0)
//     {
//       q.push({A[i] , i});
//     }
//     //deleting all those element which doesn't lie inside the currWindow
//     WindowLeftInd = i-k;
//     while(q.front().second < WindowLeftInd)
//     {
//       q.pop();
//     }
//
//     if(q.size() == 0)
//       ans.push_back(0);
//
//     else
//     {
//       ans.push_back(q.front().first);
//     }
//   }
//
//   return ans;
// }
//
// int main()
// {
//   vector<int>arr = {-8,2,3,-6,10};
//
//   vector<long long>ans = solve(arr);
//   for(auto it: ans)
//     cout<<it<<" ";
//
//   return 0;
//
// }
//
//
//
//
//
// class GPUAllocator {
// public:
//     GPUAllocator() : next_gpu_id(1), max_gpu_id(1000000) {
//         addGPUs(max_gpu_id);
//     }
//
//     void addProcess(int process_id) {
//         if (unallocated_gpus.empty()) {
//             addGPUs(100);
//         }
//         int allocated_gpu = unallocated_gpus.top();
//         unallocated_gpus.pop();
//         allocated_processes[process_id] = allocated_gpu;
//     }
//
//     void removeProcess(int process_id) {
//         if (allocated_processes.find(process_id) != allocated_processes.end()) {
//             int freed_gpu = allocated_processes[process_id];
//             unallocated_gpus.push(freed_gpu);
//             allocated_processes.erase(process_id);
//         }
//     }
//
//     int smallestUnallocated() {
//         if (unallocated_gpus.empty()) {
//             addGPUs(100);
//         }
//         return unallocated_gpus.empty() ? -1 : unallocated_gpus.top();
//     }
//
// private:
//     void addGPUs(int count) {
//         for (int i = 0; i < count; ++i) {
//             unallocated_gpus.push(next_gpu_id++);
//         }
//     }
//
//     priority_queue<int, vector<int>, greater<int>> unallocated_gpus;
//     unordered_map<int, int> allocated_processes;
//     int next_gpu_id;
//     const int max_gpu_id;
// };
