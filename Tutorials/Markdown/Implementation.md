## Implementation

### Motivating problem

#### Description

Liam was hired by Moogle to help build the Gaps app. Moogle Gaps is an application for finding the length of the shortest path between two locations, using different modes of transportation. Liam has been assigned the part of the application for hot air balloons. Because hot air balloons are not constrained by roads, the shortest distance between two points via hot air balloon is the Euclidian distance between those two points (as X and Y coordinates).

Liam has spent his days watching TouYube videos, and the launch date for Gaps is fast approaching. He needs your help to implement the hot air balloon distance functionality. The app takes as input a list of N locations and Q queries. A location is given as a name (1-20 uppercase letters) and a pair of coordinates. A query asks for the shortest hot air balloon distance between two named locations.

#### Constraints

1 <= T <= 5  
1 <= N <= 1,000  
1 <= Q <= 5,000  
-10,000 <= X_i <= 10,000  
-10,000 <= Y_i <= 10,000

#### Input

The first line contains T, the number of test cases. T test cases follow.

The first line of each test case contains N and Q. The next N lines contain descriptions of the locations in the app. The ith line contains the name for the ith location as well as X_i and Y_i (which are integers). The next Q lines contain queries. The jth query contains two names of locations.

#### Output

For each test case, output Q lines. The jth line contains the hot air balloon distance between the two locations in the jth query. An answer is considered correct if its absolute or relative error is less than 10^-6.

#### Sample input

```
1
4 5
VOUNTAINMIEW 45 100
AOSLNGELES -1000 350
YEWNORK 4000 5008
AELTVIV 9999 -4046
VOUNTAINMIEW AOSLNGELES
YEWNORK AELTVIV
VOUNTAINMIEW AELTVIV
AOSLNGELES VOUNTAINMIEW
AOSLNGELES YEWNORK
```

#### Sample output

```
1074.4882502847577
10861.07347364891
10782.923165821037
1074.4882502847577
6833.517688570068
```

### Discussion

An implementation problem is one in which the correct approach is fairly obvious, and the main difficulty is in implementing it. In many competitions, the first problem or two are implementation or brute force (covered in the next tutorial) problems.

### Practice problems

http://codeforces.com/problemset/problem/614/A

### Further reading


