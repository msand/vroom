#ifndef JOB_H
#define JOB_H

/*

This file is part of VROOM.

Copyright (c) 2015-2019, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include <vector>

#include "structures/typedefs.h"
#include "structures/vroom/amount.h"
#include "structures/vroom/location.h"
#include "structures/vroom/time_window.h"

namespace vroom {

struct Job {
  Location location;
  const Id id;
  const Duration service;
  const Amount delivery;
  const Amount pickup;
  const Skills skills;
  const Priority priority;
  const std::vector<TimeWindow> tws;
  const Duration tw_length;

  Job(Id id,
      const Location& location,
      Duration service = 0,
      const Amount& delivery = Amount(0),
      const Amount& pickup = Amount(0),
      const Skills& skills = Skills(),
      Priority priority = 0,
      const std::vector<TimeWindow>& tws =
        std::vector<TimeWindow>(1, TimeWindow()));

  Index index() const {
    return location.index();
  }

  bool is_valid_start(Duration time) const;
};

} // namespace vroom

#endif
