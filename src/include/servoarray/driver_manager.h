// This file is part of servoarray.
//
// servoarray is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// servoarray is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with servoarray.  If not, see <http://www.gnu.org/licenses/>.

#ifndef SERVOARRAY_DRIVER_MANAGER_H
#define SERVOARRAY_DRIVER_MANAGER_H

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>

#include "servoarray/driver_params.h"
#include "servoarray/driver.h"

namespace ServoArray {

class DriverManager {
  const std::vector<std::string> paths_;
  std::unordered_map<std::string, std::shared_ptr<Driver>> loaded_drivers_;

public:
  DriverManager(const std::vector<std::string>& paths = {"/usr/share/servoarray"});

  std::shared_ptr<Driver> load(const std::string&, const DriverParams&);
  std::shared_ptr<Driver> get(const std::string&) const;

  bool is_loaded(const std::string&) const;

private:
  static std::vector<std::string> expand_paths(const std::vector<std::string>&);
  static std::string driver_file_name(const std::string&);
  std::string resolve(const std::string&) const;
};

extern DriverManager default_manager;

}

#endif
