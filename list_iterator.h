/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: n/a
 * Title:			List Iterator Interface
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * The declaration of a list iterator abstract data type.
 * ----------------------------------------------------------
 */


#include "list_types.h"

/**
 * Obtains ('creates') and provides a 'new' list iterator instance for the given list.
 * The provided iterator initially points to the head node of the list.
 * 
 * Any iterator obtained via this function MUST be released using
 * function `release_iterator()`.
 * 
 * Note: This function does not make any assumptions 
 * about how list components, esp. nodes, are allocated.
 * 
 * @param list The list for which the iterator is obtained.
 * @return The list iterator instance or 0, if no list iterator could by instantiated.
 */
<type> list_it_obtain(<param>);

/**
 * Releases a list iterator that was obtained earlier via function `list_it_obtain`.
 * Released list iterators MUST NOT be used anymore.
 * 
 * Note: The implementation of this function does not make any assumptions
 * about the allocation method of list iterator elements, but MUST match the implementation
 * of function `list_it_obtain` as its inverse function.
 * 
 * @param p_it The pointer to the list iterator to release. The value of the pointer
 * is set to 0, if the list iterator was successfully released, otherwise it is left untouched.
 */
<type> list_it_release(<param>);

/**
 * Determines whether or not the given list iterator is valid.
 * 
 * @param it The list iterator to evaluate.
 * @return `True` if the list iterator is valid, false otherwise.
 */
<param> list_it_is_valid(<param>);

/**
 * Proceeds the list iterator to the next list element.
 * It points to no node if it proceeds from the last node of the list.
 * 
 * @param it The list iterator to evaluate.
 * @return `True` if the list iterator could proceed to the next list node, `false` otherwise.
 */
<type> list_it_next(<param>);

/**
 * Proceeds the list iterator to the previous list element. 
 * It points to no node if it proceeds from the first node of the list.
 * 
 * @param it The list iterator to evaluate.
 * @return `True` if the list iterator could proceed to the previous list node, `false` otherwise.
 */
<type> list_it_previous(<param>);

/**
 * Places the list iterator onto the same node as the `pos` iterator.
 * 
 * @param it The list iterator to place.
 * @param pos The list iterator addressing the new position of the iterator.
 */
void list_it_place(<param>);

/**
 * Provides the value of the node the list iterator currently points to.
 * 
 * @param it The list iterator to evaluate.
 * @return The value of the current list node under the iterator.
 */
<type> list_it_get(<param>);

