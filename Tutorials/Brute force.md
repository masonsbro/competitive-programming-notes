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

Output N lines. The ith line contains the ith conference Emma should give her talk at, in order to minimize her total time spent in an airplane. If there are multiple optimal orders, print the lexicographically smallest (where one sequence of numbers S is lexicographically smaller than another sequence of numbers T if the first index at which S and T differ is i and S_i < T_i).

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

A brute force problem is one in which the obvious algorithm is good enough; sometimes a more efficient solution is possible but more complex than the brute force approach. When reading a problem, it is often helpful to come up with a brute force approach even if the problem's contraints call for something faster. The brute force solution can serve as a starting point for the final solution. Of course, when the constraints are small enough that the brute force solution should run in time, no more thinking is necessary. Once you identify a problem as brute force, it becomes an implementation problem.

The primary hint that indicates that a problem should be solved with a brute force approach is the input size. Although it's kind of buried in the above problem, the input size for the hard part of the problem is very small.

A careful reading of the above problem statement should yield a few key insights:

* Emma wants to visit M countries in some order
* Emma can rearrange the conferences within a country without changing her total airplane time
* We want to choose the lexicographically smallest order of conferences that minimizes total airplane time

Let's see if we can decompose the problem into a few different parts. First, we must choose some order of countries to visit; then, we must choose the order of the conferences in each country. There are M! different orders of countries, and M <= 8, so we can actually just try all of these. Now, given some order of countries, what's the lexicographically smallest way to arrange the conferences? With a little bit of thinking, it should be clear that we should simply sort the conferences within each country. With this insight, we can easily generate the lexicographically smallest answer if we know the correct order of the M countries.

We're almost ready to begin solving the problem! There is one last case to consider: what if two orderings of the countries are tied? That is, what if two (or more) of the M! orderings of countries have the same total airplane time? Obviously, the tiebreaker is lexicographic: we should choose the one that will produce the lexicographically smallest final answer. Keep in mind that we are not choosing the lexicographically smallest ordering of countries, but that of conferences. It is possible that, say, country 1 should be the last country visited because it contains conferences with high numbers.

### Practice problems

### Further reading


