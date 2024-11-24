class Solution {
public:
    void merge(vector<int>&nums,int n,int low,int mid,int high){
        int n1 = mid-low+1;
        int n2 = high-mid;
        vector<int>a(n1);
        vector<int>b(n2);
        for(int i = low;i <= mid;i++){
            a[i-low] = nums[i];
        }
        for(int i = mid+1;i <= high;i++){
            b[i-mid-1] = nums[i];
        }
        int i = 0;
        int j = 0;
        int k = low;
        while(i<n1 && j<n2){
            if(a[i]>b[j]){
                nums[k] = b[j];
                j++;k++;
            }
            else{
                nums[k] = a[i];
                i++;k++;
            }
        }
        while(i<n1){
            nums[k] = a[i];
            i++;k++;
        }
        while(j<n2){
            nums[k] = b[j];
            j++;k++;
        }
    }
    void merge_sort(vector<int>&nums,int n,int low,int high){
        if(low>=high){
            return;
        }
        int mid = low + (high-low)/2;
        merge_sort(nums,n,low,mid);
        merge_sort(nums,n,mid+1,high);
        merge(nums,n,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        merge_sort(nums,n,low,high);
        return nums;
    }
};