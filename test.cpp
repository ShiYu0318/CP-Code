#include <bits/stdc++.h>
using namespace std;




int main()
{
    // int arr[10][10];
    // vector<型別> 名稱(a,b);
    // a : 大小
    // b : 每個元素 是什麼

    // 1. 有給大小
    // int n; cin >> n;
    // vector<int> arr(n);
    // for(int i=0; i<n; i++) cin >> arr[i];


    // 2. 沒給大小 EOF
    vector<int> arr;
    int n;
    while(cin >> n) arr.push_back(n);
    cout << arr.size() << "\n";
    for(int i=0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << "\n";
    arr.pop_back();
    cout << arr.size() << "\n";
    for(int i=0; i < arr.size(); ++i) cout << arr[i] << " ";





















    // arr.push_back(15);
    // cout << arr.size() << "\n";

    // arr.push_back(10);
    // cout << arr.size() << "\n";

    // arr.push_back(5);
    // cout << arr.size() << "\n\n";


    // // sort(arr, arr + n); // 陣列排序
    // sort(arr.begin(), arr.end()); // vector 排序
    
    // for(int i=0; i < arr.size(); ++i) cout << arr[i] << " ";
    // for(int i:arr) cout << i << " ";




    // cout << arr[0] << "\n";
    // cout << arr.front() << "\n\n";
    // cout << *arr.begin() << "\n";
    
    
    // cout << arr[arr.size()-1] << "\n";
    // cout << arr.back() << "\n";
    // cout << *(arr.end()-1) << "\n";




    // arr.pop_back();
    // cout << arr.size() << "\n";
    // // 5,10











    // cout << arr[1] + 1 << "\n";
    // arr[0] = 4;
    // cout << arr[0] << "\n";




    // vector< vector<int> > brr(4, vector<int>(5,0));
    //  , , , , 
    //  , , , ,  
    //  , , , , 
    //  , , , , 
    

    







    
    
    
    
    // 0 0 0 0 2 6 8 5 3 2 5
    // 0 0 0 0 1 3 4
    // 0 0 0 0 2 5 8 9
    // 0 0 0 0 1 5 7 9 2 4

    
}