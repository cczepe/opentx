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

#if defined(RADIO_TOOLS)
void addRadioTool(uint8_t index, const char * label, void (* tool)(event_t event), event_t event)
{
  int8_t sub = menuVerticalPosition - HEADER_LINE;
  LcdFlags attr = (sub == index ? INVERS : 0);
  coord_t y = MENU_HEADER_HEIGHT + 1 + index * FH;
  lcdDrawNumber(3, y, index + 1, LEADING0|LEFT, 2);
  lcdDrawText(3*FW, y, label, (sub == index ? INVERS  : 0));
  if (attr && s_editMode > 0) {
    s_editMode = 0;
    pushMenu(tool);
  }
}

void ELRSV3_run(event_t event);
void hello_run(event_t event);
void pilot_run(event_t event);


void menuRadioTools(event_t event)
{
  uint8_t index = 0;

#if defined(PCBI6X_ELRSV3)
  addRadioTool(index++, "ExpressLRS", ELRSV3_run, event);
#endif

#if defined(PCBI6X_HELLO)
  addRadioTool(index++, "Hello World", hello_run, event);
#endif

#if defined(PCBI6X_PILOT)
  addRadioTool(index++, "Pilot", pilot_run, event);
#endif

  SIMPLE_MENU("TOOLS", menuTabGeneral, MENU_RADIO_TOOLS, HEADER_LINE + index);
}
#endif // RADIO_TOOLS
