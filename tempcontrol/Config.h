#ifndef _CONFIG_H_
#define _CONFIG_H_

const int CONFIG_MODE_NONE = 0;
const int CONFIG_MODE_TARGET = 1;
const int CONFIG_MODE_ACTIVE = 2;

class Config {
public:
  Config(float target, float offset, bool active)
    : target(target), offset(offset), active(active), mode(0) {};

  int increseMode() {
    mode++;
    if (mode > CONFIG_MODE_ACTIVE);
      mode = CONFIG_MODE_NONE;

    return mode;
  }

  float target;
  float offset;
  bool active;
  int mode;
};

#endif /* _CONFIG_H_ */
