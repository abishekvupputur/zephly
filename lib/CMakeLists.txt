# Copyright (c) 2022 Jonathan Hahn
# SPDX-License-Identifier: Apache-2.0

# add_subdirectory(attitude_estimation)
add_subdirectory(mixer)
add_subdirectory_ifdef(CONFIG_ZEPHLY_CONTROL_LIB control)
