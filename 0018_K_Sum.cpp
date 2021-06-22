// https://leetcode.com/problems/4sum/
// Time O(k*n)
// Space O(1)

// Same as Above question, just general k in place of 4

class Solution {
    vector<vector<int>> twoSum(vector<int>& arr,int j,int n,int tar)
    {
        vector<vector<int>> v;
        int p = j;
        int q = n-1;
        while(p<q)
        {
            int sum = arr[p] + arr[q];
            if(sum == tar)
            {
                v.push_back({arr[p],arr[q]});
                while(p<q && arr[p+1] == arr[p])
                    p++;
                while(p<q && arr[q]==arr[q-1])
                    q--;
                p++;
                q--;
            }
            else if(sum<tar)
                p++;
            else
                q--;
        }
        // cout<<j<<" "<<tar<<"  "<<v.size()<<'\n';
        return v;
    }
    vector<vector<int>> KSum(vector<int>& arr,int j,int n,int tar,int k)
    {
        if(k == 2)
            return twoSum(arr,j,n,tar);
        vector<vector<int>> ans;
        for(int i=j;i<n;i++)
        {
            if(i>j && arr[i]==arr[i-1])
                continue;
            vector<vector<int>> temp = KSum(arr,i+1,n,tar-arr[i],k-1);
            for(auto it:temp)
            {
                vector<int> v;
                // cout<<it.size()<<"\n";
                v.push_back(arr[i]);
                for(auto it2:it){
                    v.push_back(it2);
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> fourSum(vector<int>& arr, int tar) {
        sort(arr.begin(),arr.end());
        return KSum(arr,0,arr.size(),tar,4);
    }
};