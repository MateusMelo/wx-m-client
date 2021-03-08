cmake_minimum_required(VERSION 3.16)
project(wx_m_client)
set(CMAKE_CXX_STANDARD 14)
set(SOURCES
        App.cpp App.h MainFrame.cpp MainFrame.h)

find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})

add_executable(wx_m_client ${SOURCES})

# and for each of your dependent executable/library targets:
target_link_libraries(wx_m_client ${wxWidgets_LIBRARIES})