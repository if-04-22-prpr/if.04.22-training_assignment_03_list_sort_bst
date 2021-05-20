/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for a List implementation
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions of a list.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_LIST_H
#define ___TEST_LIST_H

#include "shortcut.h"

TEST(test_list_obtain__shall_allocate_a_list);
TEST(test_list_obtain__shall_allocate_a_fresh_list);
TEST(test_list_obtain__shall_allocate_a_different_list);
TEST(test_list_obtain_failed__shall_not_allocate_a_list);

TEST(test_list_release__shall_release_a_valid_empty_list);
TEST(test_list_release__shall_release_a_valid_filled_list);
TEST(test_list_release__shall_ignore_release_of_an_invalid_list);

TEST(test_list_is_valid__shall_be_true_for_valid_list);
TEST(test_list_is_valid__shall_be_false_for_invalid_list);

TEST(test_list_add__shall_add_one_value_to_empty_list);
TEST(test_list_add__shall_add_multiple_values);
TEST(test_list_add__shall_ignore_invalid_list);

TEST(test_list_move__shall_not_move_invalid_node);
TEST(test_list_move__shall_not_move_node_after_itself);
TEST(test_list_move__shall_move_node_after_another_node);
TEST(test_list_move__shall_move_head_after_another_node);
TEST(test_list_move__shall_move_tail_after_another_node);
TEST(test_list_move__shall_move_node_to_beginning_of_list);
TEST(test_list_move__shall_move_node_to_end_of_list);

// TEST(test_list_remove__shall_not_remove_from_empty_list);
// TEST(test_list_remove__shall_remove_only_value);
// TEST(test_list_remove__shall_remove_one_value);
// TEST(test_list_remove__shall_remove_first_value);
// TEST(test_list_remove__shall_remove_value_in_the_middle);
// TEST(test_list_remove__shall_remove_value_at_the_end);
// TEST(test_list_remove__shall_not_remove_missing_value);

TEST(test_list_clear__shall_clear_empty_list);
TEST(test_list_clear__shall_clear_list_with_one_value);
TEST(test_list_clear__shall_clear_list_with_multiple_values);
TEST(test_list_clear__shall_ingore_invalid_list);

TEST(test_list_is_empty__shall_be_true__for_newly_obtained_list);
TEST(test_list_is_empty__shall_be_false__after_adding_values);
TEST(test_list_is_empty__shall_be_true_for_invalid_list);

TEST(test_list_get_size__shall_be_0_for_newly_obtained_list);
TEST(test_list_get_size__shall_reflect_number_of_values_after_adding_values);
// TEST(test_list_get_size__shall_reflect_number_of_values_after_removing_values);
TEST(test_list_get_size__shall_be_0_after_clear);
TEST(test_list_get_size__shall_be_0_for_invalid_list);

TEST(test_list_get_at__shall_return_0_for_empty_list);
TEST(test_list_get_at__shall_return_single_value);
TEST(test_list_get_at__shall_return_first_value);
TEST(test_list_get_at__shall_return_values_in_added_order);
TEST(test_list_get_at__shall_return_0_for_invalid_list);

TEST(test_list_it_obtain__shall_allocate_and_release_a_list_iterator_for_a_list);
TEST(test_list_it_obtain__shall_allocate_and_point_to_list_head);
TEST(test_list_it_obtain__shall_not_allocate_a_list_iterator_for_an_invalid_list);
TEST(test_list_it_is_valid);
TEST(test_list_it_is_valid__shall_be_invalid_for_0_iterator);
TEST(test_list_it_is_valid__shall_be_invalid_for_empty_list);

TEST(test_list_it_next__shall_move_to_next);
TEST(test_list_it_next__shall_return_false_for_invalid_it);
TEST(test_list_it_prev__shall_move_to_previous);
TEST(test_list_it_prev__shall_return_false_for_invalid_it);
TEST(test_list_it_place__shall_point_to_the_address_node);
TEST(test_list_it_place__shall_do_nothing_for_invalid_it);
TEST(test_list_it_get__shall_get_value);
TEST(test_list_it_get__shall_return_0_for_invalid_iterator);


#endif
