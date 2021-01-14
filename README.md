# Sorting
### [Algorithms] Merge Sort according to the given attributes



This is a programming assignment to test your understanding of sorting algorithms.
• Your goal is to implement an efficient sort algorithm to cover diverse input data.
• You will write a code in the C programming language to print out the sorted result
into the output file named ‘hw1 output.txt’ after sorting the objects in the input
file named ‘hw1 input.txt’. The input file consists of (1) the number of objects
to be sorted; (2) the attributes for objects–the key attribute for sorting is marked
with “(Key)”; and (3) the objects to be sorted. Each part is separated from the
next part by a character $. The sorted objects are in ascending order of the key
attribute. We note that any item can be the key attribute. We also assume that all
attribute types are string – attributes should be sorted alphabetically. Also, if two
objects with equal keys appear in the same order in sorted output as they appear
in the input file to be sorted. The details are as follows:
– The first part of the input file represents the number of objects to be sorted.
– The second part of the input file represents the attributes for objects; each
attribute is separated from the next attribute by a character :.
– The third part of the input file represents the objects to be sorted; each object
is separated from the next object by a character :.
• In the output file (hw1 output.txt), you should output the sorted objects.
1
• The following is an example of input and output files:
[ Input file : hw1_input . txt ]
3
$
P_Id ( Key ) : LastName : FirstName : Address : City
$
2: Svendson : Tove : Borgvn 23: Sandnes
3: Pettersen : Kari : Storgt 20: Stavanger
1: Hansen : Ola : Timoteivn 10: Sandnes
[ Output file : hw1_output . txt ]
1: Hansen : Ola : Timoteivn 10: Sandnes
2: Svendson : Tove : Borgvn 23: Sandnes
3: Pettersen : Kari : Storgt 20: Stavanger
• You will be judged by (1) the correctness of the results returned by your submitted
program, (2) the actual running time of the program (I will grade your score depending on the student ranking in the running time) and (3) the well-written document
to explain your source code and the performance analysis of your algorithm. For
test, we will use 1, 000 ≤ n ≤ 1, 000, 000, 1 ≤ t ≤ 10, and 1 ≤ m ≤ 15 where n is
the number of objects to be sorted, t is the number of attributes for each object,
and m is the maximum length of each attribute value. Also, 8GB RAM will be used
for testing. Please test your code extensively with several inputs, so you are sure it
works correctly.
• You cannot use any pre-defined algorithms and data structures except arrays provided by some libraries.
• Please upload your source code (c files), instructions to illustrate how your source
code works, document to explain your code and the performance analysis to iCampus.
• Your assignments must be your own original work. We will use a tool to
check for plagiarism in assignments.
2
