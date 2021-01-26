#include <sys/time.h>
#include <time.h>
#include <limits.h>

void getTimeoutAbsolute(struct timespec *ts, long long millis,
                        long long nanos) {

    /* Calculate seconds (long long prevents overflow) */
    long long seconds = millis / 1000 + nanos / 1000000000;

    /* Calculate nanoseconds */
    nanos %= 1000000000;
    nanos += (millis % 1000) * 1000000;

    /* Adjust values so that nanos is less than 1 second */
    if(nanos > 999999999) {
        seconds++;
        nanos -= 1000000000;
    }

    /* If seconds is too big to fit into the timespec use the
       maximum value (year 2038) */
    ts->tv_sec = seconds > LONG_MAX ? LONG_MAX : seconds;
    ts->tv_nsec = nanos;
}

void getTimeoutRelative(struct timespec *ts, long long millis,
                        long long nanos) {
    struct timeval tv;
    long long seconds;

    /* Get the current time */
    gettimeofday(&tv, NULL);

    /* Calculate seconds (long long prevents overflow) */
    seconds = tv.tv_sec + millis / 1000 + nanos / 1000000000;

    /* Calculate nanoseconds */
    nanos %= 1000000000;
    nanos += (tv.tv_usec + ((millis % 1000) * 1000)) * 1000;

    /* Adjust values so that nanos is less than 1 second.
       This also prevents overflowing the timespec, as the
       value may be larger than tv_nsec (signed int) */
    seconds += nanos / 1000000000;
    nanos %= 1000000000;

    /* If seconds is too big to fit into the timespec use the
       maximum value (year 2038) */
    ts->tv_sec = seconds > LONG_MAX ? LONG_MAX : seconds;
    ts->tv_nsec = nanos;
}

