class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]={0};
        int maxi=0;
        int size=tasks.size();
        for(auto i:tasks)
        {
            int f=++freq[i-'A'];
            maxi=max(maxi,f);
        }
        int num=count(freq,freq+26,maxi);
        int ans=(maxi-1)*(n+1)+num;
         return max(ans,size);
    }
};