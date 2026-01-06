class Solution {    
// 20260103 0ms O(n)
// 將 n = 1 時所有情況分成兩大類
// A. 左右同顏色數量：6
// B. 三種不同顏色數量：6
// 轉移到 n + 1 時
// 1. A 會分裂成 3 個 A 和 2 個 B
// 2. B 會分裂成 2 個 A 和 2 個 B
public:
    int numOfWays(int n) {
        const int M = 1e9+7;
        long long A = 6, B = 6;
        for(int i=1; i<n; ++i)
        {
            long long AA = 3 * A %M + 2 * B %M;
            long long BB = 2 * A %M + 2 * B %M;
            A = AA; B = BB;
        }
        return (A + B) %M;
    }
};