# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QTradingView_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QTradingView_autogen.dir/ParseCache.txt"
  "QTradingView_autogen"
  )
endif()
