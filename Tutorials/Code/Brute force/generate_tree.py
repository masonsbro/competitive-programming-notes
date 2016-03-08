def swap(L, i, j):
    temp = L[i]
    L[i] = L[j]
    L[j] = temp

num_permutations_seen = 0
def gen_permutations(current_list, current_position):
    global num_permutations_seen
    print " " * current_position + str(current_list) + " " + str(current_position)
    if current_position == len(current_list):
        print " " * current_position + str("finished permutation: ") + str(current_list)
        num_permutations_seen += 1
    else:
        for index in range(current_position, len(current_list)):
            swap(current_list, current_position, index)
            gen_permutations(current_list, current_position + 1)
            swap(current_list, index, current_position)

if __name__ == "__main__":
    gen_permutations([1, 2, 3, 4, 5], 0)
    assert num_permutations_seen == 120 # 120 == 5!