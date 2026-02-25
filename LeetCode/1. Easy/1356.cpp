class Solution {
    // 20260225
public:
    static int bit(int n)
    {
        int cnt = 0;
        while(n)
        {
            cnt += (n % 2);
            n >>= 1;
        }
        return cnt;
    }

    static bool cmp(int& a, int& b) 
    {
        int ba = bit(a), bb = bit(b);
        if(ba == bb) return a < b;
        return ba < bb;
    }

    vector<int> sortByBits(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

// class Solution {
// public:
//     static int bit(int n)
//     {
//         int cnt = 0;
//         while(n)
//         {
//             cnt += (n % 2);
//             n >>= 1;
//         }
//         return cnt;
//     }

//     static bool cmp(pair<int, int>& a, pair<int, int>& b) 
//     {
//         if(a.second == b.second) return a.first < b.first;
//         return a.second < b.second;
//     }

//     vector<int> sortByBits(vector<int>& arr) 
//     {
//         vector< pair<int, int> > vp;
//         for(int i=0; i < arr.size(); ++i) vp.emplace_back(arr[i], bit(arr[i]));
//         sort(vp.begin(), vp.end(), cmp);
//         for(int i=0; i < arr.size(); ++i) arr[i] = vp[i].first;
//         return arr;
//     }
// };