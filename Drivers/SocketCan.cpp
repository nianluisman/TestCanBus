//
// Created by nian-luisman on 10/1/26.
//
#include "SocketCan.h"

#include <cstdio>
#include <cstring>
#include <linux/can/raw.h>   // CAN_RAW
#include <net/if.h>          // if_nametoindex()
#include <sys/socket.h>      // socket(), bind()
#include <unistd.h>          // close()
#include <sys/ioctl.h>

SocketCan::SocketCan(std::string_view interface_name)
{
    socket_fd_ = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    struct sockaddr_can addr;
    struct ifreq ifr;
    strcpy(ifr.ifr_name, interface_name.data());
    ioctl(socket_fd_, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    bind(socket_fd_, (struct sockaddr *)&addr, sizeof(addr));
}

SocketCan::~SocketCan()
{
}

SocketCan::SocketCan(SocketCan&& other) noexcept
{
}

SocketCan& SocketCan::operator=(SocketCan&& other) noexcept
{
    return *this;
}

void SocketCan::send(const can_frame& frame)
{
    ssize_t nbytes = write(socket_fd_, &frame, sizeof(struct can_frame));
    if (nbytes < 0) {
        perror("can raw socket read");
        return;
    }

    /* paranoid check ... */
    if (nbytes < sizeof(struct can_frame)) {
        fprintf(stderr, "read: incomplete CAN frame\n");
    }
}

can_frame SocketCan::receive()
{
    can_frame frame;

    ssize_t nbytes = read(socket_fd_, &frame, sizeof(struct can_frame));

    if (nbytes < 0) {
        perror("can raw socket read");
        return frame;
    }

    /* paranoid check ... */
    if (nbytes < sizeof(struct can_frame)) {
        fprintf(stderr, "read: incomplete CAN frame\n");
        return frame;
    }

    return {};
}

