#ifndef PLUGINSTRUCTS_P038_DATA_STRUCT_H
#define PLUGINSTRUCTS_P038_DATA_STRUCT_H

#include "../../_Plugin_Helper.h"
#ifdef USES_P038

# include <NeoPixelBus_wrapper.h>

// # define P038_DEBUG_LOG // Enable for some (extra) logging

# define P038_CONFIG_LEDCOUNT   PCONFIG(0)
# define P038_CONFIG_STRIPTYPE  PCONFIG(1)
# define P038_CONFIG_BRIGHTNESS PCONFIG(2)
# define P038_CONFIG_MAXBRIGHT  PCONFIG(3)

# define P038_STRIP_TYPE_RGB   1
# define P038_STRIP_TYPE_RGBW  2

# ifndef P038_FEATURE_NEOPIXELFOR
#  ifdef ESP32
#   define P038_FEATURE_NEOPIXELFOR  1
#  else // ifdef ESP32
#   define P038_FEATURE_NEOPIXELFOR  0
#  endif // ifdef ESP32
# endif // ifndef P038_FEATURE_NEOPIXELFOR

struct P038_data_struct : public PluginTaskData_base {
public:

  P038_data_struct(int8_t   gpioPin,
                   uint16_t ledCount,
                   uint8_t  stripType,
                   uint8_t  brightness,
                   uint8_t  maxbright);

  P038_data_struct() = delete;
  virtual ~P038_data_struct();

  bool plugin_init(struct EventStruct *event);
  bool plugin_exit(struct EventStruct *event);
  bool plugin_write(struct EventStruct *event,
                    const String      & string);

  bool isInitialized() {
    return Plugin_038_pixels != nullptr;
  }

private:

  NeoPixelBus_wrapper *Plugin_038_pixels = nullptr;

  void HSV2RGBWorRGBandLog(float H,
                           float S,
                           float V,
                           int   rgbw[4]);

  int8_t   _gpioPin;
  uint16_t _maxPixels;
  uint8_t  _stripType;
  uint8_t  _brightness;
  uint8_t  _maxbright;
};
#endif // ifdef USES_P038
#endif // ifndef PLUGINSTRUCTS_P038_DATA_STRUCT_H
