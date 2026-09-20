class Solution {
public:
    int reverseDegree(string s) {
        int sizee=s.size();
        int sum=0;
        for(int i=0;i<sizee;i++)
        {
            int reverse=('z'-s[i])+1;
            sum+=reverse*(i+1);
        }
        return sum;
    }
};