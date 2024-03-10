// Copyright Eric Chauvin 2022



// This is licensed under the GNU General
// Public License (GPL).  It is the
// same license that Linux has.
// https://www.gnu.org/licenses/gpl-3.0.html


#include "TimeApiWin.h"
// #include "TimeApiLinux.h"


// #include <chrono>

#include <time.h>
// #include <sysinfoapi.h>



TimeApi::TimeApi( void )
{
setNow();
}



/*
Int64 TimeApi::getMilliSec( void )
{
// timespec spec;
// Int64 what = clock_gettime( CLOCK_REALTIME,
//                             &spec );

// #include <sysinfoapi.h>
Int64 milli = GetTickCount();
return milli;
}
*/


Int64 TimeApi::getSecondsNow( void )
{
__time64_t long_time;

// Get time as 64-bit integer.
_time64( &long_time );

return long_time;
}



void TimeApi::setNow( void )
{
struct tm newtime;
__time64_t long_time;
// char timebuf[26];
errno_t err;

// Get time as 64-bit integer.
_time64( &long_time );

timeSeconds = long_time;

// Convert to local time.
err = _localtime64_s( &newtime, &long_time );
if( err != 0 )
  throw "Error with time set up.";

seconds = newtime.tm_sec;
minutes = newtime.tm_min;
hour = newtime.tm_hour;
day = newtime.tm_mday;
month = newtime.tm_mon;
year = 1900 + newtime.tm_year;
weekDay = newtime.tm_wday; // Sunday = 0
yearDay = newtime.tm_yday; // day of year to 365.
dayLightSavings = newtime.tm_isdst;

//     if( newtime.tm_hour > 12 )
}



/*
For Linux.
void TimeApi::setNow( void )
{
time_t rawtime;
struct tm * timeinfo;

time( &rawtime );
timeSeconds = rawtime;

// For Linux.
timeinfo = localtime (&rawtime);

localtime_s( timeinfo, &rawtime );


// StIO::printFS( "Year:\n" );
// StIO::printFUD( 1900 + buf.tm_year );
// StIO::printFS( "\n" );

seconds = timeinfo->tm_sec;
minutes = timeinfo->tm_min;
hour = timeinfo->tm_hour;
day = timeinfo->tm_mday;
month = timeinfo->tm_mon;
year = 1900 + timeinfo->tm_year;
weekDay = timeinfo->tm_wday; // Sunday = 0
yearDay = timeinfo->tm_yday; // day of year to 365.
dayLightSavings = timeinfo->tm_isdst;
}
*/



Int64 TimeApi::diffSec( TimeApi& in )
{
return timeSeconds - in.timeSeconds;
}



void TimeApi::timeCBuf( CharBuf& result )
{

CharBuf colon( ":" );
CharBuf zero( "0" );
CharBuf secS( seconds );
CharBuf minS( minutes );
CharBuf hourS( hour );

result.clear();
result.appendCharBuf( hourS );
result.appendCharBuf( colon );
if( minS.getLast() < 2 )
  result.appendCharBuf( zero );

result.appendCharBuf( minS );
result.appendCharBuf( colon );

if( secS.getLast() < 2 )
  result.appendCharBuf( zero );

result.appendCharBuf( secS );
}


