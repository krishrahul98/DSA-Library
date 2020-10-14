def divisible_evenly(number, max_range):
    for x in range(max_range - 1, 1, -1):
        if number % x != 0:
            return False

    return True


def find_smallest_multiple():
    smallest = 20
    while True:
        if smallest % 20 == 0 and divisible_evenly(smallest, 20):
            return smallest
        smallest += 20

print(find_smallest_multiple())
