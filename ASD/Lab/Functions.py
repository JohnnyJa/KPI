from array import array
import random

def generateRandomArray(size):
    array = []
    for i in range(size):
        array.append(random.randint(0, size*10))
    return array

def generateSortedArray(size):
    array = []
    for i in range(0, size):
        array.append(i)
    return array

def generateUnsortedArray(size):
    array = []
    for i in range(size, 0, -1):
        array.append(i)
    return array

def classicBubbleSort(array):
    size = len(array)
    numOfTranspose = 0
    numOfCompare = 0
    for i in range(0, size):
        for j in range(0, size - 1):
            numOfCompare += 1
            if(array[j] > array[j + 1]):
                numOfTranspose += 1
                array[j], array[j + 1] = array[j + 1], array[j]
    return numOfCompare, numOfTranspose

def output(sorted_arr, compare, transpose):
    print(sorted_arr, end='\n\n')
    print("Num of compares: " + str(compare))
    print("Num of Transposes: " + str(transpose), end='\n\n')
    print("---------------------------------------------------------", end='\n\n')

def improvedBubbleSort(array):
    size = len(array)
    numOfTranspose = 0
    numOfCompare = 0
    for i in range(0, size):
        isSorted = True
        for j in range(0, size - i - 1):
            numOfCompare += 1
            if(array[j] > array[j + 1]):
                numOfTranspose += 1
                array[j], array[j + 1] = array[j + 1], array[j]
                isSorted = False
        if(isSorted):
            break
    return numOfCompare, numOfTranspose

def combSort(array):
    FACTOR = 1.247
    size = len(array)
    numOfTranspose = 0
    numOfCompare = 0
    step = round(size / FACTOR)
    isSorted = False
    
    while not isSorted:
        if step <= 2:
            step = 1
            isSorted = True

        for j in  range(0, size - step):
            numOfCompare += 1
            if(array[j]<array[j + step]):
                numOfTranspose += 1 
                array[j], array[j + step] = array[j + step],array[j]
                isSorted = False
        step = round(step / FACTOR)
        

    return numOfCompare, numOfTranspose