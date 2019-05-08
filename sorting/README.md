# Sorting algorithms

Works for any sort of basic data type, such as integer, string, char and double (but you have to alter the main function for your needs).

To test with integers, you can go to random_files/random_file.cpp and generate a file with integers and run with ./merge_sort < testfile

Implemented from Introduction to Algorithms, Cormen by myself for learning purposes.

# Comparison sorts

It's provable that the best complexity for a comparision sort is O(n lg(n)), by using comparisons, it's not possible to go lower than this, except for constant factors.

## Bubble sort

O(n²) 100% terrible, but implementation is trivial.

## Insertion sort

O(n²) 99.99% terrible, but implementation is trivial.

## Merge sort

O(n lg(n)) works by dividing each array in half, all the way to the trivial case and building the sorted array using the solutions for smaller cases that are already sorted.

## Heap sort

O(n lg(n)) uses a heap data structure and removes the root of the heap tree for every element of the array.

## Quick sort

O(n lg(n)) works by dividing the array (such as in merge sort) into 2 sections (possibly of different lenghts) and sorting while going down the recursion tree, and when it reaches all leaves it's sorted.

Footnote: Randomized quick sort, O(n lg(n)), the point of division of the array is selected randomly. It's supposed to reduce the complexity but I see no difference, and I find quick sort (or at least my implementations of it), to be worse then merge sort and heap sort.

# Counting sort

O(n) but keep in mind that it only works for integers (because it uses prefix sums) and all numbers must fit as indexes in an array, otherwise it's overflow. Works best if the input is much larger than the size of any individual element and/or elements are small in size (I mean, 10⁵ small, try it with 10⁹ to test the segmentation fault for yourself).

# Radix sort

O((b/r)(n + 2^(r))), r <= b with n b-bit non-negative integers, it uses counting sort but taking drastically less memory. Try it with a random files with numbers going up to 10¹⁴, it's remarkbly efficient.

# Bucket sort

O(n) and only works with floting point numbers ranging from [0, 1]. Works by dividing into buckets (groups of ) Uses insertion sort.