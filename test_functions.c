/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for Award Aggregation ADT
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for Award Aggregation ADT.
 * ----------------------------------------------------------
 */

#include "test_functions.h"
#include "comparators.h"
#include "visitors.h"
#include "list.h"

#include <stdio.h>
#include <string.h>

/* ------------------------------------------------------------------- */

TEST(test_compare_keys_ascending) {
    char* str1 = "abc";
    char* str2 = "xyz";
    ASSERT_TRUE(compare_keys(str1, str2) < 0, MSG("Expected that '%s' is less than '%s'", str1, str2));
}

TEST(test_compare_keys_equal) {
    char* str1 = "abc";
    char str2[4];
    strcpy(str2, str1);
    ASSERT_TRUE(compare_keys(str1, str1) == 0, MSG("Expected that identical string is is equal to itself", str1, str1));
    ASSERT_TRUE(compare_keys(str1, str2) == 0, MSG("Expected that equal '%s' is is equal to '%s'", str1, str2));
}

TEST(test_compare_keys_descending) {
    char* str1 = "xyz";
    char* str2 = "abc";
    ASSERT_TRUE(compare_keys(str1, str2) > 0, MSG("Expected that '%s' is greater than '%s'", str1, str2));
}

TEST(test_compare_keys_0_ascending) {
    char* null_str = 0;
    char* str = "abc";
    ASSERT_TRUE(compare_keys(null_str, str) < 0, MSG("Expected that NULL string is less than '%s'", str));
}

TEST(test_compare_keys_0_equal) {
    ASSERT_TRUE(compare_keys(0, 0) == 0, MSG("Expected that two NULL string equal"));
}

TEST(test_compare_keys_0_descending) {
    char* null_str = 0;
    char* str = "abc";
    ASSERT_TRUE(compare_keys(str, null_str) > 0, MSG("Expected that '%s' is greater than NULL string", str));
}


TEST(test_print_data__valid) {
    char* key = "key";
    IntList list = list_obtain();
    list_add(list, 42);
    list_add(list, 84);
    print_data(key, list);
}

TEST(test_print_data__invalid_list) {
    char* key = "key";
    print_data(key, 0);
}

TEST(test_print_data__invalid_args) {
    print_data(0, 0);
}
