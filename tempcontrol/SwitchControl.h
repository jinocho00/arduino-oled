#ifndef _SWITCH_CONTROl_TEMPCONTROL_H_
#define _SWITCH_CONTROl_TEMPCONTROL_H_

#include "Config.h"

class SwitchControl {
public:
  SwitchControl();
  ~SwitchControl();
  bool update();
  bool update(float temperature);
  void setConfig(Config conf);
  void setTemperature(float temperature);
  bool getSwitchStatus();

  float currentTemperature_;
  float targetTemperature_;
  float offset_;
  bool switchActive_;
  bool switchStatus_;
  bool switchPrevious_;
};

#endif /* _SWITCH_CONTROl_TEMPCONTROL_H_ */
