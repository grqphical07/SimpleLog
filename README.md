# SimpleLog

SimpleLog is a fast and easy way to log events in your c++ code

## Quick Start

Download the package, extract it, add it to your included libraries in whatever platform you use (Visual Studio, gcc, clang etc.) and then use this code to get
started:
```c++
#include "SimpleLog.h"

int main()
{

  // There are four options for the minimum message type level Debug, Info, Warning, Error, Critical
  // The value represents what message types will go through for example if you select Info only Info and above(Warning, Error, Critical) will be logged
  SimpleLog::Logger mainLogger(SimpleLog::LoggingLevel::Info)
  mainLogger.LogInfo("Some Info!")
  return 0
}
```
