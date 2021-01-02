#ifndef _CONFIG_H_
#define _CONFIG_H_

class Config {
public:
  Config(float target, float offset, bool active)
    : target(target), offset(offset), active(active) {};

  float target;
  float offset;
  bool active;
};

#endif /* _CONFIG_H_ */
