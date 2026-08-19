class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int left=0;
        int maxlen=0;
        for(int right=0;right<s.size();right++)
        {
            freq[s[right]]++;
            while(freq[s[right]]>1)
            {
                freq[s[left]]--;
                if(freq[s[left]]==0)
                {
                    freq.erase(s[left]);
                }
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};