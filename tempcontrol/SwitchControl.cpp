
#include "SwitchControl.h"

SwitchControl::SwitchControl() {
  currentTemperature_ = 0;
  targetTemperature_ = 0;
  offset_ = 0;
  switchActive_ = false;
  switchStatus_ = false;
  switchPrevious_ = false;
}

SwitchControl::~SwitchControl() {
}

bool SwitchControl::update() {
  if (switchActive_) {
    if (currentTemperature_ > targetTemperature_) {
      switchStatus_ = true;
    }
    else if (currentTemperature_ < targetTemperature_ - offset_) {
      switchStatus_ = false;
    }
  }
  else {
    if (currentTemperature_ < targetTemperature_) {
      switchStatus_ = true;
    }
    else if (currentTemperature_ > targetTemperature_ + offset_) {
      switchStatus_ = false;
    }
  }
  return switchStatus_;
}

bool SwitchControl::update(float temperature) {
  setTemperature(temperature);
  return update();
}

void SwitchControl::setConfig(Config conf) {
  targetTemperature_ = conf.target;
  offset_ = conf.offset;
  switchActive_ = conf.active;
}

void SwitchControl::setTemperature(float temperature) {
  currentTemperature_ = temperature;
}

bool SwitchControl::getSwitchStatus() {
  return switchStatus_;
}
