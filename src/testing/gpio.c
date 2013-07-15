////////////////////////////////////////////////////////////////////////////////
/**
 *  @file gpio.c
 *  @brief Toggle pg9 LED gpio.
 *
 *  Turns the Status LED on for two seconds, off for two seconds, then exits.
 *
 *  @title gpio.c
 *  @author Nicholas Guthrie
 *  @created 2013-06-13
 *
 *  Compile with: gcc gpio.c -o ../../bin/testing/gpio
 */
////////////////////////////////////////////////////////////////////////////////
/**
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------ :Libraries:
//                      _    _ _                 _
//                     | |  (_) |__ _ _ __ _ _ _(_)___ ___
//                     | |__| | '_ \ '_/ _` | '_| / -_|_-<
//                     |____|_|_.__/_| \__,_|_| |_\___/__/
//
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> //for sleep

//----------------------------------------------------------------------- :Main:
//                              __  __      _
//                             |  \/  |__ _(_)_ _
//                             | |\/| / _` | | ' \
//                             |_|  |_\__,_|_|_||_|
//
// -----------------------------------------------------------------------------
int main()
{
    // Variables
    char s_0[] = "0";
    char s_1[] = "1";
    int fd;
    int num = 0;

    // Open GPIO Pin
    if( (fd=open("/sys/devices/virtual/misc/sun4i-gpio/pin/pg9", O_RDWR)) < 0 )
    {
	printf("ERROR Opening file, Exiting.\n");
	return 1;
    }
    else
    {
	printf("Sucessfully opened file.\n");
    }

    // Turn LED On
    if( write(fd, s_1, strlen(s_1)) < 0 )
    {
	printf("  Error writing s_1, Exiting\n");
    }
    else
    {
	printf("  LED ON\n");
    }

    sleep(2);

    // Turn LED Off
    if( write(fd, s_0, strlen(s_0)) < 0 )
    {
	printf("  Error writing s_0, Exiting\n");
    }
    else
    {
	printf("  LED OFF\n");
    }

    sleep(2);

    // Close file
    if( close(fd)<0 )
    {
	printf("ERROR closing file, Exiting.\n");
	return 1;
    }
    else
    {
	printf("Sucessfully closed file.\n");
    }
}
