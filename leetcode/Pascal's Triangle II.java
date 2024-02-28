//Pascal's Triangle II
// Easy
class Solution {
    public List<Integer> getRow(int rowIndex) {
        //create a dp array 
        List<List<Integer>> triagle = new ArrayList<List<Integer>>();
        // for index 1(or 0)
        triagle.add(new ArrayList<Integer>());
        triagle.get(0).add(1);
        
        // for index 1 to rowIndex 
        for(int r = 1;r <= rowIndex;r++){
            List<Integer> currow = new ArrayList<Integer>();
            List<Integer> prerow = triagle.get(r - 1);

            //add list first index 
            currow.add(1);
            // midle index
            for(int i = 1;i < r;i++){
                currow.add(prerow.get(i)+prerow.get(i-1));
            }

            //add list last index
            currow.add(1);

            // return the list is row which promble ask
            if(rowIndex==r) return currow;
            triagle.add(currow);
        }
        // if rowIndex is 0
        List<Integer> ans = new ArrayList<Integer>();
        ans.add(1);
       return ans;
    }
}
