// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html



#pragma once



#include "../CppBase/BasicTypes.h"
#include "../CppBase/CharBuf.h"



class TimeApi
  {
  private:
  Int64 timeSeconds = 0; // Seconds since Jan 1,
                         // 1970.

  Int32 seconds = 0;
  Int32 minutes = 0;
  Int32 hour = 0;
  Int32 day = 0;
  Int32 month = 0;
  Int32 year = 0;
  Int32 weekDay = 0; // Sunday = 0
  Int32 yearDay = 0; // day of year to 365.
  Int32 dayLightSavings = 0;

  public:
  TimeApi( void );
  void setNow( void );
  Int64 diffSec( TimeApi& in );
  void timeCBuf( CharBuf& cBuf );

  static Int64 getSecondsNow( void );

  // Int64 getMilliSec( void );

  };

