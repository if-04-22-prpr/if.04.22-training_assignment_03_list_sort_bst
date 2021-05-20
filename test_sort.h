/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for sorting
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for sorting.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_SORT_H
#define ___TEST_SORT_H

#include "shortcut.h"
#include "config.h"

TEST(test_is_in_asc_order__shall_be_true_for_ascending_params);
TEST(test_is_in_asc_order__shall_be_true_for_equal_params);
TEST(test_is_in_asc_order__shall_be_false_for_descending_params);
TEST(test_is_in_desc_order__shall_be_false_for_ascending_params);
TEST(test_is_in_desc_order__shall_be_true_for_equal_params);
TEST(test_is_in_desc_order__shall_be_true_for_descending_params);

TEST(test_sort_ascending);
TEST(test_sort_descending);
TEST(test_sort_ascending_multiple);
TEST(test_sort_descending_multiple);
TEST(test_sort_ascending_reverse);
TEST(test_sort_descending_reverse); 

#endif