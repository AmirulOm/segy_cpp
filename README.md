# segy_cpp
SEGY API development tool for c++ environment.

segy.h contains all the standard segy rev 1 structure and classes. segy class can open segy file (little or big endian), It will convert from IBM floating point to IEEE (but not vice versa yet).

## Using the Class
----
I have include a sample main code on how to use the header.   

~~~C
#include <iostream>
#include "../header/segy.h"

int main () {
	segy sgy;
	sgy.OpenFile("velocity.segy");
	sgy.PrintTextHeader();
	sgy.PrintBinaryHeader();
	sgy.PrintTraceHeader();
}
~~~

I have tested with icc and g++. Please refer to Makefile to compile.

~~~makefile
g++ main.cpp -std==c++
~~~

The header file can be copy and to your own code..

## API Reference
-----
Table below show all the current and future implementation of the segy class.

Class Function              | Description 												|
--------------------------- | --------------------------------------------------------- |
`segy()` 					| Constructor 												|
`~segy()` 					| Deconstructor 											|
`void OpenFile(std::string)`| Open segy file and read the data and trace   				|
`void SaveFile()` 			| Save into segy file text file  (**not implemeted yet**)	|
`void CloseFile()`			| Close the file stream (**not implemeted yet**)  			|
`void GetAllTrace()`		| return the trace data	(**not implemeted yet**) 			|
`void ReadAllTrace()`		| Read all trace to the class	(**not implemeted yet**)	|
`void SetTrace()`			| Set the trace to the class	(**not implemeted yet**)	|
`void PrintTraceHeader()`	| Print outs the Trace Header								|
`void PrintTextHeader()`	| Print outs the Text Header								|
`void PrintBinaryHeader()`	| Print outs the Binary Header								|
`void ToSu()`				| Convert to SU file (**not implemented yet**)				|


Class Variable                      | Description 															| 
----------------------------------- | --------------------------------------------------------------------- |
`unsigned char TFileHead_ [3200]` 	| Store the beginning Text header file  								|
`unsigned char ExTFileHead_ [3200]` | Store the Extension Texh Header file (**to be changed to pointer**) 	|
`binaryFileHeader BFileHead_`		| Store the binary file header   										|
`traceHeader traceHeader_`			| Store the Trace header (**to be changed to pointer**) 				|
`float *Trace_`						| Store the trace  														|
`std::string filename_;` 			| Store the filename of the segy file 									|
`std::fstream in_;`					| File stream member													|


Sincerely,
Amirul.
