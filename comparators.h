/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: n/a
 * Title:			Comparator functions
 * ----------------------------------------------------------
 * Description:
 * Interface for comparator functions
 * ----------------------------------------------------------
 */

#ifndef ___COMPARATORS_H
#define ___COMPARATORS_H

/** 
 * Declaration of function pointer for comparator functions. 
 * A comparator function determines whether the first value
 * is less than, equal to, or greater than the second value 
 * based on dedicated record attributes.
 * 
 * @param fst The first record to compare.
 * @param snd The second record to compare.
 * @return A value less than 0 if the `fst` values is before the `snd` value, 
 * 0 if both values values are equal, 
 * and a value larger than 0 otherwise. 
 */
typedef int comparator_fn(char* fst, char* snd);

/**
 * Compares two key strings (in ascending order).
 * 
 * @param fst The first key to compare.
 * @param snd The second key to compare.
 * @return A value less than 0 if the `fst` value is less than the `snd` value, 
 * 0 if both values are equal, 
 * or a value larger than 0 otherwise.
 * Note: An invalid key is less than a valid key, two invalid keys are equal.
 */
int compare_keys(char* fst, char* snd);


#endif