class Solution {
public:
    bool checkDivisibility(int n) {

        int orignal=n;
        int sum=0;
        int product=1;
        while (n>0)
        {
            int digit=n%10;
            sum+=digit;
            product*=digit;
            n/=10;
        }
        if(orignal%(sum+product)==0) return true;
        else return false;
    }
};