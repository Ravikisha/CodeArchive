class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size(), size2=nums2.size();
        int size=size1+size2;
        int i=0, j=0, k=0;
        int *nums=new int[size];
        while(i<size1 && j<size2){
            if(nums1[i]<nums2[j]){
                nums[k++]=nums1[i++];
            }else{
                nums[k++]=nums2[j++];
            }
        }
        while(i<size1){
            nums[k++]=nums1[i++];
        }
        while(j<size2){
            nums[k++]=nums2[j++];
        }
        double res;
        if(size%2==0){
            res=(nums[size/2]+nums[size/2-1])/2.0;
        }else{
            res=nums[size/2];
        }
        delete []nums;
        return res;
    }
};