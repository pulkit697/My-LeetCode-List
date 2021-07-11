// https://leetcode.com/problems/merge-sorted-array/
// Time O(nlogn)
// Space O(1)
// Way 1 => swap in size of k
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

// Way 2 => arr1 ke sabhi wo bade arr2 mi daal do jo arr2 ke minimum element se bade hai
class Solution{
    public:
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i = n-1;
            int j = 0;
            while(i>=0 && j<m && arr1[i]>arr2[j]){
                swap(arr1[i--],arr2[j++]);
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};