/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for lists
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions of a list.
 * ----------------------------------------------------------
 */

#include "test_list.h"

#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "config.h"

#include "list.h"
#include "list_iterator.h"
#include "allocator.h"

#define ASSERT_NEW_VALID_LIST() _assert_new_valid_list(tc)
IntList _assert_new_valid_list(struct TestCase* tc) {
    int exp_alloc_cnt = mem_get_alloc_call_cnt() + 1;
    IntList list = list_obtain();
    ASSERT_TRUE(list != 0, MSG("Expected non-null list"));
    ASSERT_TRUE(list_is_valid(list), MSG("Expected a valid list"));
    ASSERT_TRUE(list_is_empty(list), MSG("Expected an empty list"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == exp_alloc_cnt, MSG("Expected mem_alloc being called exactly once, but was called %d time(s)", mem_get_alloc_call_cnt() - exp_alloc_cnt - 1));
    ASSERT_TRUE(mem_is_allocated(list), MSG("Expected obtained list1 is allocated using mem_alloc"));
    return list;
}

#define ASSERT_RESET_AND_NEW_VALID_LIST() _assert_reset_and_new_valid_list(tc)
IntList _assert_reset_and_new_valid_list(struct TestCase* tc) {
    mem_reset_stat();
    return _assert_new_valid_list(tc);
}


#define ASSERT_FREE_VALID_LIST(p_list) _assert_free_valid_list(tc, p_list)
void _assert_free_valid_list(struct TestCase* tc, IntList* p_list) {
    ASSERT_TRUE(p_list != 0 && list_is_valid(*p_list), MSG("Expected a valid list"));
    int additional_free_calls =  1 + list_get_size(*p_list);
    int exp_alloc_cnt = mem_get_alloc_call_cnt();
    int exp_free_cnt = mem_get_free_call_cnt() + additional_free_calls;
    ASSERT_TRUE(mem_is_allocated(*p_list), MSG("Expected that list to release was allocated using mem_alloc"));
    list_release(p_list);
    ASSERT_TRUE(p_list != 0 && *p_list == 0, MSG("Expected that list was set to 0"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == exp_alloc_cnt, MSG("Expected mem_alloc being NOT called, but was called %d time(s)", mem_get_alloc_call_cnt() - exp_alloc_cnt));
    ASSERT_TRUE(mem_get_free_call_cnt() == exp_free_cnt, MSG("Expected mem_free being called exactly %d time(s), but was called %d time(s)", exp_free_cnt, mem_get_free_call_cnt() - exp_free_cnt + additional_free_calls));
    ASSERT_FALSE(mem_is_allocated(*p_list), MSG("Expected that released list is not allocated anymore after release"));
}

#define ASSERT_MEM_STATUS_EXT(exp_alloc_call_cnt, exp_free_call_cnt, exp_block_cnt) _assert_mem_status_ext(tc, exp_alloc_call_cnt, exp_free_call_cnt, exp_block_cnt)
void _assert_mem_status_ext(struct TestCase* tc, int exp_alloc_call_cnt, int exp_free_call_cnt, int exp_block_cnt) {
    ASSERT_TRUE(mem_get_allocated_block_cnt() == exp_block_cnt, MSG("Expected %d allocated memory block(s), but is %d", exp_block_cnt, mem_get_allocated_block_cnt()));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == exp_alloc_call_cnt, MSG("Expected %d mem_alloc() call(s), but is %d", exp_alloc_call_cnt, mem_get_alloc_call_cnt()));
    ASSERT_TRUE(mem_get_free_call_cnt() == exp_free_call_cnt, MSG("Expected %d mem_free() call(s), but is %d", exp_free_call_cnt, mem_get_free_call_cnt()));
}

#define ASSERT_MEM_STATUS(exp_alloc_call_cnt, exp_free_call_cnt) _assert_mem_status_ext(tc, exp_alloc_call_cnt, exp_free_call_cnt, (exp_alloc_call_cnt - exp_free_call_cnt))
/* ------------------------------------------------------------------- */

TEST(test_list_obtain__shall_allocate_a_list) {
    int exp_alloc_cnt = 1;
    mem_reset_stat();
    IntList list = list_obtain();
    ASSERT_TRUE(list != 0, MSG("Expected non-null list"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == exp_alloc_cnt, MSG("Expected mem_alloc being called exactly %d time(s)", exp_alloc_cnt));
    ASSERT_TRUE(mem_is_allocated(list), MSG("Expected obtained list is allocated using mem_alloc"));
    if (list != 0) {
        free(list);
    }
}

TEST(test_list_obtain__shall_allocate_a_fresh_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    if (list != 0) {
        free(list);
    }
}

TEST(test_list_obtain__shall_allocate_a_different_list) {
    IntList list1 = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntList list2 = ASSERT_NEW_VALID_LIST();
    ASSERT_TRUE(list1 != list2, MSG("Expected different lists"));
    if (list1 != 0) {
        free(list1);
    }
    if (list2 != 0) {
        free(list2);
    }
}

TEST(test_list_obtain_failed__shall_not_allocate_a_list) {
    IntList list1 = ASSERT_RESET_AND_NEW_VALID_LIST();
    int exp_alloc_cnt = 1;
    mem_reset_calls();
    mem_block_allocs(true);
    IntList list = list_obtain();
    ASSERT_TRUE(list == 0, MSG("Expected null list"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == exp_alloc_cnt, MSG("Expected mem_alloc being called exactly %d time(s)", exp_alloc_cnt));
    if (list != 0) {
        free(list);
    }
    free(list1);
}



TEST(test_list_release__shall_release_a_valid_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_FREE_VALID_LIST(&list);
    ASSERT_TRUE(list == 0, MSG("Expected that list is set to 0"));
}

TEST(test_list_release__shall_release_a_valid_filled_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 11);
    list_add(list, 12);
    ASSERT_FREE_VALID_LIST(&list);
    ASSERT_TRUE(list == 0, MSG("Expected that list is set to 0"));
}

TEST(test_list_release__shall_ignore_release_of_an_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    int block_cnt = mem_get_allocated_block_cnt();
    IntList* p_list = 0;
    list_release(p_list);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == block_cnt, MSG("Expected unchanged memory allocation"));
    ASSERT_TRUE(mem_get_free_call_cnt() == 0, MSG("Expected NO mem_free() call, but was called %d time(s)", mem_get_free_call_cnt()));

    IntList list = 0;
    p_list = &list;
    list_release(p_list);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == block_cnt, MSG("Expected unchanged memory allocation"));
    ASSERT_TRUE(mem_get_free_call_cnt() == 0, MSG("Expected NO mem_free() call, but was called %d time(s)", mem_get_free_call_cnt()));

    list_release(&tmp);
}



TEST(test_list_is_valid__shall_be_true_for_valid_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_is_valid(list), MSG("Expected list to be valid"));
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_is_valid__shall_be_false_for_invalid_list) {
    ASSERT_FALSE(list_is_valid(0), MSG("Expected list to be invalid"));
}


TEST(test_list_add__shall_add_one_value_to_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    int exp_block_cnt = 2; // list and one node
    list_add(list, 11);
    ASSERT_MEM_STATUS(exp_block_cnt, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_add__shall_add_multiple_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    int exp_block_cnt = 2; // list and one node
    list_add(list, 11);
    ASSERT_MEM_STATUS(exp_block_cnt, 0);
    list_add(list, 12);
    exp_block_cnt++;
    ASSERT_MEM_STATUS(exp_block_cnt, 0);
    list_add(list, 13);
    exp_block_cnt++;
    ASSERT_MEM_STATUS(exp_block_cnt, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_add__shall_ignore_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(0, 11);
    ASSERT_FREE_VALID_LIST(&tmp);
}

TEST(test_list_move__shall_not_move_invalid_node) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    int exp_block_cnt = 1; // list
    list_move(0, 0, 0);
    ASSERT_MEM_STATUS(exp_block_cnt, 0);
    list_move(list, 0, 0);
    ASSERT_MEM_STATUS(exp_block_cnt, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_move__shall_not_move_node_after_itself) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 11);
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("Expected valid list iterator"));
    list_move(list, it, it);
    ASSERT_TRUE(list_get_at(list, 0) == 11, MSG("Expected that the node is still available"));
    ASSERT_MEM_STATUS(3, 0); // list and node alloc, node free
    list_it_release(&it);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_move__shall_move_node_after_another_node) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 11);
    list_add(list, 12);
    list_add(list, 13);
    list_add(list, 14);
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("Expected valid list iterator for node"));
    list_it_next(it);
    list_it_next(it);
    ASSERT_TRUE(list_it_get(it) == 13, MSG("Expected list iterator pointing to third node"));
    IntListIterator pos = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(pos), MSG("Expected valid list iterator for position"));
    ASSERT_TRUE(list_it_get(pos) == 11, MSG("Expected list iterator pointing to first node"));
    list_move(list, it, pos);
    ASSERT_TRUE(list_get_at(list, 0) == 11, MSG("Expected that the 1st node is unchanged"));
    ASSERT_TRUE(list_get_at(list, 1) == 13, MSG("Expected that the 2nd node is prev. 3rd node"));
    ASSERT_TRUE(list_get_at(list, 2) == 12, MSG("Expected that the 3rd node is prev. 2nd node"));
    ASSERT_TRUE(list_get_at(list, 3) == 14, MSG("Expected that the 4th node in unchanged"));
    ASSERT_MEM_STATUS(7, 0); // list and node alloc, node free
    list_it_release(&it);
    list_it_release(&pos);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_move__shall_move_head_after_another_node) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 11);
    list_add(list, 12);
    list_add(list, 13);
    list_add(list, 14);
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("Expected valid list iterator for node"));
    ASSERT_TRUE(list_it_get(it) == 11, MSG("Expected list iterator pointing to head"));
    IntListIterator pos = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(pos), MSG("Expected valid list iterator for position"));
    list_it_next(pos);
    list_it_next(pos);
    ASSERT_TRUE(list_it_get(pos) == 13, MSG("Expected list iterator pointing to 3rd node"));
    list_move(list, it, pos);
    ASSERT_TRUE(list_get_at(list, 0) == 12, MSG("Expected that the 1st node is prev. 2nd node"));
    ASSERT_TRUE(list_get_at(list, 1) == 13, MSG("Expected that the 2nd node is prev. 3rd node"));
    ASSERT_TRUE(list_get_at(list, 2) == 11, MSG("Expected that the 3rd node is prev. head node"));
    ASSERT_TRUE(list_get_at(list, 3) == 14, MSG("Expected that the 4th node is unchanged"));
    ASSERT_MEM_STATUS(7, 0); // list and node alloc, node free
    list_it_release(&it);
    list_it_release(&pos);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_move__shall_move_tail_after_another_node) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 11);
    list_add(list, 12);
    list_add(list, 13);
    list_add(list, 14);
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("Expected valid list iterator for node"));
    list_it_next(it);
    list_it_next(it);
    list_it_next(it);
    ASSERT_TRUE(list_it_get(it) == 14, MSG("Expected list iterator pointing to tail"));
    IntListIterator pos = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(pos), MSG("Expected valid list iterator for position"));
    list_it_next(pos);
    ASSERT_TRUE(list_it_get(pos) == 12, MSG("Expected list iterator pointing to 2nd node"));
    list_move(list, it, pos);
    ASSERT_TRUE(list_get_at(list, 0) == 11, MSG("Expected that the 1st node is prev. 1st node"));
    ASSERT_TRUE(list_get_at(list, 1) == 12, MSG("Expected that the 2nd node is prev. 2nd node"));
    ASSERT_TRUE(list_get_at(list, 2) == 14, MSG("Expected that the 3rd node is prev. tail node"));
    ASSERT_TRUE(list_get_at(list, 3) == 13, MSG("Expected that the 4th node is prev. 3rd node"));
    ASSERT_MEM_STATUS(7, 0); // list and node alloc, node free
    list_it_release(&it);
    list_it_release(&pos);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_move__shall_move_node_to_beginning_of_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 11);
    list_add(list, 12);
    list_add(list, 13);
    list_add(list, 14);
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("Expected valid list iterator for node"));
    list_it_next(it);
    list_it_next(it);
    ASSERT_TRUE(list_it_get(it) == 13, MSG("Expected list iterator pointing to 3rd node"));
    list_move(list, it, 0);
    ASSERT_TRUE(list_get_at(list, 0) == 13, MSG("Expected that the 1st node is prev. 3rd node"));
    ASSERT_TRUE(list_get_at(list, 1) == 11, MSG("Expected that the 2nd node is prev. 1st node"));
    ASSERT_TRUE(list_get_at(list, 2) == 12, MSG("Expected that the 3rd node is prev. 2nd node"));
    ASSERT_TRUE(list_get_at(list, 3) == 14, MSG("Expected that the 4th node is prev. 4th node"));
    ASSERT_MEM_STATUS(6, 0); // list and node alloc, node free
    list_it_release(&it);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_move__shall_move_node_to_end_of_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 11);
    list_add(list, 12);
    list_add(list, 13);
    list_add(list, 14);
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("Expected valid list iterator for node"));
    list_it_next(it);
    ASSERT_TRUE(list_it_get(it) == 12, MSG("Expected list iterator pointing to 2nd node"));
    IntListIterator pos = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(pos), MSG("Expected valid list iterator for position"));
    list_it_next(pos);
    list_it_next(pos);
    list_it_next(pos);
    ASSERT_TRUE(list_it_get(pos) == 14, MSG("Expected list iterator pointing to tail"));
    list_move(list, it, pos);
    ASSERT_TRUE(list_get_at(list, 0) == 11, MSG("Expected that the 1st node is prev. 1st node"));
    ASSERT_TRUE(list_get_at(list, 1) == 13, MSG("Expected that the 2nd node is prev. 3rd node"));
    ASSERT_TRUE(list_get_at(list, 2) == 14, MSG("Expected that the 3rd node is prev. 4th node"));
    ASSERT_TRUE(list_get_at(list, 3) == 12, MSG("Expected that the 4th node is prev. 2nd node"));
    ASSERT_MEM_STATUS(7, 0); // list and node alloc, node free
    list_it_release(&it);
    list_it_release(&pos);
    ASSERT_FREE_VALID_LIST(&list);
}



TEST(test_list_clear__shall_clear_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_clear(list);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_clear__shall_clear_list_with_one_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 51);
    list_clear(list);
    ASSERT_MEM_STATUS(2, 1);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_clear__shall_clear_list_with_multiple_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 51);
    list_add(list, 52);
    list_add(list, 53);
    list_clear(list);
    ASSERT_MEM_STATUS(4, 3);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_clear__shall_ingore_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_clear(0);
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_is_empty__shall_be_true__for_newly_obtained_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_is_empty(0), MSG("Expected that new list IS empty"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_is_empty__shall_be_false__after_adding_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 61);
    ASSERT_FALSE(list_is_empty(list), MSG("Expected that list with values IS NOT empty"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_is_empty__shall_be_true__after_clear) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 51);
    list_add(list, 52);
    list_add(list, 53);
    list_clear(list);
    ASSERT_FALSE(list_is_empty(0), MSG("Expected that list IS empty after list_clear"));
    ASSERT_MEM_STATUS(4, 3);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_is_empty__shall_be_true_for_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_is_empty(0), MSG("Expected that invalid list IS empty"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}



TEST(test_list_get_size__shall_be_0_for_newly_obtained_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_get_size(list) == 0, MSG("Expected that size of new list is 0"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_size__shall_reflect_number_of_values_after_adding_values) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 71);
    ASSERT_TRUE(list_get_size(list) == 1, MSG("Expected that size of list is 1 after adding first value"));
    list_add(list, 72);
    ASSERT_TRUE(list_get_size(list) == 2, MSG("Expected that size of list is 2 after adding second value"));
    list_add(list, 73);
    ASSERT_TRUE(list_get_size(list) == 3, MSG("Expected that size of list is 3 after adding third value"));
    ASSERT_MEM_STATUS(4, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

// TEST(test_list_get_size__shall_reflect_number_of_values_after_removing_values) {
//     IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
//     list_add(list, 81);
//     list_add(list, 82);
//     list_add(list, 83);
//     list_remove(list, 81);
//     ASSERT_TRUE(list_get_size(list) == 2, MSG("Expected that size of list is 2 after removing first value"));
//     list_remove(list, 82);
//     ASSERT_TRUE(list_get_size(list) == 1, MSG("Expected that size of list is 1 after removing second value"));
//     list_remove(list, 83);
//     ASSERT_TRUE(list_get_size(list) == 0, MSG("Expected that size of list is 0 after removing third value"));
//     ASSERT_MEM_STATUS(4, 3);
//     ASSERT_FREE_VALID_LIST(&list);
// }

TEST(test_list_get_size__shall_be_0_after_clear) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 81);
    list_add(list, 82);
    list_add(list, 83);
    list_clear(list);
    ASSERT_TRUE(list_get_size(list) == 0, MSG("Expected that size of list is 0 after clearing the list"));
    ASSERT_MEM_STATUS(4, 3);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_size__shall_be_0_for_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_get_size(0) == 0, MSG("Expected that size of invalid list is 0"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}


TEST(test_list_get_at__shall_return_0_for_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_get_at(list, 0) == 0, MSG("Expected that empty list provides always 0"));
    ASSERT_TRUE(list_get_at(list, 1) == 0, MSG("Expected that empty list provides always 0"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_at__shall_return_single_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 101);
    ASSERT_TRUE(list_get_at(list, 0) == 101, MSG("Expected that list provides the value"));
    ASSERT_MEM_STATUS(2, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_at__shall_return_first_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 101);
    list_add(list, 102);
    list_add(list, 103);
    ASSERT_TRUE(list_get_at(list, 0) == 101, MSG("Expected that list provides the value"));
    ASSERT_MEM_STATUS(4, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_at__shall_return_values_in_added_order) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 101);
    list_add(list, 102);
    list_add(list, 103);
    list_add(list, 104);
    ASSERT_TRUE(list_get_at(list, 0) == 101, MSG("Expected that list provides the first value"));
    ASSERT_TRUE(list_get_at(list, 1) == 102, MSG("Expected that list provides the second value"));
    ASSERT_TRUE(list_get_at(list, 2) == 103, MSG("Expected that list provides the third value"));
    ASSERT_TRUE(list_get_at(list, 3) == 104, MSG("Expected that list provides the new second value"));
    ASSERT_MEM_STATUS(5, 0);
    ASSERT_FREE_VALID_LIST(&list);
}

TEST(test_list_get_at__shall_return_0_for_invalid_list) {
    IntList tmp = ASSERT_RESET_AND_NEW_VALID_LIST();
    ASSERT_TRUE(list_get_at(0, 0) == 0, MSG("Expected that invalid list provides always 0"));
    ASSERT_MEM_STATUS(1, 0);
    ASSERT_FREE_VALID_LIST(&tmp);
}

/* ---------------------------------------- */

TEST(test_list_it_obtain__shall_allocate_and_release_a_list_iterator_for_a_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    mem_reset_calls();
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(it != 0, MSG("Expected non-null list iterator"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == 1, MSG("Expected mem_alloc being called exactly %d time(s) for the iterator", 1));
    list_it_release(&it);
    ASSERT_TRUE(mem_get_free_call_cnt() == 1, MSG("Expected mem_free being called exactly %d time(s) for the iterator", 1));
    list_release(&list);
}

TEST(test_list_it_obtain__shall_allocate_and_point_to_list_head) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 21);
    mem_reset_calls();
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(it != 0, MSG("Expected non-null list iterator"));
    ASSERT_TRUE(list_it_get(it) == 21, MSG("Expected list iterator pointing to list head (requires 'list_it_get()'"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == 1, MSG("Expected mem_alloc being called exactly %d time(s) for the iterator", 1));
    list_it_release(&it);
    ASSERT_TRUE(mem_get_free_call_cnt() == 1, MSG("Expected mem_free being called exactly %d time(s) for the iterator", 1));
    list_release(&list);
}

TEST(test_list_it_obtain__shall_not_allocate_a_list_iterator_for_an_invalid_list) {
    mem_reset_calls();
    IntListIterator it = list_it_obtain(0);
    ASSERT_TRUE(it == 0, MSG("Expected null list iterator"));
    ASSERT_TRUE(mem_get_alloc_call_cnt() == 0, MSG("Expected mem_alloc being called exactly %d time(s) for the iterator", 0));
}

TEST(test_list_it_is_valid) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 21);
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("Expected valid list iterator"));
    list_it_release(&it);
    list_release(&list);
}

TEST(test_list_it_is_valid__shall_be_invalid_for_0_iterator) {
    ASSERT_FALSE(list_it_is_valid(0), MSG("Expected invalid list iterator"));
}

TEST(test_list_it_is_valid__shall_be_invalid_for_empty_list) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    IntListIterator it = list_it_obtain(list);
    ASSERT_FALSE(list_it_is_valid(it), MSG("Expected invalid list iterator"));
    list_it_release(&it);
    list_release(&list);
}

TEST(test_list_it_next__shall_move_to_next) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 21);
    list_add(list, 22);
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("Expected valid list iterator"));
    ASSERT_TRUE(list_it_get(it) == 21, MSG("Expected list iterator pointing to list head (requires 'list_it_get()'"));
    ASSERT_FALSE(list_it_next(it), MSG("Expected list iterator moved to next"));
    ASSERT_TRUE(list_it_get(it) == 22, MSG("Expected list iterator pointing to next node (requires 'list_it_get()'"));
    ASSERT_FALSE(list_it_next(it), MSG("Expected list iterator did not move to next"));
    ASSERT_FALSE(list_it_is_valid(it), MSG("Expected list iterator rendered invalid"));
    list_it_release(&it);
    list_release(&list);
}

TEST(test_list_it_next__shall_return_false_for_invalid_it) {
    ASSERT_FALSE(list_it_next(0), MSG("Expected invalid list iterator has no next"));
}

TEST(test_list_it_prev__shall_move_to_previous) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 21);
    list_add(list, 22);
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("Expected valid list iterator"));
    ASSERT_TRUE(list_it_get(it) == 21, MSG("Expected list iterator pointing to list head (requires 'list_it_get()'"));
    ASSERT_FALSE(list_it_next(it), MSG("Expected list iterator moved to next"));
    ASSERT_TRUE(list_it_get(it) == 22, MSG("Expected list iterator pointing to next node (requires 'list_it_get()'"));
    ASSERT_FALSE(list_it_previous(it), MSG("Expected list iterator moved to previous"));
    ASSERT_TRUE(list_it_get(it) == 21, MSG("Expected list iterator pointing to last node (requires 'list_it_get()'"));
    ASSERT_FALSE(list_it_previous(it), MSG("Expected list iterator did not move to previous"));
    ASSERT_FALSE(list_it_is_valid(it), MSG("Expected list iterator rendered invalid"));
    list_it_release(&it);
    list_release(&list);
}
TEST(test_list_it_prev__shall_return_false_for_invalid_it) {
    ASSERT_FALSE(list_it_previous(0), MSG("Expected invalid list iterator has no previous"));
}
TEST(test_list_it_place__shall_point_to_the_address_node) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 21);
    list_add(list, 22);
    list_add(list, 23);
    IntListIterator it = list_it_obtain(list);
    IntListIterator other_it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("Expected valid list iterator"));
    ASSERT_TRUE(list_it_is_valid(other_it), MSG("Expected valid other list iterator"));
    ASSERT_TRUE(list_it_get(other_it) == 21, MSG("Expected other list iterator pointing to head node (requires 'list_it_get()'"));
    list_it_next(it);
    list_it_next(it);
    ASSERT_TRUE(list_it_get(it) == 23, MSG("Expected list iterator pointing to 3rd node (requires 'list_it_get()'"));
    list_it_place(other_it, it);
    ASSERT_TRUE(list_it_get(other_it) == 23, MSG("Expected other list iterator pointing to 3rd node (requires 'list_it_get()'"));
    ASSERT_TRUE(list_it_previous(other_it), MSG("Expected other list iterator moved to previous"));
    ASSERT_TRUE(list_it_get(other_it) == 22, MSG("Expected other list iterator pointing to 2nd node (requires 'list_it_get()'"));
    list_it_release(&it);
    list_it_release(&other_it);
    list_release(&list);

}
TEST(test_list_it_place__shall_do_nothing_for_invalid_it) {
    list_it_place(0, 0);
}

TEST(test_list_it_get__shall_get_value) {
    IntList list = ASSERT_RESET_AND_NEW_VALID_LIST();
    list_add(list, 21);
    list_add(list, 22);
    list_add(list, 23);
    IntListIterator it = list_it_obtain(list);
    ASSERT_TRUE(list_it_is_valid(it), MSG("#1 Expected valid list iterator"));
    ASSERT_TRUE(list_it_get(it) == 21, MSG("#1 Expected list iterator pointing to list head"));
    ASSERT_TRUE(list_it_next(it), MSG("#2 Expected list iterator moved to next"));
    ASSERT_TRUE(list_it_get(it) == 22, MSG("#2 Expected list iterator pointing to next node"));
    ASSERT_FALSE(list_it_next(it), MSG("#3 Expected list iterator moved to next"));
    ASSERT_TRUE(list_it_get(it) == 23, MSG("#3 Expected list iterator pointing to next node"));
    list_it_release(&it);
    list_release(&list);
}

TEST(test_list_it_get__shall_return_0_for_invalid_iterator) {
    ASSERT_TRUE(list_it_get(0) == 0, MSG("Expected list iterator return 0 for invalid iterator"));
}