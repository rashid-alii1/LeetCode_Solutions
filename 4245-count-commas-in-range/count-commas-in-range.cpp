class Solution {
public:
    int countCommas(int n) {
    //     if(n<=999) return 0;
    //     else
    //     {
    //         return n-999;
    //     }
    // } this is also perfect but pro level is that 
        return max(0, n-999);  
    }
};