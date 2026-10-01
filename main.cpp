#include <iostream>
#include <unistd.h>

#include "Drivers/SocketCan.h"

int main()
{
    SocketCan socket("vcan0");
    can_frame frame = {0x1, 0x3, 0x0 , 0x0, 0x0, {0x01,0x02,0x03 ,0x04}};
    while (true)
    {
        socket.send(frame);
        sleep(1);
    }
    return 0;
}