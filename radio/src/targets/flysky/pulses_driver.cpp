/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "opentx.h"

void intmoduleStop(void);
void extmoduleStop(void);

void intmoduleNoneStart(void);
void intmoduleAfhds2aStart(void);

void extmodulePpmStart(void);
void extmodulePxxStart(void);
void extmoduleCrossfireStart(void);
void extmoduleTimerStart(uint32_t period, uint8_t state);

void init_afhds2a(uint32_t port) {
  TRACE("init_afhds2a");
  if (port == INTERNAL_MODULE) {
    intmoduleAfhds2aStart();
  }
}

void disable_afhds2a(uint32_t port) {
  TRACE("disable_afhds2a");
  if (port == INTERNAL_MODULE){
    intmoduleStop();
  }
}

void init_ppm(uint32_t port) {
  if (port == EXTERNAL_MODULE) {
    extmodulePpmStart();
  }
}

void disable_ppm(uint32_t port) {
  if (port == EXTERNAL_MODULE) {
    extmoduleStop();
  }
}

void init_no_pulses(uint32_t port) {
  if (port == INTERNAL_MODULE){
    intmoduleNoneStart();
  }    
}

void disable_no_pulses(uint32_t port) {
  if (port == INTERNAL_MODULE)
    intmoduleStop();
  else
    extmoduleStop();
}

void init_sbusOut(uint32_t module_index) {}
void disable_sbusOut(uint32_t module_index){}
void setupPulsesSbus(uint8_t port){}

void init_serial(uint32_t port, uint32_t baudrate, uint32_t period_half_us) {
}

void disable_serial(uint32_t port) {
}

void init_module_timer(uint32_t port, uint32_t period, uint8_t state)
{
  if (port == EXTERNAL_MODULE) {
    extmoduleTimerStart(period, state);
  }
}

void disable_module_timer(uint32_t port)
{
  if (port == EXTERNAL_MODULE) {
    extmoduleStop();
  }
}
