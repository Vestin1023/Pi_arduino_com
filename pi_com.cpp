#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>
int main ()
{
 int fd ;
// devices on RPi – serial0 / ttyS0 / ttyAMA0
 if ((fd = serialOpen ("/dev/serial0", 1200)) < 0){
 fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
 return 1 ;
 }
 serialPutchar(fd, 'A'); // Write char 'A'(65) to serial port
 delay(500); // Wait for char to be received from loopback
 while(serialDataAvail(fd)){ // While data is available
 printf("data recv: %d", serialGetchar(fd));
 fflush(stdout); // Flush stdout to avoid buffering
 }
 return 0 ;
}
