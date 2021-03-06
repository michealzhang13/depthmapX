# Copyright (C) 2020 Petros Koutsolampros

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

set(segmentpathsgui segmentpathsgui)
set(segmentpathsgui_SRCS
    uictrigger.cpp
    segmentpathsmainwindow.cpp)
set(modules_gui "${modules_gui}" "segmentpathsgui" CACHE INTERNAL "modules_gui" FORCE)

find_package(Qt5 COMPONENTS Core Widgets Gui OpenGL REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "../../../depthmapX/UI")

add_definitions(${Qt5Core_DEFINITIONS})
add_definitions(${Qt5Widgets_DEFINITIONS})
add_definitions(${Qt5Gui_DEFINITIONS})

add_compile_definitions(SEGMENTPATHS_GUI_LIBRARY)

add_library(${segmentpathsgui} OBJECT ${segmentpathsgui_SRCS}
    ../../../depthmapX/imainwindowmodule.h)
