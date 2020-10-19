/** 
 * @file        TLE5012-platf-ino.hpp
 * @brief       TLE5012 Arduino Hardware Platforms
 * @date        October 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE5012_PLATF_INO_HPP_
#define TLE5012_PLATF_INO_HPP_

#include "../../../config/tle5012-conf.hpp"

#if (TLE5012_FRAMEWORK == TLE5012_FRMWK_ARDUINO)

#include "../pal/TLE5012-pal-ino.hpp"

#define SENS_TYPE TLE5012_Sens2Go

/**
 * @class Tle5012Ino
 *
 * @brief represents the TLE5012 base class
 *
 * This class provides a simple API for connecting the TLE5012 via SSC interface,
 * which is included into all flavours the TLE5012 sensor. This setup also
 * works with the Sens2Kit (Sensor including XMC1100 mcu), breakout board (only the Sensor
 * from the Sens2Kit) and bulk chip (read the section on who to connect the bulk chip via 3wire SPI).
 *
 * @addtogroup tle5012inohw
 * @{
 */

/**
 * @brief Arduino Hardware Platform Pins
 */
typedef struct {
	uint8_t power;      //!< Switch on/off power pin */
	uint8_t csPin;      //!< chipselect pin for first sensor */
	uint8_t mMOSI;      //!< Pin for SPI MOSI (pin 0.6 on test board);
	uint8_t mMISO;      //!< Pin for SPI MISO (pin 0.7 on test board)
	uint8_t mSCK;       //!< Pin for CLOCK (pin 0.8 on test board)
}sensType_t;

extern sensType_t TLE5012_Sens2Go;     //!< TLE5012 Sensor2Go Kit with XMC1100 */
extern sensType_t TLE5012_breakOut;    //!< TLE5012 breakout board removed from the Sensor2Go Kit */
extern sensType_t TLE5012_bulk;        //!< TLE5012 bulk chip (se manual on how to connect the 3wire SPI */

class Tle5012Ino: virtual public TLE5012Ino
{

	public:

		uint8_t mSpiNum = 0;          //!< Number of used SPI channel

		Tle5012Ino(void);
		Tle5012Ino(SPIClass &bus);
		Tle5012Ino(SPIClass &bus, uint8_t misoPin, uint8_t mosiPin, uint8_t sckPin);
		errorTypes begin();
		errorTypes begin(uint8_t csPin, slaveNum slave=TLE5012B_S0);

};

/** @} */

#endif /** TLE5012_SWITCH_FRAMEWORK **/
#endif /** TLE5012_PLATF_INO_HPP_ **/