/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for BST
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for binary search tree.
 * ----------------------------------------------------------
 */

#include "test_bst.h"
#include "bst.h"
#include "list.h"
#include "allocator.h"

#include "general.h"
#include <stdio.h>
#include <string.h>


#define ASSERT_VALID_BST() _assert_valid_tree(tc)
static Tree _assert_valid_tree(struct TestCase* tc) {
    Tree tree = tree_acquire();
    ASSERT_TRUE(tree != 0, MSG("Could not acquire the BST, expected a non-null pointer"));
    ASSERT_TRUE(tree_is_valid(tree), MSG("Expected a valid BST instance"));
    return tree;
}

static size_t visit_idx = 0;
static char* keys[] =      { "O", "F", "V", "C", "S", "K", "X", "H", "E", "M", "Q", "U", "A", "L", "G", "R", "J", "Z", "B", "P", "W", "D", "T", "I", "N", "Y" };
static char* keys_asc[]  = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
static char* keys_desc[] = { "Z", "Y", "X", "W", "V", "U", "T", "S", "R", "Q", "P", "O", "N", "M", "L", "K", "J", "I", "H", "G", "F", "E", "D", "C", "B", "A" };
static char* keys_pre[] =  { "O", "F", "C", "A", "B", "E", "D", "K", "H", "G", "J", "I", "M", "L", "N", "V", "S", "Q", "P", "R", "U", "T", "X", "W", "Z", "Y" };
static char* keys_post[] = { "B", "A", "D", "E", "C", "G", "I", "J", "H", "L", "N", "M", "K", "F", "P", "R", "Q", "T", "U", "S", "W", "Y", "Z", "X", "V", "O" };
static size_t keys_cnt = sizeof(keys) / sizeof(keys[0]);
struct TestCase* cur_tc = 0;

void test_payload(char* act_key, char* exp_key, IntList data) {
    struct TestCase* tc = cur_tc;
    ASSERT_TRUE(act_key != 0, MSG("#%d: Expected valid key", visit_idx));
    ASSERT_TRUE(list_is_valid(data), MSG("#%d: Expected valid data list", visit_idx));
    if(act_key != 0) {
        ASSERT_TRUE(strcmp(exp_key, act_key) == 0, MSG("#%d: Expected key is '%s' but got '%s'", visit_idx, exp_key, act_key));
        ASSERT_TRUE(list_get_size(data) == 1, MSG("#%d: Expected data list contains one item", visit_idx));
        ASSERT_TRUE(list_get_at(data, 0) == 42, MSG("#%d: Expected correct data item", visit_idx));
    }
    visit_idx++;
}

void test_ascending(char* key, IntList data) {
    test_payload(key, keys_asc[visit_idx], data);
}

void test_descending(char* key, IntList data) {
    test_payload(key, keys_desc[visit_idx], data);
}

void test_preorder(char* key, IntList data) {
    test_payload(key, keys_pre[visit_idx], data);
}

void test_postorder(char* key, IntList data) {
    test_payload(key, keys_post[visit_idx], data);
}

/* ------------------------------------------------------------------- */

TEST(test_tree_acquire__shall_allocate_a_tree) {
    mem_reset_stat();
    Tree t = ASSERT_VALID_BST();
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 1, MSG("Expected one allocation"));
    tree_release(&t);
}

TEST(test_tree_release__shall_release_an_allocated_tree) {
    mem_reset_stat();
    Tree t = ASSERT_VALID_BST();
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 1, MSG("Expected one allocation"));
    tree_release(&t);
    ASSERT_TRUE(t == 0, MSG("Expected pointer to tree instance was set to 0 after release"));
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_tree_release__shall_not_release_an_invalid_tree) {
    mem_reset_stat();
    Tree t = ASSERT_VALID_BST();
    tree_release(&t);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
    tree_release(0);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_tree_is_valid__shall_return_true_for_a_valid_tree) {
    Tree t = ASSERT_VALID_BST();
    ASSERT_TRUE(tree_is_valid(t), MSG("Expected a valid tree"));
    tree_release(&t);
}

TEST(test_tree_is_valid__shall_return_false_for_an_invalid_tree) {
    ASSERT_FALSE(tree_is_valid(0), MSG("Expected an invalid tree"));
}

TEST(test_tree_is_empty__shall_return_true_for_empty_and_invalid_trees) {
    Tree t = ASSERT_VALID_BST();
    ASSERT_TRUE(tree_is_empty(t), MSG("Expected an empty tree"));
    tree_release(&t);
    ASSERT_TRUE(tree_is_empty(0), MSG("Expected that an invalid tree is empty"));
}

TEST(test_tree_is_empty__shall_return_false_for_non_empty_trees) { 
    mem_reset_stat();
    Tree t = ASSERT_VALID_BST();
    tree_add(t, "key", 42);
    ASSERT_FALSE(tree_is_empty(t), MSG("Expected a non-empty tree"));
    tree_release(&t);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_tree_get_size__shall_return_number_of_nodes) {
    mem_reset_stat();
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST();
    size_t exp_val = 0;
    size_t act_val = 0;
    ASSERT_TRUE(act_val == exp_val, MSG("Expected size of %d but got %d", exp_val, act_val));
    for (size_t idx = 0; idx < keys_cnt; idx++) {
        tree_add(t, keys[idx], 42 + idx);
        exp_val++;
        act_val = tree_get_size(t);
        ASSERT_TRUE(act_val == exp_val, MSG("Expected size of %d but got %d", exp_val, act_val));
    }
    tree_release(&t);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_tree_get_height__shall_return_height_of_the_tree) {
    mem_reset_stat();
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST();
    int exp_val = -1;
    int act_val = tree_get_height(t);
    ASSERT_TRUE(exp_val == exp_val, MSG("Expected height of %d but got %d", exp_val, act_val));
    for (size_t idx = 0; idx < keys_cnt; idx++) {
        tree_add(t, keys[idx], 42);
        exp_val = (idx == 0 ? 0 : idx < 3 ? 1 : idx < 7 ? 2 : idx < 13 ? 3 : idx < 23 ? 4 : 5);
        act_val = tree_get_height(t);
        ASSERT_TRUE(exp_val == exp_val, MSG("Expected height of %d but got %d", exp_val, act_val));
    }
    tree_release(&t);
}

TEST(test_tree_get__shall_provide_added_nodes) {
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST();
    for (size_t idx = 0; idx < keys_cnt; idx++) {
        int exp_size = idx + 1;
        for (size_t i = 0; i < exp_size; i++) {
            tree_add(t, keys[idx], idx + i * (i %2 == 1 ? -1 : 1));
        }
        IntList values = tree_get(t, keys[idx]);
        ASSERT_TRUE(list_is_valid(values), MSG("#%d: Expected valid data list", idx));
        int act_size = list_get_size(values);
        ASSERT_TRUE(exp_size == act_size, MSG("#%d: Expected data list of size %d but got %d", idx, exp_size, act_size));
        bool values_ok = true;
        for (size_t i = 0; i < act_size; i++) {
            values_ok = values_ok && list_get_at(values, i) == idx + i * (i %2 == 1 ? -1 : 1);
        }
        ASSERT_TRUE(values_ok, MSG("#%d: Expected data list contains added values (in added order)", idx));
    }
    tree_release(&t);
}

TEST(test_tree_visit_ascending__shall_visit_all_nodes_in_order) {
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST();
    for (size_t idx = 0; idx < keys_cnt; idx++) {
        tree_add(t, keys[idx], 42);
    }
    visit_idx = 0;
    tree_visit_ascending(t, &test_ascending);
    tree_release(&t);
}

TEST(test_tree_visit_descending__shall_visit_all_nodes_reverse_in_order) {
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST();
    for (size_t idx = 0; idx < keys_cnt; idx++) {
        tree_add(t, keys[idx], 42);
    }
    visit_idx = 0;
    tree_visit_descending(t, &test_descending);
    tree_release(&t);
}

TEST(test_tree_visit_pre_order__shall_visit_all_nodes_pre_order) {
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST();
    for (size_t idx = 0; idx < keys_cnt; idx++) {
        tree_add(t, keys[idx], 42);
    }
    visit_idx = 0;
    tree_visit_pre_order(t, &test_preorder);
    tree_release(&t);

    // printf("\n");
    // for (int i = 0; i < 26; i++) {
    //     printf("\"%s\", ", res[i]);
    // }
}

TEST(test_tree_visit_post_order__shall_visit_all_nodes_post_order) {
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST();
    for (size_t idx = 0; idx < keys_cnt; idx++) {
        tree_add(t, keys[idx], 42);
    }
    visit_idx = 0;
    tree_visit_post_order(t, &test_postorder);
    tree_release(&t);

    // printf("\n");
    // for (int i = 0; i < 26; i++) {
    //     printf("\"%s\", ", res[i]);
    // }
}
