class NumArray {
public:
    int n;
    vector<int>segmentTree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segmentTree.resize(4*n);
        buildSegmentTree(nums,0,n-1,0);
    }
    void buildSegmentTree(vector<int>&nums, int l, int r, int i){
        if(l==r){
            segmentTree[i] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildSegmentTree(nums,l,mid,2*i+1);
        buildSegmentTree(nums,mid+1,r,2*i+2);
        segmentTree[i] = segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    void updateQuery(int index, int val, int l, int r, int i){
        if(l==r){
            segmentTree[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(l<=index && index<=mid){
            updateQuery(index, val, l, mid, 2*i+1);
        }
        else{
            updateQuery(index, val, mid+1, r, 2*i+2);
        }
        segmentTree[i] = segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    void update(int index, int val) {
        updateQuery(index, val, 0, n-1, 0);
    }
    int rangeSumQuery(int start, int end, int l, int r, int i){
        if(start>r || end<l){
            return 0;
        }
        if(start<=l && r<=end){
            return segmentTree[i];
        }
        int mid = l + (r-l)/2;
        return rangeSumQuery(start,end,l,mid,2*i+1)+rangeSumQuery(start,end,mid+1,r,2*i+2);
    }
    int sumRange(int left, int right) {
        int ans = rangeSumQuery(left,right,0,n-1,0);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */