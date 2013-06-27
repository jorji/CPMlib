#! /bin/sh
#
# at .bashrc
#
###################################################################################
#
# CPMlib - Cartesian Partition Manager Library
#
# Copyright (C) 2012-2013 Institute of Industrial Science, The University of Tokyo.
# All right reserved.
#
###################################################################################
#
# Compiler options:
#
#   --with-comp=INTEL|FJ       This option is mandatory if either compiler is specified.
#   --with-ompi=/hoge          In case of using wrapper compiler, this option may be omitted.
#   --with-pm=/foo             Specify the directory that the PMlib is installed.
#   --with-f90real=4|8         Specify real type in fortran
#   --with-f90example=yes|no   Specify compilation of fortran sample included. 
#   --host=hostname            Specify in case of cross-compilation.
#
# Usage : ./config_cpm.sh install_directory
#
#
./configure --prefix=$1 \
            --with-comp=INTEL \
            --with-ompi=/opt/openmpi \
            --with-parser=/usr/local/TextParser \
            --with-pm=/usr/local/PMlib \
            --with-f90example=yes \
            CXX=icpc \
            CXXFLAGS=-O3 \
            F90=ifort \
            F90FLAGS=-O3 \
            LDFLAGS=-L/opt/intel/composerxe/lib/intel64

