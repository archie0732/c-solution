# Merge k Sorted Lists
[題目連結](https://leetcode.com/problems/merge-k-sorted-lists/description/)
## 題目
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.  

Merge all the linked-lists into one sorted linked-list and return it.

#### sample 
**Example 1:**

Input:  
lists = [`1,4,5`,`1,3,4`,`2,6`]  
Output:   
```
1,1,2,3,4,4,5,6
```
`Explanation`:  
The linked-lists are: 
```md 
  1->4->5,  
  1->3->4,  
  2->6  
```
merging them into one sorted list:  
```1->1->2->3->4->4->5->6  ```  

### code 
```java
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        return mergeKListsHelper(lists, 0, lists.length - 1);
    }
    
    private ListNode mergeKListsHelper(ListNode[] lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start + 1 == end) {
            return merge(lists[start], lists[end]);
        }
        int mid = start + (end - start) / 2;
        ListNode left = mergeKListsHelper(lists, start, mid);
        ListNode right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
    }
    
    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                curr.next = l1;
                l1 = l1.next;
            } else {
                curr.next = l2;
                l2 = l2.next;
            }
            curr = curr.next;
        }
        
        curr.next = (l1 != null) ? l1 : l2;
        
        return dummy.next;
    }
}
```
![](https://github.com/archie0732/c-solution/blob/main/picture/pekora.jpg)
