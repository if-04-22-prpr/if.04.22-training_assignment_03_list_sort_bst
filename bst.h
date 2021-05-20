/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: n/a
 * Title:			Binary Search Tree (BST)
 * ----------------------------------------------------------
 * Description:
 * The declaration of an abstract data type of a binary search tree.
 * ----------------------------------------------------------
 */

#ifndef ___BINARY_SEARCH_TREE__H
#define ___BINARY_SEARCH_TREE__H

#include <stddef.h>

/** The type of the binary search tree, named `Tree`. */

/**
 * Acquires ('creates') and provides a 'new' tree instance.
 * Any tree acquired via this function MUST be released using
 * function `tree_release()`.
 * 
 * Note: This function does not make any assumptions 
 * about how tree components, esp. nodes, are allocated.
 * 
 * @return The BST instance or 0, if no tree could by instantiated.
 */
<type> tree_acquire();

/**
 * Releases a tree that was obtained earlier via function `tree_obtain`.
 * Released trees MUST NOT be used anymore. Any instances that are
 * associated with the tree are released as well.
 * 
 * Note: The implementation of this function does not make any assumptions
 * about the allocation method of tree elements, but MUST match the implementation
 * of function `tree_acquire` as its inverse function.
 * 
 * @param p_tree The pointer to the tree to release. The value of the pointer
 * is set to 0, if the tree was successfully released, otherwise it is left untouched.
 */
<type> tree_release(Tree* p_tree);

/**
 * Determines whether or not the given tree is valid.
 * A tree is valid if it is not 0.
 * 
 * @param tree The tree to evaluate.
 * @return `True` if the tree is valid, false otherwise.
 */
<type>  tree_is_valid(<param>);

/**
 * Determines whether or not the tree contains at least one node.
 * 
 * @param tree The tree to evaluate.
 * @return `False` if the tree contains one or more nodes, `true` otherwise.
 */
<type>  tree_is_empty(<param>);

/**
 * Provides the number of nodes the tree consists of.
 * 
 * @param tree The tree to evaluate.
 * @return The size of the tree.
 */
size_t tree_get_size(<param>);

/**
 * Provides the height of the tree.
 * 
 * @param tree The tree to evaluate.
 * @return The height of the tree. It is 0 if the tree 
 * only consists of a root node and -1, if the tree is empty.
 */
<type>  tree_get_height(<param>);

/**
 * Provides the list of integers that are mapped to the given key.
 * 
 * @param tree The tree from which the data shall be retrieved.
 * @param key The value for which the associated values are provided.
 * @return The requested data or 0, if no data for the value are available.
 */
IntList tree_get(<param>);

/**
 * Adds the given `value` to the list of values that are associated with the given `key` value.
 *  
 * @param tree The tree to which the value shall be added.
 * @param key The mapping key.
 * @param value The value to add to the list of values sharing the same key.
 */
<type>  tree_add(<param>);

/**
 * Traverses the binary search tree in a way that visits all nodes
 * in ascending order.
 * 
 * @param tree The tree to traverse.
 * @param visitor The function that is invoked for each node.
 */
<type>  tree_visit_ascending(<param>);

/**
 * Traverses the binary search tree in a way that visits all nodes
 * in descending order.
 * 
 * @param tree The tree to traverse.
 * @param visitor The function that is invoked for each node.
 */
<type>  tree_visit_descending(<param>);

/**
 * Traverses the binary search tree using pre-order traversal scheme.
 * All nodes are visited by invoking the given `visitor` function.
 * 
 * @param tree The tree to traverse.
 * @param visitor The function that is invoked for each node.
 */
<type>  tree_visit_pre_order(<param>) ;

/**
 * Traverses the binary search tree using post-order traversal scheme.
 * All nodes are visited by invoking the given `visitor` function.
 * 
 * @param tree The tree to traverse.
 * @param visitor The function that is invoked for each node.
 */
<type>  tree_visit_post_order(<param>);

#endif
