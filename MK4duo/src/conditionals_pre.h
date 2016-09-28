/**
 * MK4duo 3D Printer Firmware
 *
 * Based on Marlin, Sprinter and grbl
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 * Copyright (C) 2013 - 2016 Alberto Cotronei @MagoKimbra
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * conditionals_pre.h
 * Defines that depend on configuration but are not editable.
 */

#ifndef CONDITIONALS_PRE_H
#define CONDITIONALS_PRE_H

#ifndef CONFIGURATION_LCD // Get the LCD defines which are needed first
  #define CONFIGURATION_LCD

  #define LCD_HAS_DIRECTIONAL_BUTTONS (BUTTON_EXISTS(UP) || BUTTON_EXISTS(DWN) || BUTTON_EXISTS(LFT) || BUTTON_EXISTS(RT))

  #if ENABLED(CARTESIO_UI)
    #define DOGLCD
    #define ULTIPANEL
    #define NEWPANEL
    #define DEFAULT_LCD_CONTRAST 90
    #define LCD_CONTRAST_MIN 60
    #define LCD_CONTRAST_MAX 140
  #endif

  #if ENABLED(MAKRPANEL) || ENABLED(MINIPANEL)
    #define DOGLCD
    #define DEFAULT_LCD_CONTRAST 17
    #define ULTIPANEL
    #define NEWPANEL
  #endif

  #if ENABLED(miniVIKI) || ENABLED(VIKI2) || ENABLED(ELB_FULL_GRAPHIC_CONTROLLER)
    #define ULTRA_LCD // general LCD support, also 16x2
    #define DOGLCD    // Support for SPI LCD 128x64 (Controller ST7565R graphic Display Family)
    #define ULTIMAKERCONTROLLER // as available from the Ultimaker online store.

    #if ENABLED(miniVIKI)
      #define LCD_CONTRAST_MIN  75
      #define LCD_CONTRAST_MAX 115
      #define DEFAULT_LCD_CONTRAST 95
    #elif ENABLED(VIKI2)
      #define DEFAULT_LCD_CONTRAST 40
    #elif ENABLED(ELB_FULL_GRAPHIC_CONTROLLER)
      #define LCD_CONTRAST_MIN  90
      #define LCD_CONTRAST_MAX 130
      #define DEFAULT_LCD_CONTRAST 110
      #define U8GLIB_LM6059_AF
      #define SD_DETECT_INVERTED
    #endif

    #ifndef ENCODER_PULSES_PER_STEP
      #define ENCODER_PULSES_PER_STEP 4
    #endif
    #ifndef ENCODER_STEPS_PER_MENU_ITEM
      #define ENCODER_STEPS_PER_MENU_ITEM 1
    #endif
  #endif

  // Generic support for SSD1306 OLED based LCDs.
  #if ENABLED(U8GLIB_SSD1306) || ENABLED(U8GLIB_SH1106)
    #define ULTRA_LCD  //general LCD support, also 16x2
    #define DOGLCD  // Support for I2C LCD 128x64 (Controller SSD1306 graphic Display Family)
  #endif

  #if ENABLED(PANEL_ONE) || ENABLED(U8GLIB_SH1106)
    #define ULTIMAKERCONTROLLER
  #endif

  #if ENABLED(BQ_LCD_SMART_CONTROLLER)
    #define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

    #if DISABLED(ENCODER_PULSES_PER_STEP)
      #define ENCODER_PULSES_PER_STEP 4
    #endif

    #if DISABLED(ENCODER_STEPS_PER_MENU_ITEM)
      #define ENCODER_STEPS_PER_MENU_ITEM 1
    #endif

    #if DISABLED(LONG_FILENAME_HOST_SUPPORT)
      #define LONG_FILENAME_HOST_SUPPORT
    #endif
  #endif

  #if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
    #define DOGLCD
    #define U8GLIB_ST7920
    #define REPRAP_DISCOUNT_SMART_CONTROLLER
  #endif

  #if ENABLED(ULTIMAKERCONTROLLER)              \
   || ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER) \
   || ENABLED(G3D_PANEL)                        \
   || ENABLED(RIGIDBOT_PANEL)                   \
   || ENABLED(REPRAPWORLD_KEYPAD)
    #define ULTIPANEL
    #define NEWPANEL
  #endif

  #if ENABLED(REPRAPWORLD_GRAPHICAL_LCD)
    #define DOGLCD
    #define U8GLIB_ST7920
    #define ULTIPANEL
    #define NEWPANEL
  #endif

  #if ENABLED(SPARK_FULL_GRAPHICS)
    #define ENCODER_PULSES_PER_STEP 2
    #define ENCODER_STEPS_PER_MENU_ITEM 1

    #define DOGLCD
    #define U8GLIB_ST7920
    #define REPRAP_DISCOUNT_SMART_CONTROLLER
  #endif

  #if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)
    #if DISABLED(SDSUPPORT)
      #define SDSUPPORT
    #endif
  #endif

  #if ENABLED(RADDS_DISPLAY)
    #define ENCODER_PULSES_PER_STEP 2
    #define ENCODER_STEPS_PER_MENU_ITEM 1
    #define ULTIPANEL
    #define NEWPANEL
  #endif

  #if ENABLED(RA_CONTROL_PANEL)
    #define LCD_I2C_TYPE_PCA8574
    #define LCD_I2C_ADDRESS 0x27   // I2C Address of the port expander
    #define ULTIPANEL
    #define NEWPANEL
  #endif

  #if ENABLED(MINIPANEL)
   #define DOGLCD
   #define ULTIPANEL
   #define NEWPANEL
   #define DEFAULT_LCD_CONTRAST 17
  #endif

  /**
   * I2C PANELS
   */
  #if ENABLED(LCD_I2C_SAINSMART_YWROBOT)
    // This uses the LiquidCrystal_I2C library ( https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home )
    // Make sure it is placed in the Arduino libraries directory.
    #define LCD_I2C_TYPE_PCF8575
    #define LCD_I2C_ADDRESS 0x27   // I2C Address of the port expander
    #define ULTIPANEL
    #define NEWPANEL
  #endif

  // PANELOLU2 LCD with status LEDs, separate encoder and click inputs
  #if ENABLED(LCD_I2C_PANELOLU2)
    #define LCD_I2C_TYPE_MCP23017
    #define LCD_I2C_ADDRESS 0x20 // I2C Address of the port expander
    #define LCD_USE_I2C_BUZZER //comment out to disable buzzer on LCD

    #if DISABLED(ENCODER_PULSES_PER_STEP)
      #define ENCODER_PULSES_PER_STEP 4
    #endif
    #if DISABLED(ENCODER_STEPS_PER_MENU_ITEM)
      #define ENCODER_STEPS_PER_MENU_ITEM 1
    #endif

    #if ENABLED(LCD_USE_I2C_BUZZER)
      #define LCD_FEEDBACK_FREQUENCY_HZ 1000
      #define LCD_FEEDBACK_FREQUENCY_DURATION_MS 100
    #endif

    #define ULTIPANEL
    #define NEWPANEL
  #endif

  // Panucatt VIKI LCD with status LEDs, integrated click & L/R/U/P buttons, separate encoder inputs
  #if ENABLED(LCD_I2C_VIKI)
    // This uses the LiquidTWI2 library v1.2.3 or later ( https://github.com/lincomatic/LiquidTWI2 )
    // Make sure the LiquidTWI2 directory is placed in the Arduino or Sketchbook libraries subdirectory.
    // Note: The pause/stop/resume LCD button pin should be connected to the Arduino
    //       BTN_ENC pin (or set BTN_ENC to -1 if not used)
    #define LCD_I2C_TYPE_MCP23017
    #define LCD_I2C_ADDRESS 0x20 // I2C Address of the port expander
    #define LCD_USE_I2C_BUZZER //comment out to disable buzzer on LCD (requires LiquidTWI2 v1.2.3 or later)
    #define ULTIPANEL
    #define NEWPANEL
  #endif

  // Shift register panels
  // ---------------------
  // 2 wire Non-latching LCD SR from:
  // https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/schematics#!shiftregister-connection

  #if ENABLED(SAV_3DLCD)
     #define SR_LCD_2W_NL    // Non latching 2 wire shiftregister
     #define ULTIPANEL
     #define NEWPANEL
  #endif

  #if ENABLED(DOGLCD) // Change number of lines to match the DOG graphic display
    #if DISABLED(LCD_WIDTH)
      #define LCD_WIDTH 22
    #endif
    #if DISABLED(LCD_HEIGHT)
      #define LCD_HEIGHT 5
    #endif
  #endif

  #if ENABLED(ULTIPANEL)
    #define NEWPANEL  // enable this if you have a click-encoder panel
    #define ULTRA_LCD
    #if DISABLED(LCD_WIDTH)
      #define LCD_WIDTH 20
    #endif
    #if DISABLED(LCD_HEIGHT)
      #define LCD_HEIGHT 4
    #endif
  #else //no panel but just LCD
    #if ENABLED(ULTRA_LCD)
      #if DISABLED(LCD_WIDTH)
        #define LCD_WIDTH 16
      #endif
      #if DISABLED(LCD_HEIGHT)
        #define LCD_HEIGHT 2
      #endif
    #endif
  #endif

  #if ENABLED(DOGLCD)
    /* Custom characters defined in font font_6x10_marlin_symbols */
    // \x00 intentionally skipped to avoid problems in strings
    #define LCD_STR_REFRESH     "\x01"
    #define LCD_STR_FOLDER      "\x02"
    #define LCD_STR_ARROW_RIGHT "\x03"
    #define LCD_STR_UPLEVEL     "\x04"
    #define LCD_STR_CLOCK       "\x05"
    #define LCD_STR_FEEDRATE    "\x06"
    #define LCD_STR_BEDTEMP     "\x07"
    #define LCD_STR_THERMOMETER "\x08"
    #define LCD_STR_DEGREE      "\x09"

    #define LCD_STR_SPECIAL_MAX '\x09'
    // Maximum here is 0x1f because 0x20 is ' ' (space) and the normal charsets begin.
    // Better stay below 0x10 because DISPLAY_CHARSET_HD44780_WESTERN begins here.
  #else
    /* Custom characters defined in the first 8 characters of the LCD */
    #define LCD_STR_BEDTEMP     "\x00"  // this will have 'unexpected' results when used in a string!
    #define LCD_STR_DEGREE      "\x01"
    #define LCD_STR_THERMOMETER "\x02"
    #define LCD_STR_UPLEVEL     "\x03"
    #define LCD_STR_REFRESH     "\x04"
    #define LCD_STR_FOLDER      "\x05"
    #define LCD_STR_FEEDRATE    "\x06"
    #define LCD_STR_CLOCK       "\x07"
    #define LCD_STR_ARROW_RIGHT ">"  /* from the default character set */
  #endif

  /**
   * Default LCD contrast for dogm-like LCD displays
   */
  #if ENABLED(DOGLCD)

    #define HAS_LCD_CONTRAST ( \
        ENABLED(MAKRPANEL) \
     || ENABLED(CARTESIO_UI) \
     || ENABLED(VIKI2) \
     || ENABLED(miniVIKI) \
     || ENABLED(ELB_FULL_GRAPHIC_CONTROLLER) \
    )

    #if HAS_LCD_CONTRAST
      #ifndef LCD_CONTRAST_MIN
        #define LCD_CONTRAST_MIN 0
      #endif
      #ifndef LCD_CONTRAST_MAX
        #define LCD_CONTRAST_MAX 63
      #endif
      #ifndef DEFAULT_LCD_CONTRAST
        #define DEFAULT_LCD_CONTRAST 32
      #endif
    #endif
  #else
    #define HAS_LCD_CONTRAST false
  #endif

#endif // CONFIGURATION_LCD

/**
 * The BLTouch Probe emulates a servo probe
 */
#if ENABLED(BLTOUCH)
  #if DISABLED(ENABLE_SERVOS)
    #define ENABLE_SERVOS
  #endif
  #if Z_ENDSTOP_SERVO_NR < 0
    #undef Z_ENDSTOP_SERVO_NR
    #define Z_ENDSTOP_SERVO_NR 0
  #endif
  #if NUM_SERVOS < 1
    #undef NUM_SERVOS
    #define NUM_SERVOS (Z_ENDSTOP_SERVO_NR + 1)
  #endif
  #undef DEACTIVATE_SERVOS_AFTER_MOVE
  #undef SERVO_DEACTIVATION_DELAY
  #define SERVO_DEACTIVATION_DELAY 50
  #undef Z_ENDSTOP_SERVO_ANGLES
  #define Z_ENDSTOP_SERVO_ANGLES { BLTOUCH_DEPLOY, BLTOUCH_STOW }

  #define BLTOUCH_DEPLOY    10
  #define BLTOUCH_STOW      90
  #define BLTOUCH_SELFTEST 120
  #define BLTOUCH_RESET    160
  #define _TEST_BLTOUCH(P) (READ(P##_PIN) != P##_ENDSTOP_INVERTING)
#endif

#endif // CONDITIONALS_PRE_H