class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left=0;
        int maxlen=0;
        int n=fruits.size();
        for(int right=0;right<n;right++)
        {
            basket[fruits[right]]++;
            while(basket.size()>2)
            {
                basket[fruits[left]]--;
                if(basket[fruits[left]]==0)
                {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;     
    }
};
