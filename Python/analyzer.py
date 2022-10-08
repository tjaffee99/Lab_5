import python.stringdata as a
import time as t


# linear search algorithm. Goes thorugh the elemtns in order and sees if it finds it
def linear_search(data, tar):
    # used to calculate the time to find the target
    currTime = t.time()
    for i in range(len(data)):
        if data[i] == tar:
            print('Time to search: ', t.time() - currTime)
            return i
    print('Time to search: ', t.time() - currTime)
    return -1


# non-recursive binary
def binary_search(data, tar):
    # keeps track of what our new beginning of the split list will be
    beg = 0
    # keeps track of what our new end of the split list will be
    end = len(data)
    # keeps track of the time it takes to find each target
    currTime = t.time()

    # Runs until the array has split to the smallest length it can be
    while beg < end:
        # calcutaes the midpoint of the lists (and after they ar split)
        midPoint = int((beg + end) / 2)

        # if it's at the endpoint, return the value. Program over
        if data[midPoint] == tar:
            print('Time to search: ', t.time() - currTime)
            return midPoint
        # if the midpoint value is less than the target value, set the end of the split list to the mipoint
        elif data[midPoint] > tar:
            end = midPoint
        # if the midpoint value is greater than the target value, set the beginning of the split list to the mipoint
        elif data[midPoint] < tar:
            beg = midPoint + 1
    print('Time to search: ', t.time() - currTime)
    return -1


def main():
    dataset = a.get_data()
    targets = ["not_here", "mzzzz", "aaaaa"]
    print('linear:')
    for x in targets:
        print(linear_search(dataset, x))

    print('\nbinary: ')
    for x in targets:
        print(binary_search(dataset, x))


if __name__ == "__main__":
    main()