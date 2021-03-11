###################################################################################
#
# CPMlib - Computational space Partitioning Management library
#
# Copyright (c) 2012-2014 Institute of Industrial Science (IIS), The University of Tokyo.
# All rights reserved.
#
# Copyright (c) 2014-2016 Advanced Institute for Computational Science (AICS), RIKEN.
# All rights reserved.
#
# Copyright (c) 2016-2017 Research Institute for Information Technology (RIIT), Kyushu University.
# All rights reserved.
#
###################################################################################

set(CMAKE_SYSTEM_NAME Linux)

include(CMakeForceCompiler)

# CMAKE_FORCE_Fortran_Compiler is not supported ver. 2.6
# A : cmake version >= 2.7
# B : cmake version < 2.7

if (CMAKE_MAJOR_VERSION GREATER 2)
  set(build_rule "A")
else()
  if(CMAKE_MINOR_VERSION GREATER 6)
    set(build_rule "A")
  else()
    set(build_rule "B")
  endif()
endif()


if(with_MPI)
    set(CMAKE_C_COMPILER mpifcc)
    set(CMAKE_CXX_COMPILER mpiFCC)
  if (build_rule STREQUAL "A")
    set(CMAKE_Fortran_COMPILER mpifrt)
  else()
    set(CMAKE_Fortran_COMPILER mpifrt)
    set(CMAKE_Fortran_COMPILER_WORKS true)
  endif()
else()
    set(CMAKE_C_COMPILER fcc)
    set(CMAKE_CXX_COMPILER FCC)
  if (build_rule STREQUAL "A")
    set(CMAKE_Fortran_COMPILER frt)
  else()
    set(CMAKE_Fortran_COMPILER frt)
    set(CMAKE_Fortran_COMPILER_WORKS true)
  endif()
endif()

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(TARGET_ARCH "Fugaku")
set(USE_F_TCS "YES")



