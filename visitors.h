/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: n/a
 * Title:			Visitor functions
 * ----------------------------------------------------------
 * Description:
 * Interface for visitor functions
 * ----------------------------------------------------------
 */


#ifndef ___VISITORS_H
#define ___VISITORS_H

#include "general.h"
#include "list_types.h"

/** 
 * Declaration of function pointer for visitor functions. 
 * A visitor function is invoked when a node is visited
 * and processes the payload of the node in a specific manner.
 * 
 * @param key The key of the visited node.
 * @param value_list The value list of the visited node.
 */
typedef void visitor_fn(char* key, IntList value_list);

/**
 * Prints the data. 
 * 
 * @param key The key of the visited node.
 * @param value_list The value list of the visited node.
 */
void print_data(char* key, IntList value_list);

/**
 * Sorts the items of the value list in ascending order. 
 * 
 * @param key The key of the visited node.
 * @param value_list The value list of the visited node.
 */
void sort_values_asc(char* key, IntList value_list);

/**
 * Sorts the items of the value list in descending order. 
 * 
 * @param key The key of the visited node.
 * @param value_list The value list of the visited node.
 */
void sort_values_desc(char* key, IntList value_list);


#endif