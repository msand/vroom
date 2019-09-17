#ifndef STEP_H
#define STEP_H

/*

This file is part of VROOM.

Copyright (c) 2015-2019, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "structures/vroom/job.h"
#include "structures/vroom/location.h"

namespace vroom {

struct Step {
  const STEP_TYPE type;
  const Location location;
  const Id job;
  const Duration service;
  const Amount load;

  Duration arrival;
  Duration duration;
  Duration waiting_time;
  Distance distance;

  Step(STEP_TYPE type, Location location, const Amount& load);

  Step(const Job& job, const Amount& load);
};

} // namespace vroom

#endif
