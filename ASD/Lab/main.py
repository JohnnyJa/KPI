import Functions

def main():
    size = 100
    RandomArray = Functions.generateRandomArray(size)
    SortedArray = Functions.generateSortedArray(size)
    UnsortedArray = Functions.generateUnsortedArray(size)

    arr = RandomArray[:]
    print("Unsorted random arr: \n" + str(RandomArray), end = '\n\n')

    print("---------------------------------------------------------", end = '\n\n')

    #
    # -------------------------------------------------------------------------------------------

    classicBubbleArray = arr[:]
    compare, transpose = Functions.classicBubbleSort(classicBubbleArray)

    # print("Classic Bubble sorted arr: ")
    # Functions.output(classicBubbleArray, compare, transpose)

    #
    # -------------------------------------------------------------------------------------------

    # improvedBubbleArray = arr[:]
    # compare, transpose = Functions.improvedBubbleSort(improvedBubbleArray)

    print("Improved Bubble sorted arr: ")
    Functions.output(improvedBubbleArray, compare, transpose)


    # combSort
    # -------------------------------------------------------------------------------------------

    combSortArray = arr[:]
    compare, transpose = Functions.combSort(combSortArray)

    # print("CombSort sorted arr: ")
    # print(combSortArray)

    print("Improved Bubble sorted arr: ")
    Functions.output(combSortArray, compare, transpose)

if __name__ == '__main__':
    main()

