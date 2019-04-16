// Andrew Welch

// Quick sort with modification to no longer resort to insertion sort
// when elements < 10

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include "insertsort.h"
/*
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template <typename Comparable>
const Comparable &median3(std::vector<Comparable> &a, int left, int right)
{
    int center = (left + right) / 2;

    if (a[center] < a[left])
        std::swap(a[left], a[center]);
    if (a[right] < a[left])
        std::swap(a[left], a[right]);
    if (a[right] < a[center])
        std::swap(a[center], a[right]);

    // Place pivot at position right - 1
    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}

/*
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quicksort(std::vector<Comparable> &a, int left, int right)
{
    // Altered to work for cases less than 10
    if (left + 2 <= right)
    {
        const Comparable &pivot = median3(a, left, right);

        // Begin partitioning
        int i = left, j = right - 1;
        for (;;)
        {
            while (a[++i] < pivot)
            {
            }
            while (pivot < a[--j])
            {
            }
            if (i < j)
                std::swap(a[i], a[j]);
            else
                break;
        }

        std::swap(a[i], a[right - 1]); // Restore pivot

        quicksort(a, left, i - 1);  // Sort small elements
        quicksort(a, i + 1, right); // Sort large elements
    }
    else
    {
        if (a[left] > a[right])
        {
            std::swap(a[left], a[right]);
        }
    }
}
/*
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quicksort(std::vector<Comparable> &a)
{
    quicksort(a, 0, a.size() - 1);
}

#endif
