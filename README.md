# TrafficTool
C++/JS/MySQL tool to analyze traffic data

## General Information
This project requires CMake (3.15.0) to build and run!

**To correctly run this program, the `src/TrafficTool/CMakelists.txt` file _must_ be edited to have the correct library paths!**

Additional libraries:
- Boost C++ 1.70.0
	- Regex
	- Property Tree
	- Json Parser
	- Histogram
- MySQL C++ Connector
- MathGL2
    - TBD
- GNU Scientific Library (GSL)

## Build Information
```
cmake .
```

## Changelog 
09/01/2019 - Added initial memory profiling for application and simple math functions
