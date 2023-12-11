# Theofanis' Nightmare
[題目連結](https://codeforces.com/contest/1903/problem/C)
### 題目
Theofanis easily gets obsessed with problems before going to sleep and often has nightmares about them. To deal with his obsession he visited his doctor, Dr. Emix.

In his latest nightmare, he has an array a
 of size n
 and wants to divide it into non-empty subarrays†
 such that every element is in exactly one of the subarrays.

For example, the array [1,−3,7,−6,2,5]
 can be divided to [1][−3,7][−6,2][5]
.

The Cypriot value of such division is equal to     
$`{\textstyle \sum_{i=1}^{k}}`$   
.sumi
 where k
 is the number of subarrays that we divided the array into and sumi
 is the sum of the i
-th subarray.

The Cypriot value of this division of the array [1][−3,7][−6,2][5]=1⋅1+2⋅(−3+7)+3⋅(−6+2)+4⋅5=17
.

Theofanis is wondering what is the maximum Cypriot value of any division of the array.

†
 An array b
 is a subarray of an array a
 if b
 can be obtained from a
 by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end. In particular, an array is a subarray of itself.



 **input**  

The first line contains a single integer t
 (1≤t≤$`10^4`$
) — the number of test cases.

Each test case consists of two lines.

The first line of each test case contains a single integer n
 (1≤n≤$`10^5`$
) — the size of the array.

The second line contains n
 integers $`a_1,a_2,…,a_n`$
 ($`−10^8≤a_i≤10^8 `$
) — the elements of the array.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅$`10^5`$
.

**output**  


For each test case, print one integer — the maximum Cypriot value of the array a
.  
