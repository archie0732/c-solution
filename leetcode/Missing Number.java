//Missing Number
//easy
//use HashMap
class Solution {
    public int missingNumber(int[] nums) {
        HashMap<Integer,Integer> map =  new HashMap<>();
        for(int it :nums){
            map.put(it,1);
        }
        int ans=0;
        for(int i=0 ;;i++){
            Integer a = map.get(i);
            if(a==null||a.equals(0)){
                return i;
            }
        }
    }
}
