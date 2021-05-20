/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: n/a
 * Title:			Insertion sort implementation
 * ----------------------------------------------------------
 * Description:
 * Implements the insertion sort algorithm using binary search
 * ----------------------------------------------------------
 */
#ifndef ___SORT_H
#define ___SORT_H

#include "list.h"
#include "sorting_criteria.h"

/**
 * Sorts the given list according to the insertion sort algorithm using binary.
 * 
 * @param list The list to be sorted.
 * @param criterion The pointer to the function that implements the sorting criterion.
 * That function accepts two integer parameters and returns a boolean value.
 */
void sort(IntList list, criterion_fn* criterion);

#endif
