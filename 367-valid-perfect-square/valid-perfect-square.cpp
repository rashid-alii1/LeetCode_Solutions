class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num == 0 || num==1)
            return true;

        long long r = num;

        while(r * r > num)
        {
            r = (r + num / r) / 2;
        }
        if(r*r==num) return true;
        else return false;    
    }
};