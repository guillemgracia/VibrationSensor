#include "Senscape.h"
#include "SensADC.h"
#include "SensVIBSENS.h"


SensVIBSENS::SensVIBSENS (inch, sref, ref2_5v, ssel, div, sht, sampcon_ssel, sampcon_id, mass){
	SensADC adc	= SensADC(
	    inch,
	    sref,
	    ref2_5V,
	    ssel,
	    div,
	    sht,
	    sampcon_ssel,
	    sampcon_id);

	_data.vib_data = 0;
	_data.vib_value = 0;
	_data.vib_altitude = 0;
	_calib.vib_mass = mass;
}

//Reads and transforms voltage from sensor to Hz
void readVIBSENS(void){
	adc.attachCallback(onDataReady);
	adc.read();
}


boolean SensVIBSENS::onDataReady(uint16_t data, error_t result){
	_data.vib_data = data;
	/*vib_value needs the value of gravity and number masses to transform
	data from volts to a Hz.*/
	// function of vibratoin frequency to determine
	_data.vib_value = NULL;

	return true;
}


boolean SensVIBSENS::getAltitude(void){

	_data.vib_altitude = altitude;
	return true;
}
