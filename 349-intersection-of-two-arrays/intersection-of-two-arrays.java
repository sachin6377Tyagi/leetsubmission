class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        ArrayList<Integer>vec=new ArrayList<>();
        HashMap<Integer,Integer>mp=new HashMap<>();
        HashMap<Integer,Integer>mp1=new HashMap<>();
        for(int i=0;i<nums1.length;++i){
            if(mp.containsKey(nums1[i])){
                int val=mp.get(nums1[i]);
                mp.put(nums1[i],val+1);
            }
            else mp.put(nums1[i],1);
        }
        for(int i=0;i<nums2.length;++i){
            if(mp.containsKey(nums2[i]))mp1.put(nums2[i],1);
        }
        for(int key:mp1.keySet())vec.add(key);
        int l=vec.size();
        int[] ans=new int[l];
        for(int i=0;i<vec.size();++i)ans[i]=vec.get(i);
        return ans;
    }
}

// import Java.io.*.;