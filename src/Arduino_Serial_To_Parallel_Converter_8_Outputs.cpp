#include "Arduino_Serial_To_Parallel_Converter_8_Outputs.h"



/**************************************************************************************************/
/* Constructor */
Arduino_Serial_To_Parallel_Converter_8_Outputs::Arduino_Serial_To_Parallel_Converter_8_Outputs(
	uint8_t serial_data_pin_id,
	uint8_t clock_pin_id,
	uint8_t latch_pin_id )
{
	Parallel_Output[0] = Provider_Port( 0x01, this );
	Parallel_Output[1] = Provider_Port( 0x02, this );
	Parallel_Output[2] = Provider_Port( 0x04, this );
	Parallel_Output[3] = Provider_Port( 0x08, this );
	Parallel_Output[4] = Provider_Port( 0x10, this );
	Parallel_Output[5] = Provider_Port( 0x20, this );
	Parallel_Output[6] = Provider_Port( 0x40, this );
	Parallel_Output[7] = Provider_Port( 0x80, this );

	/* Set Component_Attribute */
	this->Serial_Data_Pin_Id = serial_data_pin_id;
	this->Clock_Pin_Id = clock_pin_id;
	this->Latch_Pin_Id = latch_pin_id;
	
	/* Configure Arduino board */
	pinMode( this->Serial_Data_Pin_Id, OUTPUT );
	pinMode( this->Clock_Pin_Id, OUTPUT );
	pinMode( this->Latch_Pin_Id, OUTPUT );
	
	/* Switch off all outputs */
	this->Output_Pin_State = 0; 
	Update_Outputs();
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Component_Type_Operations */
/**************************************************************************************************/
void Arduino_Serial_To_Parallel_Converter_8_Outputs::Update_Outputs( void )
{
	digitalWrite(this->Latch_Pin_Id, LOW);
	for(int i = 7; i >=  0; i--)
	{
		digitalWrite(this->Clock_Pin_Id, LOW);

		uint8_t pinValue = ((this->Output_Pin_State) & (this->Parallel_Output[i].Bitmask));

		digitalWrite(this->Serial_Data_Pin_Id, pinValue);
		digitalWrite(this->Clock_Pin_Id, HIGH);
	}
	digitalWrite(this->Latch_Pin_Id, HIGH);
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Event reception points accessors */
/**************************************************************************************************/


/**************************************************************************************************/
/* Provided port accessors */
/**************************************************************************************************/
i_Discrete_Output* Arduino_Serial_To_Parallel_Converter_8_Outputs::Get_Port__Parallel_Output_1(void)
{
	return (i_Discrete_Output*)&(this->Parallel_Output[0]);
}
/*------------------------------------------------------------------------------------------------*/
i_Discrete_Output* Arduino_Serial_To_Parallel_Converter_8_Outputs::Get_Port__Parallel_Output_2(void)
{
	return (i_Discrete_Output*)&(this->Parallel_Output[1]);
}
/*------------------------------------------------------------------------------------------------*/
i_Discrete_Output* Arduino_Serial_To_Parallel_Converter_8_Outputs::Get_Port__Parallel_Output_3(void)
{
	return (i_Discrete_Output*)&(this->Parallel_Output[2]);
}
/*------------------------------------------------------------------------------------------------*/
i_Discrete_Output* Arduino_Serial_To_Parallel_Converter_8_Outputs::Get_Port__Parallel_Output_4(void)
{
	return (i_Discrete_Output*)&(this->Parallel_Output[3]);
}
/*------------------------------------------------------------------------------------------------*/
i_Discrete_Output* Arduino_Serial_To_Parallel_Converter_8_Outputs::Get_Port__Parallel_Output_5(void)
{
	return (i_Discrete_Output*)&(this->Parallel_Output[4]);
}
/*------------------------------------------------------------------------------------------------*/
i_Discrete_Output* Arduino_Serial_To_Parallel_Converter_8_Outputs::Get_Port__Parallel_Output_6(void)
{
	return (i_Discrete_Output*)&(this->Parallel_Output[5]);
}
/*------------------------------------------------------------------------------------------------*/
i_Discrete_Output* Arduino_Serial_To_Parallel_Converter_8_Outputs::Get_Port__Parallel_Output_7(void)
{
	return (i_Discrete_Output*)&(this->Parallel_Output[6]);
}
/*------------------------------------------------------------------------------------------------*/
i_Discrete_Output* Arduino_Serial_To_Parallel_Converter_8_Outputs::Get_Port__Parallel_Output_8(void)
{
	return (i_Discrete_Output*)&(this->Parallel_Output[7]);
}
/**************************************************************************************************/



/**************************************************************************************************/
/* Private methods */
/**************************************************************************************************/


/**************************************************************************************************/
/* Provided operations */
/**************************************************************************************************/
Arduino_Serial_To_Parallel_Converter_8_Outputs::Provider_Port::Provider_Port( 
	uint8_t bitmask, 
	Arduino_Serial_To_Parallel_Converter_8_Outputs* parent )
{
    this->Bitmask = bitmask;
    this->Parent = parent;
}
/*------------------------------------------------------------------------------------------------*/
void Arduino_Serial_To_Parallel_Converter_8_Outputs::Provider_Port::Set_Level( 
	E_IO_LEVEL level )
{
	if( level == IO_LEVEL_HIGH )
	{
		((this->Parent)->Output_Pin_State) |= (this->Bitmask);
	}
	else if( level == IO_LEVEL_LOW )
	{
		((this->Parent)->Output_Pin_State) &= ~(this->Bitmask);
	}
}
/**************************************************************************************************/


/**************************************************************************************************/
/* Received events */
/**************************************************************************************************/