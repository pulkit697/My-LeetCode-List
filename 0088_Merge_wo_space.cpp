// https://leetcode.com/problems/merge-sorted-array/
// Time O(nlogn)
// Space O(1)
class Solution {
    void swapper(vector<int>&a,int m,vector<int>&b,int n,int k)
    {
        int i=0;
        int j=i+k;
        while(j<m+n)
        {
            if(i>=m)
            {
                if(b[i-m]>b[j-m])
                    swap(b[i-m],b[j-m]);
            }
            else
            {
                if(j>=m)
                {
                    if(a[i]>b[j-m])
                        swap(a[i],b[j-m]);
                }
                else
                {
                    if(a[i]>a[j])
                        swap(a[i],a[j]);
                }
            }
            i++;
            j++;
        }
    }
    int next(int k)
    {
        if(k<=1)    return 0;
        return (k+1)/2;
    }
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i = m-1;
        int j = n-1;
        for(int k = min(m,(m+n)/2);k>0;k=next(k))
            swapper(a,m,b,n,k);
        for(int i=0;i<n;i++)
        {
            a[i+m]=b[i];
        }
    }
};