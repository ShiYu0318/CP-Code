
// using namespace std;

// bool check(vector<int> arr, int k, int maxSum) {
//     int count = 1;
//     int currentSum = 0;
//     for (int num : arr) {
//         if (currentSum + num > maxSum) {
//             count++;
//             currentSum = num;
//         } else {
//             currentSum += num;
//         }
//         if (count > k) {
//             return false;
//         }
//     }
//     return true;
// }

// int maxsum(const vector<int>& arr, int k) {
//     int left = *max_element(arr.begin(), arr.end());
//     int right = 0;
//     for (int num : arr) {
//         right += num;
//     }
    
//     while (left < right) {
//         int mid = left + (right - left) / 2;
//         if (check(arr, k, mid)) {
//             right = mid;
//         } else {
//             left = mid + 1;
//         }
//     }
//     return left;
// }

// int main() {
//     int n, k;
//     cin >> n >> k;
    
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
    
//     int result = maxsum(arr, k);
//     cout << result << endl;
    
//     return 0;
// }