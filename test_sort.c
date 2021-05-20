/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for insertion sort with binary search
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for insertion sort using binary search.
 * ----------------------------------------------------------
 */

#include "test_sort.h"
#include "sort.h"
#include "list.h"
#include "sorting_criteria.h"

#include <stdlib.h>
#include <time.h>

#define MAX_VALUE 1024
static bool is_random_initialized = false;
void init_list_random(IntList list, unsigned int item_count) {
	if (!is_random_initialized) {
		srandom(time(0));
		is_random_initialized = true;
	}
	for (unsigned long i = 0; list != 0 && i < item_count; i++) {
		list_add(list, random() % MAX_VALUE);
	}
}

#define ASSERT_SORTED_LIST(direction_txt, criterion, reverse_criterion, multiple) _assert_sorted_list(tc, direction_txt, criterion, reverse_criterion, multiple)
void _assert_sorted_list(struct TestCase* tc, const char* direction_txt, criterion_fn* criterion, criterion_fn* reverse_criterion, bool multiple);

void _assert_sorted_list(struct TestCase* tc, const char* direction_txt, criterion_fn* criterion, criterion_fn* reverse_criterion, bool multiple) {
    IntList list = list_obtain();
    ASSERT_TRUE(list_is_valid(list), MSG("Expected valid list"));
    init_list_random(list, 16);
    if (multiple) {
        list_add(list, 42);
        list_add(list, 42);
        list_add(list, 42);
    }
    if (reverse_criterion != 0) {
        sort(list, reverse_criterion);
        int i = 1;
        for (; i < list_get_size(list) && reverse_criterion(list_get_at(list, i-1), list_get_at(list, i)); i++);
        ASSERT_TRUE(i == list_get_size(list), MSG("Expected that all elements are in reverse %s order as required for preparation", direction_txt));
    }
    sort(list, criterion);
    int i = 1;
    for (; i < list_get_size(list) && criterion(list_get_at(list, i-1), list_get_at(list, i)); i++);
    ASSERT_TRUE(i == list_get_size(list), MSG("Expected that all elements are in %s order", direction_txt));
    list_release(&list);
}

TEST(test_is_in_asc_order__shall_be_true_for_ascending_params) {
    ASSERT_TRUE(is_in_asc_order(1, 2), MSG("Expected true for ascending values"));
}
TEST(test_is_in_asc_order__shall_be_true_for_equal_params) {
    ASSERT_TRUE(is_in_asc_order(3, 3), MSG("Expected true for equal values"));
}
TEST(test_is_in_asc_order__shall_be_false_for_descending_params) {
    ASSERT_FALSE(is_in_asc_order(5, 4), MSG("Expected false for descending values"));
}
TEST(test_is_in_desc_order__shall_be_false_for_ascending_params) {
    ASSERT_FALSE(is_in_desc_order(11, 12), MSG("Expected false for ascending values"));
}
TEST(test_is_in_desc_order__shall_be_true_for_equal_params) {
    ASSERT_TRUE(is_in_desc_order(13, 13), MSG("Expected true for ascending values"));
}
TEST(test_is_in_desc_order__shall_be_true_for_descending_params) {
    ASSERT_TRUE(is_in_desc_order(15, 14), MSG("Expected true for descending values"));
}

TEST(test_sort_ascending) {
    ASSERT_SORTED_LIST("ascending", &is_in_asc_order, 0, false);
}

TEST(test_sort_descending) {
    ASSERT_SORTED_LIST("descending", &is_in_desc_order, 0, false);
}

TEST(test_sort_ascending_multiple) {
    ASSERT_SORTED_LIST("ascending sorted", &is_in_asc_order, 0, true);
}

TEST(test_sort_descending_multiple) {
    ASSERT_SORTED_LIST("descending sorted", &is_in_desc_order, 0, true);
}

TEST(test_sort_ascending_reverse) {
    ASSERT_SORTED_LIST("ascending reverse", &is_in_asc_order, &is_in_desc_order, false);
}

TEST(test_sort_descending_reverse) {
    ASSERT_SORTED_LIST("descending reverse", &is_in_desc_order, &is_in_asc_order, false);
}
