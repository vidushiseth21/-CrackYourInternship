/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int>ans;
        int total=0;
        int pro=0;
        int deadline=INT_MIN;
        for(int i=0;i<n;i++)
        {
            deadline=max(deadline,arr[i].dead);
        }
        vector<int>schedule(deadline+1,-1);
        sort(arr,arr+n,[](const Job &arr1,const Job &arr2)
        {
            return arr1.profit>arr2.profit;
        });
        for(int i=0;i<n;i++)
        {
            int currdead=arr[i].dead;
            for(int j=currdead;j>0;j--)
            {
                if(schedule[j]==-1)
                {
                    pro+=arr[i].profit;
                    total++;
                    schedule[j]=arr[i].dead;
                    break;
                }
            }
            
        }
        ans.push_back(total);
        ans.push_back(pro);
        return ans;
        
    } 
};