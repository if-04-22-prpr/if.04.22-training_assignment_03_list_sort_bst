/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: n/a
 * Title:			Sensor Data
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * The list of sensor measurements.
 * ----------------------------------------------------------
 */
#ifndef ___SENSOR_DATA_H
#define ___SENSOR_DATA_H


#include "general.h"

/**
 * Provides the number of captured sensor data.
 * 
 * @return The number of available sensor data. 
 */
size_t get_sensor_data_count();

/**
 * Provides the name of the sensor that contributes 
 * a measured value for the given index.
 * 
 * @param idx The index of the measurement to receive.
 * @return The name of the sensor that measured the data.
 */
char* get_sensor_name(size_t idx);

/**
 * Provides the name of the sensor that contributes 
 * a measured value for the given index.
 * 
 * @param idx The index of the measurement to receive.
 * @return The name of the sensor that measured the data.
 */
int get_sensor_value(size_t idx);

#endif
