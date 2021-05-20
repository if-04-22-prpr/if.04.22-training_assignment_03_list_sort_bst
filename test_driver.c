/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Title:			Tests implementation of a Liked List.
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Unit tests for a linked list implemenation.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "test_list.h"
#include "test_sort.h"
#include "test_functions.h"
#include "test_bst.h"

int main(int argc, char *argv[])
{
	ADD_TEST(test_list_obtain__shall_allocate_a_list);
	ADD_TEST(test_list_obtain__shall_allocate_a_fresh_list);
	ADD_TEST(test_list_obtain__shall_allocate_a_different_list);
	ADD_TEST(test_list_obtain_failed__shall_not_allocate_a_list);
	
	ADD_TEST(test_list_get_size__shall_be_0_for_newly_obtained_list);
	ADD_TEST(test_list_get_size__shall_reflect_number_of_values_after_adding_values);
	ADD_TEST(test_list_get_size__shall_be_0_after_clear);
	ADD_TEST(test_list_get_size__shall_be_0_for_invalid_list);

	ADD_TEST(test_list_release__shall_release_a_valid_empty_list);
	ADD_TEST(test_list_release__shall_release_a_valid_filled_list);
	ADD_TEST(test_list_release__shall_ignore_release_of_an_invalid_list);
	
	ADD_TEST(test_list_is_valid__shall_be_true_for_valid_list);
	ADD_TEST(test_list_is_valid__shall_be_false_for_invalid_list);
	
	ADD_TEST(test_list_is_empty__shall_be_true__for_newly_obtained_list);
	ADD_TEST(test_list_is_empty__shall_be_false__after_adding_values);
	ADD_TEST(test_list_is_empty__shall_be_true_for_invalid_list);
	
	ADD_TEST(test_list_add__shall_add_one_value_to_empty_list);
	ADD_TEST(test_list_add__shall_add_multiple_values);
	ADD_TEST(test_list_add__shall_ignore_invalid_list);

	ADD_TEST(test_list_move__shall_not_move_invalid_node);
	ADD_TEST(test_list_move__shall_not_move_node_after_itself);
	ADD_TEST(test_list_move__shall_move_node_after_another_node);
	ADD_TEST(test_list_move__shall_move_head_after_another_node);
	ADD_TEST(test_list_move__shall_move_tail_after_another_node);
	ADD_TEST(test_list_move__shall_move_node_to_beginning_of_list);
	ADD_TEST(test_list_move__shall_move_node_to_end_of_list);
	
	ADD_TEST(test_list_clear__shall_clear_empty_list);
	ADD_TEST(test_list_clear__shall_clear_list_with_one_value);
	ADD_TEST(test_list_clear__shall_clear_list_with_multiple_values);
	ADD_TEST(test_list_clear__shall_ingore_invalid_list);
	
	ADD_TEST(test_list_get_at__shall_return_0_for_empty_list);
	ADD_TEST(test_list_get_at__shall_return_single_value);
	ADD_TEST(test_list_get_at__shall_return_first_value);
	ADD_TEST(test_list_get_at__shall_return_values_in_added_order);
	ADD_TEST(test_list_get_at__shall_return_0_for_invalid_list);

	ADD_TEST(test_list_it_obtain__shall_allocate_and_release_a_list_iterator_for_a_list);
	ADD_TEST(test_list_it_obtain__shall_allocate_and_point_to_list_head);
	ADD_TEST(test_list_it_obtain__shall_not_allocate_a_list_iterator_for_an_invalid_list);
	ADD_TEST(test_list_it_is_valid);
	ADD_TEST(test_list_it_is_valid__shall_be_invalid_for_0_iterator);
	ADD_TEST(test_list_it_is_valid__shall_be_invalid_for_empty_list);

	ADD_TEST(test_list_it_next__shall_move_to_next);
	ADD_TEST(test_list_it_next__shall_return_false_for_invalid_it);
	ADD_TEST(test_list_it_prev__shall_move_to_previous);
	ADD_TEST(test_list_it_prev__shall_return_false_for_invalid_it);
	ADD_TEST(test_list_it_place__shall_point_to_the_address_node);
	ADD_TEST(test_list_it_place__shall_do_nothing_for_invalid_it);

	ADD_TEST(test_list_it_get__shall_get_value);
	ADD_TEST(test_list_it_get__shall_return_0_for_invalid_iterator);


	ADD_TEST(test_is_in_asc_order__shall_be_true_for_ascending_params);
	ADD_TEST(test_is_in_asc_order__shall_be_true_for_equal_params);
	ADD_TEST(test_is_in_asc_order__shall_be_false_for_descending_params);
	ADD_TEST(test_is_in_desc_order__shall_be_false_for_ascending_params);
	ADD_TEST(test_is_in_desc_order__shall_be_true_for_equal_params);
	ADD_TEST(test_is_in_desc_order__shall_be_true_for_descending_params);

	ADD_TEST(test_sort_ascending);
	ADD_TEST(test_sort_descending);
	ADD_TEST(test_sort_ascending_multiple);
	ADD_TEST(test_sort_descending_multiple);
	ADD_TEST(test_sort_ascending_reverse);
	ADD_TEST(test_sort_descending_reverse); 

	ADD_TEST(test_compare_keys_ascending);
	ADD_TEST(test_compare_keys_equal);
	ADD_TEST(test_compare_keys_descending);
	ADD_TEST(test_compare_keys_0_ascending);
	ADD_TEST(test_compare_keys_0_equal);
	ADD_TEST(test_compare_keys_0_descending);

	ADD_TEST(test_print_data__valid);
	ADD_TEST(test_print_data__invalid_list);
	ADD_TEST(test_print_data__invalid_args);

	ADD_TEST(test_tree_acquire__shall_allocate_a_tree);
	ADD_TEST(test_tree_release__shall_release_an_allocated_tree);
	ADD_TEST(test_tree_release__shall_not_release_an_invalid_tree);

	ADD_TEST(test_tree_is_valid__shall_return_true_for_a_valid_tree);
	ADD_TEST(test_tree_is_valid__shall_return_false_for_an_invalid_tree);

	ADD_TEST(test_tree_is_empty__shall_return_true_for_empty_and_invalid_trees);
	ADD_TEST(test_tree_is_empty__shall_return_false_for_non_empty_trees);

	ADD_TEST(test_tree_get_size__shall_return_number_of_nodes);
	ADD_TEST(test_tree_get_height__shall_return_height_of_the_tree);

	ADD_TEST(test_tree_get__shall_provide_added_nodes);
	ADD_TEST(test_tree_visit_ascending__shall_visit_all_nodes_in_order);
	ADD_TEST(test_tree_visit_descending__shall_visit_all_nodes_reverse_in_order);
	ADD_TEST(test_tree_visit_pre_order__shall_visit_all_nodes_pre_order);
	ADD_TEST(test_tree_visit_post_order__shall_visit_all_nodes_post_order);

	run_tests();
	return 0;
}
