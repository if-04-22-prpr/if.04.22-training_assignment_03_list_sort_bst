/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: n/a
 *-----------------------------------------------------------------------------
 * Description:
 * Build and print a tree of sensor data
 *-----------------------------------------------------------------------------
*/

#include "bst.h"
#include "sensor_data.h"
#include <stdio.h>

/**
 * Implement a BST of sensors identified by it's name.
 * For each sensor, multiple values are applied to the list of values for this sensor.
 * Therefore each tree node require a key (string, criterion) and a list of integer values.
 * 
 * The tree is populated by adding a pair of `get_sensor_name(i)` and `get_sensor_value(i)`.
 * Key and values sharing the same index belong together (`sensor_data.h`).
 * 
 * Tasks:
 * 1) Build the tree with provided sensor data.
 * 2) Print all sensors (name and values) in alphabethical order.
 * 3) Print all sensors (name and values) in reverse alphabethical order.
 * 4) Sort the values of each sensor ascending and print all sensors in tree pre-order.
 * 5) Sort the values of each sensor decending and print all sensors in tree post-order.
 * Don't forget to release the tree.
 */

int main(int argc, char *argv[]) {

    /* 1) Build the tree with provided sensor data. */

    /* 2) Print all sensors (name and values) in alphabethical order. */
    printf("\n\nSensor Data (Sensors in ascending order))\n");

    /* 3) Print all sensors (name and values) in reverse alphabethical order. */
    printf("\n\nSensor Data (Sensors in descending order))\n");

    /* 4) Sort the values of each sensor ascending and print all sensors in tree pre-order. */
    printf("\n\nAscending Sorted Sensor Data (Sensors in pre-order))\n");

    /* 5) Sort the values of each sensor decending and print all sensors in tree post-order. */
    printf("\n\nDescending Sorted Sensor Data (Sensors in post-order))\n");

}