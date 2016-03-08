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

So, our strategy is this: generate all M! permutations of countries, and keep track of the best one seen so far. At the end (after looking at all permutations), we can expand that best ordering of countries into an ordering of conferences by replacing each country with the sorted list of conferences in that country. I encourage you to try to code this solution on your own.

I won't discuss the implementation in too much detail here, but there are a couple of important points. First, I use an approach called backtracking to generate the permutations recursively. In backtracking, you change the state temporarily, make a recursive call, and then revert the change. Using this technique, we can avoid making copies of the list of countries. To apply backtracking to the problem of generating permutations, we define a state by the current permutation of countries and the number of countries that have been permuted so far. We can then set the next country in the permutation and recursively generate the permutations for the rest of the list.

For example, say we want to generate all permutations of the list `[1, 2, 3]`. Of course, the current position that we are considering is position 0 (in this recursive call, we are choosing an element to go in the 0th spot in the list). There are 3 things we can put there: 1, 2, or 3. First, let's put 1 there and then recurse on the rest of the list, then put 2 there and recurse, then put 3 there and recurse. In that first recursive call, our current list is still `[1, 2, 3]`, but our current position is now 1. Now we have 2 things we can put at index 1: 2 or 3. This pattern continues. When we reach the end of the list, we've finished a permutation. It will be helpful to draw the tree of recursive calls; you can see that every possible permutation is generated. The following code will generate this tree.

```python
def gen_permutations(current_list, current_position):
    print " " * current_position + str(current_list) + " " + str(current_position)
    if current_position == len(current_list):
        print " " * current_position + str("finished permutation: ") + str(current_list)
    else:
        for index in range(current_position, len(current_list)):
            swap(current_list, current_position, index)
            gen_permutations(current_list, current_position + 1)
            swap(current_list, index, current_position)
```

When we finish a permutation, though, we want to see if it's better than the best one seen so far (that is, whether it has a smaller total airplane time than the current best, or, if it has the same airplane time as the current best, whether it is lexicographically smaller). To do this, we'll keep track of the current permutation's airplane time, as well as the best permutation and its airplane time. The best permutation and its airplane time should be global variables, so that we can update them at one leaf of the call tree and let those changes be seen at a later leaf of the call tree. But everyone knows that global variables are poor style, so instead we'll use a trick to achieve the same effect as pass-by-reference: we'll pass in a list for each global variable, and then just change the elements of the list.

Finally, our recursive function needs to be able to get the minimum conference number for a country in order to decide whether a permutation is lexicographically smaller than another one. When comparing two permutations, we don't need to compare all the conferences, just the first (minimum) for each country. This is because if two permutations have the same minimum conference for a given position, then they have the same country at that position, and all the conferences in that country will match. So, we need to be able to get from a list of countries to a list of their corresponding minimum conferences. To do this, we'll use a list comprehension and a dictionary mapping countries to their minimum conferences (we'll pass this dictionary into our recursive function).

Now we have enough information to assemble our final recursive function.

```python
# Generate all permutations
def gen_permutations(countries, cur_time, min_conferences, best_order, best_time, position):
    # If we're at the end of the list, we've finished a permutation
    if position == len(countries):
        # See if the current permutation (stored in countries) is better than best_order
        if cur_time < best_time[0]:
            # Our airplane time is less than the previous best
            for i in range(len(best_order)):
                best_order[i] = countries[i]
            best_time[0] = cur_time
        elif cur_time == best_time[0]:
            # Our airplane time is the same as the previous best
            # We must check if we have a lex. smaller list of min conferences
            if lex_less([min_conferences[country] for country in countries],
                        [min_conferences[country] for country in best_order]):
                for i in range(len(best_order)):
                    best_order[i] = countries[i]
                best_time[0] = cur_time
    else:
        # This is a recursive way to generate permutations using backtracking
        # For each country we haven't placed yet, put it in the current position and
        #     generate permutations on the rest of the list
        for index in range(position, len(countries)):
            swap(countries, position, index)
            new_time = cur_time + times[(countries[position - 1], countries[position])]
            gen_permutations(countries, new_time, min_conferences, best_order, best_time, position + 1)
            swap(countries, index, position)
```

This is the meat of the implementation. After calling gen_permutations with appropriate arguments, the best permutation of countries will be stored in the list object passed in as best_order. We can then expand best_order by printing the sorted conferences in each country. The full code and some tests can be found in the code directory.

Some readers will recognize this as the traveling salesman problem. The traveling salesman problem is one of the most famous NP-complete problems; there is no known polynomial time algorithm that solves it. There are faster algorithms that take O(M^2 2^M) time instead of O(M M!), but those are based on dynamic programming and are still only feasible for input sizes up to about 20. Note, however, that not all brute force problems are computationally hard. Sometimes there is a problem with a complex fast solution and a simple brute force solution whose constraints are small enough that the brute force solution will pass. Always check the constraints to see if brute force will work!

### Practice problems

[http://codeforces.com/problemset/problem/629/A]
[http://codeforces.com/problemset/problem/631/A]
[http://codeforces.com/problemset/problem/626/A]
[http://codeforces.com/problemset/problem/464/B]
[http://codeforces.com/problemset/problem/124/B]

### Further reading


