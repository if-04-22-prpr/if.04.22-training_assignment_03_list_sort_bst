/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: n/a
 * Title:			List Interface
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * The declaration of a list abstract data type.
 * ----------------------------------------------------------
 */


#include "list_types.h"

/**
 * Obtains ('creates') and provides a 'new' list instance.
 * Any list obtained via this function MUST be released using
 * function `release_list()`.
 * 
 * Note: This function does not make any assumptions 
 * about how list components, esp. nodes, are allocated.
 * 
 * @return The list instance or 0, if no list could by instantiated.
 */
<type> list_obtain();

/**
 * Releases a list that was obtained earlier via function `obtain_list`.
 * Released lists MUST NOT be used anymore.
 * 
 * Note: The implementation of this function does not make any assumptions
 * about the allocation method of list elements, but MUST match the implementation
 * of function `obtain_list` as its inverse function.
 * 
 * @param p_list The pointer to the list to release. The value of the pointer
 * is set to 0, if the list was successfully released, otherwise it is left untouched.
 */
void list_release(<params>);

/**
 * Determines whether or not the given list is valid.
 * 
 * @param list The list to evaluate.
 * @return `True` if the list is valid, false otherwise.
 */
<type> list_is_valid(<params>);

/**
 * Determines whether or not the list contains at least one item.
 * 
 * @param list The list to evaluate.
 * @return `False` if the list contains one or more items, `true` otherwise.
 */
<type> list_is_empty(<params>);

/**
 * Provides the number of values stored in the list.
 * 
 * @param list The list to evaluate.
 * @return The number of values the list contains.
 */
<type> list_get_size(<params>);

/**
 * Provides the value stored in the list at the given position.
 * 
 * @param list The list from which the value shall be retrieved.
 * @param index The zero-based position index of the value to retrieve.
 * @return The value stored at the given position or 0, if the position
 * is not available.
 */
<type> list_get_at(<params>);

/**
 * Inserts the given value at the end of the given list.
 * 
 * @param list The list to which the value shall be appended.
 * @param value The value to append to the list.
 */
void list_add(<params>);
 
/**
 * Moves the node addressed by `node_to_move` AFTER the node addressed
 * by `place_after`. If iterator `place_after`, the node is moved to 
 * the head of the list.
 * If the list or `node_to_move` is invalid, the invocation is ignored.
 * 
 * @param list The list holding the node to move.
 * @param node_to_move The iterator addressing the node to move.
 * @param place_after The iterator addressing the node, AFTER which the 
 * node shall be moved. If invalid, the node is moved to the head.
 */
void list_move(IntList list, IntListIterator node_to_move, IntListIterator place_after);

/**
 * Clears the given list by removing all values from the list.
 * 
 * @param list The list to clear.
 */
void list_clear(<params>);

