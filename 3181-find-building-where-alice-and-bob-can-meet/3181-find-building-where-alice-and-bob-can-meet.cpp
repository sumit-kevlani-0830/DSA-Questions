class SegmentTree{
    public:
        int n;
        vector<int>segmentTree;
        SegmentTree(vector<int>&nums){
            n = nums.size();
            segmentTree.resize(4*n);
        }
        void buildTree(int l,int r,vector<int>&nums,int i){
            if(l==r){
                segmentTree[i] = l;
                return;
            }
            int mid = l + (r-l)/2;
            buildTree(l,mid,nums,2*i+1);
            buildTree(mid+1,r,nums,2*i+2);
            int leftIdx = segmentTree[2*i+1];
            int rightIdx = segmentTree[2*i+2];
            if(nums[leftIdx]>=nums[rightIdx]){
                segmentTree[i] = leftIdx;
            }
            else{
                segmentTree[i] = rightIdx;
            }
        }
        int query(int l,int r,int start,int end,vector<int>&nums,int i){
            if(r<start || end<l){
                return -1;
            }
            if(start<=l && r<=end){
                return segmentTree[i];
            }
            int mid = l + (r-l)/2;
            int leftIdx = query(l,mid,start,end,nums,2*i+1);
            int rightIdx = query(mid+1,r,start,end,nums,2*i+2);
            if(leftIdx==-1){
                return rightIdx;
            }
            if(rightIdx==-1){
                return leftIdx;
            }
            if(nums[leftIdx]>=nums[rightIdx]){
                return leftIdx;
            }
            else{
                return rightIdx;
            }
        }
        int leftMostBuilding(vector<int>&nums,int idx1,int idx2){
            int left = max(idx1,idx2)+1;
            int right = n-1;
            int ans = -1;
            while(left<=right){
                int mid = left + (right-left)/2;
                int currIdx = query(0,n-1,left,mid,nums,0);
                if(nums[currIdx]>nums[idx1] && nums[currIdx]>nums[idx2]){
                    ans = currIdx;
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            return ans;
        }  
};
class Solution {
public:
    
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int len = queries.size();
        vector<int>ans(len);
        SegmentTree segTree(heights);
        segTree.buildTree(0,n-1,heights,0);
        for(int i = 0;i < len;i++){
            int a = queries[i][0];
            int b = queries[i][1];
            int heightFirstBuilding = heights[a];
            int heightSecondBuilding = heights[b];
            if(a==b){
                ans[i] = a;
            }
            else if(a<b && heightFirstBuilding<heightSecondBuilding){
                ans[i] = b;
            }
            else if(b<a && heightSecondBuilding<heightFirstBuilding){
                ans[i] = a;
            }
            else{
                ans[i] = segTree.leftMostBuilding(heights,a,b);
            }
        }
        return ans;
    }
};