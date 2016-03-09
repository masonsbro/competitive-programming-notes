# Utility function for swapping two elements in an array by index
def swap(L, i, j):
    temp = L[i]
    L[i] = L[j]
    L[j] = temp

# Utility function for checking whether list_1 is lexicographically smaller than list_2
def lex_less(list_1, list_2):
    i = 0
    while list_1[i] == list_2[i]:
        i += 1
    return list_1[i] < list_2[i]

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

num_test_cases = int(raw_input())

for test_case in range(num_test_cases):
    num_conferences, num_countries = map(int, raw_input().split())
    # This dictionary will store the conferences in each country
    countries = {}
    # We initialize each country with an empty list of conferences
    for country in range(1, num_countries + 1):
        countries[country] = []
    # Read in each conference's country
    for conference in range(1, num_conferences + 1):
        country = int(raw_input())
        countries[country].append(conference)
    # Sort the conferences in each country
    for country in range(1, num_countries + 1):
        countries[country].sort()
    # This dictionary will store the time to travel between pairs of countries
    times = {}
    # Read in each travel time
    for i in range(num_countries * (num_countries - 1) / 2):
        country_1, country_2, time = map(int, raw_input().split())
        times[(country_1, country_2)] = time
        times[(country_2, country_1)] = time
    # For convenience, add 0 travel times
    for country in range(1, num_countries + 1):
        times[(country, country)] = 0
    # Initialize the variables to be used by gen_permutations
    countries_list = range(1, num_countries + 1)
    cur_time = 0
    min_conferences = {country: countries[country][0] for country in countries_list}
    best_order = range(1, num_countries + 1)
    # 10000 > 8 * 1000, so this is worse than any conceivable ordering
    best_time = [10000]
    # Generate all permutations recursively
    gen_permutations(countries_list, cur_time, min_conferences, best_order, best_time, 0)
    # Print the conferences in each country, in sorted order
    for country in best_order:
        for conference in countries[country]:
            print conference
