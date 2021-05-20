/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding
 *-----------------------------------------------------------------------------
 * Exercise Number: n/a
 * Title:			Sensor Data
 * Author:			S. Schraml
 *-----------------------------------------------------------------------------
 * Description:
 * Provides the list of sensor measurements.
 *-----------------------------------------------------------------------------
*/

#include "sensor_data.h"

struct SensorData {
    char* sensor_name;
    int sensor_value;
};

struct SensorData sensor_data[] = {
    {"Illuminance", 409},
    {"Precipitation", 8},
    {"Dew-Point", 2},
    {"Wind-Speed", 18},
    {"CO2", 401},
    {"Soil-Moisture", 6},
    {"Soil-Moisture", 0},
    {"Accum.-Precip.", 1},
    {"Air-Pressure", 1046},
    {"Illuminance", 439},
    {"Air-Pressure", 989},
    {"Accum.-Precip.", 8},
    {"Soil-Moisture", 2},
    {"Accum.-Precip.", 14},
    {"Dew-Point", -6},
    {"Soil-Moisture", 5},
    {"Air-Pressure", 982},
    {"Humidity", 87},
    {"UV-Index", 3},
    {"Accum.-Precip.", 7},
    {"Precipitation", 7},
    {"Precipitation", 11},
    {"Soil-Moisture", 0},
    {"Dew-Point", 8},
    {"Dew-Point", 10},
    {"Solar-Radiation", 620},
    {"Wind-Direction", -118},
    {"Temperature", 12},
    {"Air-Pressure", 980},
    {"CO2", 419},
    {"Temperature", 28},
    {"Wind-Speed", 10},
    {"Illuminance", 479},
    {"Humidity", 61},
    {"Wind-Speed", 25},
    {"Temperature", 21},
    {"CO2", 444},
    {"Wind-Speed", 9},
    {"Temperature", 28},
    {"Temperature", 26},
    {"Dew-Point", 2},
    {"Dew-Point", -1},
    {"Illuminance", 202},
    {"Dew-Point", 2},
    {"Illuminance", 475},
    {"Accum.-Precip.", 19},
    {"Soil-Moisture", 8},
    {"Air-Pressure", 1006},
    {"UV-Index", 5},
    {"Precipitation", 5},
    {"Dew-Point", -8},
    {"Solar-Radiation", 364},
    {"Soil-Moisture", 6},
    {"Humidity", 49},
    {"Solar-Radiation", 507},
    {"Wind-Direction", -108},
    {"Wind-Direction", 114},
    {"Accum.-Precip.", 15},
    {"Wind-Direction", 155},
    {"CO2", 398},
    {"Dew-Point", -9},
    {"Wind-Direction", -69},
    {"Air-Pressure", 1021},
    {"Precipitation", 12},
    {"Humidity", 45},
    {"Illuminance", 446},
    {"Humidity", 77},
    {"Temperature", 28},
    {"Wind-Direction", -94},
    {"Accum.-Precip.", 16},
    {"UV-Index", 3},
    {"UV-Index", 3},
    {"Wind-Direction", -75},
    {"Wind-Direction", -124},
    {"Humidity", 64},
    {"Humidity", 51},
    {"Humidity", 89},
    {"Wind-Speed", 3},
    {"Temperature", 13},
    {"Air-Pressure", 1032},
    {"Temperature", 15},
    {"Temperature", 11},
    {"Wind-Speed", 20},
    {"Temperature", 12},
    {"Solar-Radiation", 717},
    {"Solar-Radiation", 900},
    {"Accum.-Precip.", 6},
    {"Air-Pressure", 1008},
    {"Temperature", 15},
    {"Wind-Speed", 6},
    {"CO2", 405},
    {"Temperature", 29},
    {"Humidity", 48},
    {"Precipitation", 3},
    {"Dew-Point", -6},
    {"Wind-Direction", -152},
    {"Wind-Speed", 9},
    {"Precipitation", 2},
    {"Wind-Speed", 25},
    {"Wind-Speed", 20},
    {"UV-Index", 4},
    {"Illuminance", 334},
    {"Air-Pressure", 1005},
    {"Dew-Point", 5},
    {"Dew-Point", -2},
    {"Illuminance", 441},
    {"Solar-Radiation", 301},
    {"Dew-Point", -4},
    {"Soil-Moisture", 8},
    {"Solar-Radiation", 342},
    {"Solar-Radiation", 236},
    {"CO2", 424},
    {"Accum.-Precip.", 21},
    {"CO2", 419},
    {"Precipitation", 4},
    {"Precipitation", 3},
    {"CO2", 439},
    {"Dew-Point", 6},
    {"UV-Index", 3},
    {"Solar-Radiation", 1063},
    {"Temperature", 10},
    {"Humidity", 64},
    {"Solar-Radiation", 145},
    {"CO2", 394},
    {"UV-Index", 2},
    {"UV-Index", 5},
    {"Soil-Moisture", 8},
    {"Humidity", 83},
    {"Air-Pressure", 1009},
    {"Solar-Radiation", 955},
    {"Accum.-Precip.", 16},
    {"Wind-Direction", -37},
    {"Air-Pressure", 1004},
    {"CO2", 405},
    {"Soil-Moisture", 6},
    {"Air-Pressure", 986},
    {"Wind-Direction", -107},
    {"Temperature", 27},
    {"UV-Index", 0},
    {"Dew-Point", 7},
    {"Wind-Direction", 174},
    {"Wind-Speed", 12},
    {"Soil-Moisture", 6},
    {"Accum.-Precip.", 0},
    {"Wind-Speed", 13},
    {"Wind-Speed", 4},
    {"Illuminance", 333},
    {"Humidity", 62},
    {"Illuminance", 172},
    {"Soil-Moisture", 0},
    {"Wind-Speed", 19},
    {"Accum.-Precip.", 2},
    {"Dew-Point", -1},
    {"Precipitation", 6},
    {"UV-Index", 1},
    {"UV-Index", 4},
    {"Soil-Moisture", 1},
    {"Air-Pressure", 1017},
    {"Precipitation", 7},
    {"Dew-Point", -3},
    {"Temperature", 20},
    {"Precipitation", 0},
    {"UV-Index", 6},
    {"Humidity", 49},
    {"UV-Index", 3},
    {"Wind-Speed", 10},
    {"Wind-Direction", 64},
    {"Illuminance", 307},
    {"Soil-Moisture", 5},
    {"Illuminance", 252},
    {"Air-Pressure", 996},
    {"Soil-Moisture", 5},
    {"Wind-Direction", 150},
    {"Soil-Moisture", 3},
    {"CO2", 427},
    {"Wind-Direction", -90},
    {"CO2", 409},
    {"UV-Index", 2},
    {"Wind-Speed", 2},
    {"Humidity", 52},
    {"Soil-Moisture", 1},
    {"Temperature", 30},
    {"Precipitation", 1},
    {"Solar-Radiation", 1088},
    {"CO2", 406},
    {"Air-Pressure", 1021},
    {"Illuminance", 239},
    {"Humidity", 79},
    {"Air-Pressure", 1026},
    {"Air-Pressure", 1048},
    {"Illuminance", 478},
    {"CO2", 438},
    {"Illuminance", 360},
    {"Accum.-Precip.", 0},
    {"Humidity", 93},
    {"Precipitation", 8},
    {"Accum.-Precip.", 13},
    {"Precipitation", 4},
    {"Dew-Point", -10},
    {"UV-Index", 4},
    {"Illuminance", 496},
    {"Solar-Radiation", 982},
    {"Wind-Speed", 18},
    {"Humidity", 92},
    {"Precipitation", 1},
    {"Wind-Direction", 18},
    {"Precipitation", 2},
    {"CO2", 416},
    {"Accum.-Precip.", 6},
    {"Solar-Radiation", 456},
    {"Accum.-Precip.", 9},
    {"Illuminance", 298},
    {"CO2", 436},
    {"UV-Index", 3},
    {"Wind-Direction", -98},
    {"Precipitation", 1},
    {"Accum.-Precip.", 10},
    {"UV-Index", 3},
    {"Solar-Radiation", 433},
    {"Illuminance", 119},
    {"Temperature", 28},
    {"CO2", 430},
    {"Solar-Radiation", 178},
    {"Solar-Radiation", 751},
};

size_t get_sensor_data_count() {
    return sizeof(sensor_data) / sizeof(sensor_data[0]);
}

char* get_sensor_name(size_t idx) {
    char* name = 0;
    if (idx < get_sensor_data_count()) {
        name = sensor_data[idx].sensor_name;
    }
    return name;
}

int get_sensor_value(size_t idx) {
    int value = 0;
    if (idx < get_sensor_data_count()) {
        value = sensor_data[idx].sensor_value;
    }
    return value;
}
