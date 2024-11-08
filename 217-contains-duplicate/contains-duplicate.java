class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<nums.length;++i){
            if(mp.containsKey(nums[i])){
                int val=mp.get(nums[i]);
                mp.put(nums[i],val+1);
            }
            else{
                mp.put(nums[i],1);
            }
        }
        int maxi=0;
        for(int key:mp.keySet()){
            int val=mp.get(key);
            maxi=Math.max(val,maxi);
        }
        if(maxi<=1)return false;
        return true;
    }
}