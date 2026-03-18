class Solution { // 20260311
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        int i;
        for(i=1; i<=n; i<<=1);
        return i-n-1;
    }
};