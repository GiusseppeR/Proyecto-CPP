if(NOT EXISTS "D:/Escritorio/ProyectoBase/cmake-build-debug/extern/cgal-5.6.1/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: D:/Escritorio/ProyectoBase/cmake-build-debug/extern/cgal-5.6.1/install_manifest.txt")
endif(NOT EXISTS "D:/Escritorio/ProyectoBase/cmake-build-debug/extern/cgal-5.6.1/install_manifest.txt")

if (NOT DEFINED CMAKE_INSTALL_PREFIX)
  set (CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/playCircle")
endif ()
 message(${CMAKE_INSTALL_PREFIX})

file(READ "D:/Escritorio/ProyectoBase/cmake-build-debug/extern/cgal-5.6.1/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach(file ${files})
  message(STATUS "Uninstalling $ENV{DESTDIR}${file}")
  if(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    execute_process(
      COMMAND "D:/CLion 2023.2.2/bin/cmake/win/x64/bin/cmake.exe" -E remove "$ENV{DESTDIR}${file}"
      OUTPUT_STRIP_TRAILING_WHITESPACE
      OUTPUT_VARIABLE rm_out
      RESULT_VARIABLE rm_retval
      )
    if(NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing $ENV{DESTDIR}${file}")
    endif(NOT "${rm_retval}" STREQUAL 0)
  else(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
    message(STATUS "File $ENV{DESTDIR}${file} does not exist.")
  endif(IS_SYMLINK "$ENV{DESTDIR}${file}" OR EXISTS "$ENV{DESTDIR}${file}")
endforeach(file)
