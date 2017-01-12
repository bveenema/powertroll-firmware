#include "omni_button.h"

omni_button::omni_button()
{
  _btnState = !OMNI_BUTTON_TYPE;  // initial button state in active-high logic
  _lastState = _btnState;
  _clickCount = 0;
  _lastBounceTime = 0;
  clicks = 0;
  depressed = 0;

  // Turn on internal pullup resistor if applicable
  if (OMNI_BUTTON_TYPE == 0 && OMNI_BUTTON_PULLUP == 1)
    pinMode(OMNI_SW_PIN, INPUT_PULLUP);
  else
    pinMode(OMNI_SW_PIN, INPUT);
}



void omni_button::update()
{
  uint32_t now = (uint32_t)millis();      // get current time
  _btnState = digitalRead(OMNI_SW_PIN);  // current appearant button state

  // Make the button logic active-high in code
  if (!OMNI_BUTTON_TYPE) _btnState = !_btnState;

  // If the switch changed, due to noise or a button press, reset the debounce timer
  if (_btnState != _lastState) _lastBounceTime = now;


  // debounce the button (Check if a stable, changed state has occured)
  if (now - _lastBounceTime > DEBOUNCE_TIME && _btnState != depressed)
  {
    depressed = _btnState;
    if (depressed) _clickCount++;
  }

  // If the button released state is stable, report nr of clicks and start new cycle
  if (!depressed && (now - _lastBounceTime) > MULTICLICK_TIME)
  {
    // positive count for released buttons
    clicks = _clickCount;
    _clickCount = 0;
  }

  // Check for "long click"
  if (depressed && (now - _lastBounceTime > LONGPRESS_TIME))
  {
    // negative count for long clicks
    clicks = 0 - _clickCount;
    _clickCount = 0;
  }

  _lastState = _btnState;
}
