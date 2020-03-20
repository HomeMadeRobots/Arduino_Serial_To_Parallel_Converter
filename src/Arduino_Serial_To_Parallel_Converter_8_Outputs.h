#ifndef ARDUINO_SERIAL_TO_PARALLEL_CONVERTER_8_OUTPUTS_H
#define ARDUINO_SERIAL_TO_PARALLEL_CONVERTER_8_OUTPUTS_H


/* Attributes */
#include <stdint.h>
#include "Arduino.h"

/* Realized interfaces */
#include "i_Discrete_Output.h"

/* Needed interfaces */


/* Events */


/* Component_Type */
class Arduino_Serial_To_Parallel_Converter_8_Outputs {
public :
    /*--------------------------------------------------------------------------------------------*/
    /* Constructor */
    Arduino_Serial_To_Parallel_Converter_8_Outputs(
		uint8_t serial_data_pin_id,
		uint8_t clock_pin_id,
		uint8_t latch_pin_id );

    /*--------------------------------------------------------------------------------------------*/
    /* Component_Type_Operations */
	void Update_Outputs( void );

    /*--------------------------------------------------------------------------------------------*/
    /* Event reception points accessors */

    /*--------------------------------------------------------------------------------------------*/
    /* Provided port accessors */
	i_Discrete_Output* Get_Port__Parallel_Output_1( void );
	i_Discrete_Output* Get_Port__Parallel_Output_2( void );
	i_Discrete_Output* Get_Port__Parallel_Output_3( void );
	i_Discrete_Output* Get_Port__Parallel_Output_4( void );
	i_Discrete_Output* Get_Port__Parallel_Output_5( void );
	i_Discrete_Output* Get_Port__Parallel_Output_6( void );
	i_Discrete_Output* Get_Port__Parallel_Output_7( void );
	i_Discrete_Output* Get_Port__Parallel_Output_8( void );

	/*--------------------------------------------------------------------------------------------*/
    /* Provided operations */
	
private :
    /*--------------------------------------------------------------------------------------------*/
    /* Private attributes */
	uint8_t Serial_Data_Pin_Id;
	uint8_t Clock_Pin_Id;
	uint8_t Latch_Pin_Id;
	/* Bit carrier representing the required hardware outputs state.
	MSB represent output 8, LSB represent output 1.
	Bit value = 1 stands for IO_LEVEL_HIGH, bit value = 0 stands for IO_LEVEL_LOW.*/
	uint8_t Output_Pin_State; 
	
    /*--------------------------------------------------------------------------------------------*/
    /* Private methods */

    /*--------------------------------------------------------------------------------------------*/
    /* Requirer_Ports */

    /*--------------------------------------------------------------------------------------------*/
    /* Provider ports */
	class Provider_Port : i_Discrete_Output {
	public :
		Provider_Port() {}
		Provider_Port( 
			uint8_t bitmask, 
			Arduino_Serial_To_Parallel_Converter_8_Outputs* parent ) ;

		void Set_Level( E_IO_LEVEL level ) override;

	//private :
		uint8_t Bitmask;
		Arduino_Serial_To_Parallel_Converter_8_Outputs* Parent;
		
	};
	Provider_Port Parallel_Output[8];

    /*--------------------------------------------------------------------------------------------*/
    /* Sent events */

    /*--------------------------------------------------------------------------------------------*/
    /* Received events */
};

#endif