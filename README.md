# segy_cpp
SEGY API development tool for c++ environment.

segy.h contains all the standart segy structure and classes. segy class can open segy file (little or big endian), It will convert from IBM floating point to IEEE (but not vice versa yet).

inside src_sample contains the sample main file.

I have tested with icc and g++ using -std=c++11. Please refer to Makefile 

Sincerely,
Amirul.
