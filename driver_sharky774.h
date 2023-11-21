/*
  Based on: https://github.com/wmbusmeters/wmbusmeters/blob/master/src/driver_sharky774.cc
  Copyright (C) 2017-2022 Fredrik Öhrström (gpl-3.0-or-later)
*/

#pragma once

#include "driver.h"

#include <vector>
#include <string>

struct Sharky774: Driver
{
  Sharky774(std::string key = "") : Driver(std::string("sharky774"), key) {};
  virtual esphome::optional<std::map<std::string, float>> get_values(std::vector<unsigned char> &telegram) override {
    std::map<std::string, float> ret_val{};

    add_to_map(ret_val, "total_energy_consumption_kwh", this->get_0C06(telegram));
    add_to_map(ret_val, "total_energy_consumption_kwh", this->get_0C0E(telegram));
    add_to_map(ret_val, "total_volume_m3", this->get_0C13(telegram));
    add_to_map(ret_val, "volume_flow_m3h", this->get_0B3B(telegram));
    add_to_map(ret_val, "power_kw", this->get_0C2B(telegram));
    add_to_map(ret_val, "flow_temperature_c", this->get_0A5A(telegram));
    add_to_map(ret_val, "return_temperature_c", this->get_0A5E(telegram));

    if (ret_val.size() > 0) {
      return ret_val;
    }
    else {
      return {};
    }
  };

private:
};