class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        int[] ans=new int[2];
        for(int i=0;i<nums.length;++i){
            int num=target-nums[i];
            if(mp.containsKey(num)){
                int j=mp.get(num);
                ans[0]=j;
                ans[1]=i;
                break;
            }
            mp.put(nums[i],i);
        }
        return ans;
    }
}