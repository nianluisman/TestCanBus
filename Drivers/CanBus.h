#ifndef TESTLINUXCAN_CANBUS_H
#define TESTLINUXCAN_CANBUS_H

#include <array>
#include <cstddef>
#include <cstdint>
#include <linux/can.h>       // can_frame, sockaddr_can

class CanBus
{
public:
    virtual ~CanBus() = default;

    CanBus(const CanBus&) = delete;
    CanBus& operator=(const CanBus&) = delete;

    virtual void send(const can_frame& frame) = 0;
    [[nodiscard]] virtual can_frame receive() = 0;

protected:
    CanBus() = default;
    CanBus(CanBus&&) = default;
    CanBus& operator=(CanBus&&) = default;
};

#endif // TESTLINUXCAN_CANBUS_H
