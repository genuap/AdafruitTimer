# AdafruitTimer
Timer for Adafruit STEAM robot challenge

### Written for  Adafruit CircuitPlayground hardware

Designed to be a timer for a STEAM robot challenge.
Once reset, left button must be pressed to start the timer.
Timer will loop LEDs around the Adafruit until the light sensor is covered
When light sensor is covered, the game is won, lights will blink in a pattern and the device will chirp

Must press reset button to reset

## ifdef timer
I have a complier ifdef to leave out a timer portion, which is optional.
If enabled, this will activate a ~2min timer. Once the timer is started the LEDs 
will loop around the Adafruit as prior. However, with timer enabled, each loop will become
progressively faster, until time is up. At which point the device will blink a red and yellow
pattern and the device will chirp.

To win, light sensor must be covered prior to timer expiring

