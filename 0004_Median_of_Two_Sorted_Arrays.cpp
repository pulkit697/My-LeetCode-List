// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Time O(log(n+m))
// Space O(1)
#define vi vector<int>
class Solution {
public:
    int fun(vi& a,vi& b,int k)
    {
        int start = 0;
        int end = a.size()-1;
        while(start<=end)
        {
            int mid = (end+start)/2;
            int c = lower_bound(b.begin(),b.end(),a[mid]) - b.begin();
            int c2 = upper_bound(b.begin(),b.end(),a[mid]) - b.begin();
            int idx = mid + c;
            int idx2 = mid + c2;
            if(k>=idx && k<=idx2){
                return a[mid];
            }
            else if(idx<k){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int t = n+m;
        if(t%2!=0){
            double x = (double)fun(a,b,t/2);
            if(x == -1) return (double)fun(b,a,t/2);
            return x;
        }
        // cout<<t<<"  ***  ";
        double x = fun(a,b,(t-1)/2);
        double y = fun(a,b,t/2);
        // cout<<x<<" "<<y<<"    ";
        if(x == -1){
            x = fun(b,a,(t-1)/2);
        }
        if(y==-1){
            y = fun(b,a,t/2);
            // cout<<x<<" "<<y;
        }
        // cout<<'\n';
        return (x+y)/2.0;
    }
};