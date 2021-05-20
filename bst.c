/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: n/a
 * Title:			Binary Search Tree implementation
 * ----------------------------------------------------------
 * Description:
 * Implementation of a binary search tree.
 * ----------------------------------------------------------
 */

#include "bst.h"
#include "list.h"
#include "allocator.h"

#include "comparators.h"
#include "visitors.h"

/** The type of the binary search tree node (named TreeNode). */

/** The implementation of tree node data, contains key and list of values */

/** The implementation of tree data */

/* ===================================================================== */
/* private function declarations */

/** The function pointer type for visiting tree nodes. */
typedef void node_visitor_fn(TreeNode node, visitor_fn* data_visitor);

/** 
 * Acquires a single tree node and initializes its members, including the given key and value. 
 */
static TreeNode tree_node_acquire(char* key, int value);

/** 
 * Release a single tree node and its payload. 
 * Matches 'node_visitor_fn' signature, no attribute of 'data_visitor' is required.
 * @param data_visitor The function that is invoked for the payload of each visited node, may be 0.
 */
static void tree_node_release(TreeNode node, visitor_fn* data_visitor);

/**
 * Calculates the height of the given node.
 * 
 * @param node The node from which the height is calculated.
 * @return The height of the tree from the given node or 0, if the node is 0.
 */
static int tree_node_get_height(TreeNode node);

/**
 * The adapter function for visiting the payload of a visited node.
 * Matches 'node_visitor_fn' signature, requires attribute 'visitor_fn' of 
 * provided `data_visitor`.
 * 
 * @param node The visited node.
 * @param data_visitor The function to be invoked for the node's payload.
 */
static void tree_node_visit_payload(TreeNode node, visitor_fn* data_visitor);

/**
 * Traverses the tree according to 'Pre-Order' scheme and visits
 * each node using the 'node_visitor' function.
 * 
 * @param root The root of the tree to traverse
 * @param node_visitor The function that is invoked for each visited node.
 * @param data_visitor The function that is invoked for the payload of each visited node, may be 0.
 */
static void tree_traverse_pre_order(TreeNode root, node_visitor_fn* node_visitor, visitor_fn* data_visitor);

/**
 * Traverses the tree according to 'In-Order' scheme and visits
 * each node using the 'node_visitor' function.
 * 
 * @param root The root of the tree to traverse
 * @param node_visitor The function that is invoked for each visited node.
 * @param data_visitor The function that is invoked for the payload of each visited node, may be 0.
 */
static void tree_traverse_in_order(TreeNode root, node_visitor_fn* node_visitor, visitor_fn* data_visitor);

/**
 * Traverses the tree according to 'Reverse-In-Order' scheme and visits
 * each node using the 'node_visitor' function.
 * 
 * @param root The root of the tree to traverse
 * @param node_visitor The function that is invoked for each visited node.
 * @param data_visitor The function that is invoked for the payload of each visited node, may be 0.
 */
static void tree_traverse_reverse_in_order(TreeNode root, node_visitor_fn* node_visitor, visitor_fn* data_visitor);

/**
 * Traverses the tree according to 'Post-Order' scheme and visits
 * each node using the 'node_visitor' function.
 * 
 * @param root The root of the tree to traverse
 * @param node_visitor The function that is invoked for each visited node.
 * @param data_visitor The function that is invoked for the payload of each visited node, may be 0.
 */
static void tree_traverse_post_order(TreeNode root, node_visitor_fn* node_visitor, visitor_fn* data_visitor);

/* ===================================================================== */

static TreeNode tree_node_acquire(char* key, int value) {
    TreeNode node = alloc_mem(sizeof(...));
    if (node != 0) {
        ... init members ...;
    }
    return node;
}

Tree tree_acquire() {
    Tree tree = 0;
    tree = alloc_mem(sizeof(...));
    if (tree != 0) {
        ... init members ...;
    }
    return tree;
}

static void tree_node_release(TreeNode node, visitor_fn* data_visitor) {
    ...;
}

void tree_release(Tree* p_tree) {
    /* release the tree and its nodes by traversing it the right way and 
       invoke function 'tree_node_release' on each node */
}


static void tree_node_visit_payload(TreeNode node, visitor_fn* data_visitor) {
    /* delegate visiting the payload of a node to the visitor_fn */
}

