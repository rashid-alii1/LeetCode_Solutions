class Solution {
public:
    
    int product(int num)
    {
        int productt=1;
        while(num>0)
        {
            int digit=num%10;
            productt*=digit;
            num/=10;
        }
        return productt;
    }
    int smallestNumber(int n, int t) 
    {
        //bool status = true;
        while(true)
        {
            int producttt = product(n);
            if(producttt%t==0)
            {
                //status=false;
                return n;
            }
            else
            {
                //productt=1;
                n++;
            }
        }
        //return n;
    }
    
};