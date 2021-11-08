# Install script for directory: /Users/jaeseoko/Research/public/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/jaeseoko/Research/build_meta2/public/ysclass/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysclass11/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysport/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgl/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/gl2/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/gl1/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysglcpp/src/nownd/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysbitmap/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysbitmap/cmdtools/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysbitmaputil/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysbitmapfont/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysbitmapfont/cmdtools/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/yssystemfont/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fssimplewindow/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fssimplewindow/template/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fssimplewindow/samples/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/yssimplesound/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/yssimplesound/test/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/yssimplesound/sample/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/yssimplesound/sample_fssimplewindow/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fslazywindow/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fslazywindow/template/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fslazywindow/samples/sample00-bouncingBall/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fssimplefiledialog/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fssimplefiledialog/sample/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysfontrenderer/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ystexturemanager/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ystexturemanager/src/gl/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ystexturemanager/src/null/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsguilib/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsguilib/src/gl2/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsguilib/src/gl1/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsguilib/src/nownd/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsguilib/filedialog/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsguilib/template/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsguilib/template_with_filedialog/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsgui3d/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsgui3d/src/gl1/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsgui3d/src/gl2/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsgui3d/template/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsgui3d/template_with_filedialog/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/fsgui3d/template-easy/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/yssocket/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/kernel/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/kernelutil/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/shellrender/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/shellrender/gl2/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/shellrender/gl1/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/shellrender/nownd/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/gui_foundation/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/gui/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/main/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/cmdlib/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/cmdmain/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ysgebl/src/samples/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/2DRetroMapTool/src/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/ir_transceiver/cmake_install.cmake")
  include("/Users/jaeseoko/Research/build_meta2/public/opencv/cmake_install.cmake")

endif()

