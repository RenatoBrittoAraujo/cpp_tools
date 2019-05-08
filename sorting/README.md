# Sorting algorithms

Works for any sort of basic data type, such as integer, string, char and double (but you have to alter the main function for what your need are).

To test with integers, you can do to random_files/random_file.cpp and generate a file with integers and run with ./merge_sort < testfile

# Comparison sorts

It's provable that the best complexity for a comparision sort is O(n lg(n)), by using comparisons, it's not possible to go lower than this, except for constant factors.

## Bubble sort

O(n²) 100% terrible, but implementation is trivial

## Insertion sort

O(n²) 99.99% terrible, but implementation is trivial

## Merge sort

O(n lg(n)) works by dividing each array in half, all the way to the trivial case and building the sorted array using the solutions for smaller cases that are already sorted.

## Heap sort

O(n lg(n)) uses a heap data structure and removes the root of the heap tree for every element of the array.

## Quick sort

O(n lg(n)) works by dividing the array (such as in merge sort) into 2 sections (possibly of different lenghts) and sorting while going down the recursion tree, and when it reaches all leaves it's sorted

### Randomized quick sort

O(n lg(n)) The point of division of the array is selected randomly

# Counting sort

O(n) but keep in mind that it only works for integers (because it uses prefix sums) and all numbers must fit as indexes in an array, otherwise it's overflow. Works best if the input is much larger than the size of any individual element.

# Radix sort

# Bucket sort