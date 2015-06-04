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

unsigned long lastTime = 0UL;
char publishString[40];

SYSTEM_MODE(AUTOMATIC);

/* This function is called once at start up ----------------------------------*/
void setup() {

}

/* This function loops forever --------------------------------------------*/
void loop() {
    //This will run in a loop
    unsigned long now = millis();
    //Every 15 seconds publish uptime
    if (now - lastTime > 15000UL) {
        lastTime = now;
        // now is in milliseconds
        unsigned nowSec = now / 1000UL;
        unsigned sec = nowSec % 60;
        unsigned min = (nowSec % 3600) / 60;
        unsigned hours = (nowSec % 86400) / 3600;
        sprintf(publishString, "%u:%u:%u", hours, min, sec);
        Spark.publish("Uptime", publishString);

    }
}

