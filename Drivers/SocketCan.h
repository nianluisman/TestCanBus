#ifndef TESTLINUXCAN_SOCKETCAN_H
#define TESTLINUXCAN_SOCKETCAN_H

#include "CanBus.h"

#include <string_view>

class SocketCan final : public CanBus
{
public:
    explicit SocketCan(std::string_view interface_name);
    ~SocketCan() override;

    SocketCan(const SocketCan&) = delete;
    SocketCan& operator=(const SocketCan&) = delete;
    SocketCan(SocketCan&& other) noexcept;
    SocketCan& operator=(SocketCan&& other) noexcept;

    void send(const can_frame& frame) override;
    [[nodiscard]] can_frame receive() override;

private:
    static constexpr int InvalidSocket = -1;

    int socket_fd_{InvalidSocket};
};

#endif // TESTLINUXCAN_SOCKETCAN_H
