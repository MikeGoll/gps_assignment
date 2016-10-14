/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: dcgps.c - A simple console gps program that includes images of coordinates of user on a basic map that 
-- is created using ascii characters.
--
-- PROGRAM: gps
--
-- FUNCTIONS:
-- int main(int argc, char *argv[]);
-- int gps_open(server, port, gpsdata);
-- int gps_stream (gpsdata, flags, data);
-- void gps_close(gpsdata);
--
-- DATE: October 19th, 2016
--
-- DESIGNER: Yi Hsiang (Mark) Chen
--
-- PROGRAMMER: Yi Hsiang (Mark) Chen
--
-- NOTES:
-- A gps application that returns information about satellites that contribute to triangulation.
-- The information about the satellites includes their longitude, latitude, its PRN, elevation, azimuth, SNR, and a used
-- flag.
----------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <gps.h>
#include "gpsadd.h"

struct gps_data_t gpsdata;
static struct fixsource_t source;

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: main
--
-- DATE: October 19th, 2016
--
-- DESIGNER: Yi Hsiang (Mark) Chen
--
-- PROGRAMMER: Yi Hsiang (Mark) Chen
--
-- RETURNS: int.
--
-- NOTES:
-- This guns mallocs the appropriate memory for the gps_data_t structure that will contain information about the satellites,
-- open the stream to gpsd, and start the stream.
----------------------------------------------------------------------------------------------------------------------*/

int main() {
	
	unsigned int flags = WATCH_ENABLE;
	
	/* I am having trouble with malloc'ing, it gives me an 'error: incompatible types when assigning to type 'struct gps_data_t' from type 'void *' */
	gpsdata = malloc(sizeof(struct gps_data_t));
	
	/* Checking for errors on opening gps */
	if (gps_open(source.server, source.port, &gpsdata) != 0) {
		fprintf(stderr, "An unexpected error has occurred: %d %s\n", errno, gps_errstr(errno));
	}
	
	if (source.device != NULL) {
		flags |= WATCH_DEVICE;
	}
	
	/* Opening the GPS stream */
	gps_stream(&gpsdata, flags, source.device);
	
	/* Note to Mike, please add whatever functions are required to connect to gps-utils.c in this next section before
	the stream is closed, thanks! */
	
	
	
	
	
	
	/* Disabling the WATCH as well as closing the gps stream, ending the session. */
	gps_stream(&gpsdata, WATCH_DISABLE, NULL);
	(void)gps_close(&gpsdata);
}