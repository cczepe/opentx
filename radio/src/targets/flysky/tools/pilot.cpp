/**
 * Show the name of the pilot.
 *
 */
#include "opentx.h"

void pilot_draw() {
  lcdDrawText(FW, FH, "Pilot", BOLD);
  lcdDrawText(FW, FH + 10, "Name: ", SMLSIZE);
  lcdDrawText(lcdLastRightPos, FH + 10, "Clemens Czepe", SMLSIZE);
}

void pilot_stop() {
  if (globalData.cToolRunning) {
    globalData.cToolRunning = 0;
    popMenu();
  }
}

void pilot_run(event_t event) {
  if (globalData.cToolRunning == 0) {
    globalData.cToolRunning = 1;
  }

  if (event == EVT_KEY_LONG(KEY_EXIT)) { // exit on LONG press CANCEL
    pilot_stop();
  }

  // run every frame
  lcdClear();
  pilot_draw();
}
