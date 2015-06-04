/**
 ******************************************************************************
 * @file    application.cpp
 * @authors  Satish Nair, Zachary Crockett and Mohit Bhoite
 * @version V1.0.0
 * @date    05-November-2013
 * @brief   Tinker application
 ******************************************************************************
  Copyright (c) 2013 Spark Labs, Inc.  All rights reserved.

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this program; if not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "application.h"

/* Function prototypes -------------------------------------------------------*/
int exchangeSet(String set);

SYSTEM_MODE(AUTOMATIC);

/* This function is called once at start up ----------------------------------*/
void setup() {
    //Setup the Tinker application here

    //Register all the Tinker functions
    Spark.function("Set", exchangeSet);

}

/* This function loops forever --------------------------------------------*/
void loop() {
    //This will run in a loop
}

/*******************************************************************************
 * Function Name  : exchangeSet
 * Description    : Sets all pins
 * Input          : String TRUE or FALSE to set all pins to that state 
 * Output         : None.
 * Return         : 0
 *******************************************************************************/
int exchangeSet(String set) {
    boolean state = false;
    
    if (set.startsWith("TRUE"))
        state = true;
    else
        state= false;
    
    
    
    for (int i = 0; i < 8; i++) {
        pinMode(i, INPUT_PULLDOWN);
        digitalWrite(i, state);
    }
    EEPROM.write(1, state);
    return 0;
}

