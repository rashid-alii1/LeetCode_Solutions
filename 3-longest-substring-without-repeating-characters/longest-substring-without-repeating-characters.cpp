class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int left=0;
        int maxlen=0;
        int n=s.size();
        for(int right=0;right<n;right++)
        {
            // freq[s[right]]++;
            // while(freq[s[right]]>1)
            // {
            //     freq[s[left]]--;
            //     if(freq[s[left]]==0)
            //     {
            //         freq.erase(s[left]);
            //     }
            //     left++;
            // }
            if(freq.count(s[right]))
            {
                left=max(left,freq[s[right]]+1);
            }
            freq[s[right]]=right;
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};