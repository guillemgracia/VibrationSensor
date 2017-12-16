#ifndef SENSCAPE_VIBSENS_H_
#define SENSCAPE_VIBSENS_H_

#include "Senscape.h"
#include "SensADC.h"

struct VIBSENS_data_t : sensor_data_t {
    int32_t vib_data;				//data from sensor
    int32_t vib_value;				//value usable value of data
    int32_t vib_altitude;			//altitude the rocket has in order to calculate gravity
};

struct VIBSENS_calib_t {
	int16_t vib_mass;				//number of masses of 0.26g
};

class SensVIBSENS : public SensorClient {
    private:
		static SensVIBSENS_data_t _data;
		static SensVIBSENS_calib_T _calib;
		static SensADC adc;

        // Process vibration data
        static boolean onDataReady(uint16_t data, error_t result);
        // get altitude
        static boolean getAltitude(void);

    public:
        //constructor
		SensVIBSENS (static uint16_t inch;
					static uint16_t sref,
					static uint16_t ref2_5v,
					static uint16_t ssel,
					static uint16_t div,
					static uint16_t sht,
					static uint16_t sampcon_ssel,
					static uint16_t sampcon_id);
        // Reads vibration data
        static void readVIBSENS(void);

};
#endif // SENSCAPE_VIBSENS_H_
