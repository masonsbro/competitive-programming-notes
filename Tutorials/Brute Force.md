## Brute force

### Motivating problem

#### Description

Emma is a graduate student at the University of Texas at Austin, and she has been invited to give talks at N conferences around the world. All of the conferences are taking place at the same time (and are not ending until Emma finishes her talks), and Emma gets to choose when she gives her talk at each conference. Emma loves traveling, but she hates airplanes--unfortunately, the N conferences are spread among M countries, and in order to travel between countries she must fly in a plane. She wants to schedule her talks in an order that minimizes the amount of time she spends in an airplane. Emma can hang glide between conferences in the same country, and she doesn't mind hang gliding; furthermore, she will hang glide to the first conference she attends and back to UT after the last conference.

Because Emma is busy putting together her talks, she wants you to find an optimal order for the N conferences.

#### Constraints

1 <= T <= 5  
1 <= N <= 100,000  
1 <= M <= 8  
1 <= A_i <= M  
1 <= X_j <= M  
1 <= Y_j <= M  
1 <= B_j <= 1,000

#### Input

The first line of the input contains T, the number of test cases. T test cases follow.

The first line of each test case contains N and M. N lines follow. The ith line contains an integer A_i indicating in which country the ith conference is located. After these N lines, M(M - 1) / 2 lines follow. The jth of these lines contains three integers, X_j, Y_j, and B_j. Each unordered pair (X_j, Y_j) appears exactly once. B_j is the time it takes to travel from country X_j to Y_j or vice versa.

#### Output

Output N lines. The ith line contains the ith conference Emma should give her talk at, in order to minimize her total time spent in an airplane. If there are multiple optimal orders, print the lexicographically smallest.

#### Sample input

```
1
5 3
1
2
1
3
3
1 2 10
2 3 50
1 3 100
```

#### Sample output

```
1
3
2
4
5
```

### Discussion



### Practice problems

### Further reading


