class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        for(auto i:s)
         m[i]++;
        priority_queue<pair<int,char>>pq;
        for(auto i:m)
        {
            pq.push(make_pair(i.second,i.first));
        }
        string ans;
        while(!pq.empty())
        {
            auto a=pq.top();
            pq.pop();
            if(ans.empty() || a.second!=ans.back())
            {
                ans+=a.second;
                if(--a.first>0)
                    pq.push(a);
            }
            else
            {
                if(pq.empty())
                 return "";
                auto b=pq.top();
                pq.pop();
                ans+=b.second;
                if(--b.first>0)
                 pq.push(b);
                pq.push(a);
            }
        }
        return ans;
    }
};