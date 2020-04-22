#include "Main.h"
#include "Component_PinOutDigital.h"
#include "Component_ProximityCheck.h"
#include "Component_LedDisplay8.h"
#include "Component_Button.h"
#include "Lib_Timer.h"
#include "Lib_Interval.h"

void Main::setup() {
}

/* **************************************************************************** */

// LedDisplay8 disp(11, 10, 9, 8, 7, 6, 5, 4);
// Button btnAdd(2);
// Button btnMin(3);
// byte num = 0;

// void Main::loop() {
//  if (btnAdd.isClicked()) {
//    num++;
//  }

//  if (btnMin.isClicked()) {
//    num--;
//  }

//  disp.set(num);
// }

/* **************************************************************************** */

// PinOutDigital ledState(13);
// PinOutDigital ledErr(12);
// ProximityCheck pc(2, A0);
// Button btn(3);

// void Main::loop() {
//  if (btn.isClicked()) {
//    ledErr.off();
//    pc.calibrate();
//  } else {
//    switch (pc.getState()) {
//      case ProximityCheckState::PROXIMITY:
//        ledErr.off();
//        ledState.on();
//        break;
//      case ProximityCheckState::NO_PROXIMITY:
//        ledErr.off();
//        ledState.off();
//        break;
//      case ProximityCheckState::ERROR_FIRST_CHECK:
//        ledState.off();
//        ledErr.on();
//        break;
//    }
//  }
// }

/* **************************************************************************** */

// PinOutDigital ledState(2);
// PinOutDigital ledErr(3);
// Button btn(5);

// void Main::setup() {
//   ledErr.flash(500, 10);
//   ledState.flash(500, 0);
// }

// void Main::loop() {
//   if (ledState.isFlashing()) {
//     ledErr.on();
//   } else {
//     ledErr.off();
//   }
// }

/* **************************************************************************** */

// PinOutDigital led(13);
// PinOutDigital led2(4);

// void Main::setup() {
//   led.flash(500, 5);
// }

// void Main::loop() {
//   if (!led.isFlashing()) {
//     led2.on();
//   }
// }

/* **************************************************************************** */

// PinOutDigital l1(9);
// PinOutDigital l2(10);
// PinOutDigital l3(11);
// PinOutDigital l4(LED_BUILTIN);
// Button btn(2);

// void Main::loop() {
//   if (btn.isClicked()) {
//     l1.invert();
//   }

//   if (btn.isLongClick()) {
//     l2.invert();
//   }

//   if (btn.isShortClick()) {
//     l3.invert();
//   }

//   if (btn.isDown()) {
//     l4.on();
//   } else {
//     l4.off();
//   }
// }

/* **************************************************************************** */

// PinOutDigital l1(9);
// PinOutDigital l2(10);
// PinOutDigital l3(11);
// Timer timer(5000);
// Button btn(2);

// void Main::loop() {
//   if (timer.onFinish()) {
//     l1.on();
//   }

//   if (timer.isFinished()) {
//     l3.flashStop();

//     if (!l2.isFlashing()) {
//       l2.flash(100);
//     }
//   } else {
//     l2.flashStop();

//     if (!l3.isFlashing()) {
//       l3.flash(500);
//     }
//   }

//   if (btn.isClicked()) {
//     timer.start();
//   }
// }

/* **************************************************************************** */


PinOutDigital l1(9);
PinOutDigital l2(10);
PinOutDigital l3(11);
Interval interval(500);
Button btn(2);

void Main::loop() {
  if (interval.onStep()) {
    l1.invert();
  }

  if (btn.isClicked()) {
    if (interval.isRunning()) {
      interval.stop();
      l3.flash(100, 2);
      l2.off();
    } else {
      interval.start();
      l2.flash(100, 1);
      l3.off();
    }
  }
}

/* **************************************************************************** */
