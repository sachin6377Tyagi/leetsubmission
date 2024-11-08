class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        String symb="!?',;.";
        for(int i=0;i<symb.length();++i){
            char temp=symb.charAt(i);
            paragraph=paragraph.replace(temp,' ');
        }
       String[] words=paragraph.split(" "); 
       HashMap<String,Integer>mp=new HashMap<>();
       HashMap<String,Integer>b=new HashMap<>();
       for(String s:banned){
        s=s.toLowerCase();
        b.put(s,1);
       }
       int maxi=0;
       String ans="";
       for(String s:words){
        s=s.toLowerCase();
        if(b.containsKey(s) || s.length()==0)continue;
        if(mp.containsKey(s)){
            int val=mp.get(s);
            mp.put(s,val+1);
        }
        else mp.put(s,1);
       }
       for(String key:mp.keySet()){
        int val=mp.get(key);
        if(val>maxi){
            maxi=val;
            ans=key;
        }
       }
       System.out.println(mp);
       return ans;
    }
}