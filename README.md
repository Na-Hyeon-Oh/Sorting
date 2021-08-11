# Sorting Algorithm
✅ Algorithms_PA1

<br>

## Index
+ [Overview](#ov)
+ [Tools](#with)
+ [Prerequisites](#pre)
+ [Details](#details)

<br><br>

## Overview <a name = "ov"></a>

Implementation of an efficient sorting algorithm to cover diverse input items.


<br>

## Tools <a name = "with"></a>

<a href="https://github.com/search?q=user%3ADenverCoder1+is%3Arepo+language%3Ac"><img alt="C" src="https://img.shields.io/badge/C-2370ED.svg?logo=c&logoColor=white"></a>

✔️ Window 10

✔️ Visual Studio


<br>

## Prerequisites <a name = "pre"></a>

|Sorting Algorithms|Descripton|Performance(Complexity)|
|------|---|------|
|Merge Sort|main file|n|


<br>

## Details <a name = "details"></a>

### Description of Files

|File Name|Descripton|
|------|---|
|detectDeadlock.c|main file|
|Makefile|bash script|
|DeadlockDetection|execution file|
|input files|test cases in following [format](#inputF)|

### Compile and Execute

```
make
./DeadlockDetection input_file_name
```

### Algorithm

⚫ I referred to the original Merge sort to have fast performance and stable result in terms of time.

That is, I modified merge sort, and sort numbers which contains the “order” which is related to “string” objects by given key attribute (among attributes) which are the real sets to be sorted. 

Therefore, I do not sort real objects, but sort the “order number” by comparing each strings, and print them out in the order of “sorted order” to the output file.



<br>

![image](https://user-images.githubusercontent.com/64342804/129051769-2b3b8a7d-ff99-425f-928c-eb78a65bda4b.png)

![image](https://user-images.githubusercontent.com/64342804/129051834-45ad2e4b-9de3-4861-b829-a6ce6a7809df.png)

![image](https://user-images.githubusercontent.com/64342804/129051870-444296a5-b649-45bc-9042-5d3d85134104.png)



### Performance Analysis

1.	Input file read once(one cycle), linearly

-	If (the number of line) = n, (the number of attributes) = t, (the length of each attributes) = m, then print 1 byte for n*t*(m+1) + c times. c is a constant which is from reading 1st, 2nd part

-	I found that functions such as getline() has bigger internal time complexity than fread(), fwrite(). So that I use the latter functions

2.	Sorting

1)	OrderMergeSort()

-	My sorting algorithm is based on the merge sort, so that it has O(n log n) time complexity and it gives us stable result
-
-	Here, n = obj_num = (the number of objects)
-	
-	OrderMergeSort(key_objects[n], sorted_order[n], low, high, type)
-	
  a.	If n=1, done  -> O(1)
  
  b.	Recursively Sort A[1, … n/2(floor)] and A[n/2(ceil), …, n]  -> 2T(n/2)
  
  c.	Merge 2 sorted lists  -> O(n)
  
  ▶️ T(n) =
  
    (i)	O(1) if n=1
    
    (ii)	T(n/2(floor)) + T(n/2(ceil)) + O(n) = 2T(n/2) + O(n) if n>1
 
      ➡️ h = lgn, (the number of leaves) = n by recursion tree
      
      ➡️ Θ(n lg n)
      
2)	NewMerge()

-	For comparing strings in the key_objects[], I use previously defined function ‘strcmp’ (for case sensitivity) in <string.h>. These functions may impact on code performance with their internal complexity

3.	Print output with no search(just load from the memory) using predefined 2D array objects; print by byte for 1 cycle

-	If (the number of line) = n, (the number of attributes) = t, (the length of each attributes) = m, then print 1 byte for n*t*(m+1) times

4.	Optimization

-	I use more memory for memorization to reduce time complexity, so that not repeatedly read the input file and so on; I try not to use too much memory by using dynamic allocation for optimized amount.

-	I try to use predefined functions in library which have less internal time complexity (ex) fread, fwrite, switch…).


#### EX

⚫ If n=1144 -> ~=182ms

⚫ If n ~= 7500000 -> ~=598000ms





### Input Format <a name="inputF"></a>
  
  ```
  N M t1 t2 ... tm
  Anm
      ...
  Rnm
      ...
  ```
  
  - N : process #
  - M : resource type # 
  - t : resource unit # for each resource type
  - Anm : allocation matrix for processes
  - Rnm : allocation matrix for processes
  
### Output Format
 
 1. If No Deadlock
  ```
<INPUT>
...

<STACK Trace>
...

---------------------------------------------------------------------------

<RESULT>
Is there Deadlock? NO

  ```

2. If Deadlock occurs
```
<INPUT>
...

<STACK Trace>
...

---------------------------------------------------------------------------

<RESULT>
Is there Deadlock? Yes  // Blocked Processes { (pids) }

  ```
