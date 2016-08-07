#define _GNU_SOURCE
#include "libc.h"
#include "syscall.h"
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>

int accept4(int fd, struct sockaddr* restrict addr, socklen_t* restrict len, int flg) {
    if (!flg)
        return accept(fd, addr, len);
    int ret = syscall(SYS_accept4, fd, addr, len, flg, 0, 0);
    if (ret >= 0 || (errno != ENOSYS && errno != EINVAL))
        return ret;
    ret = accept(fd, addr, len);
    if (ret < 0)
        return ret;
    if (flg & SOCK_CLOEXEC)
        fcntl(ret, F_SETFD, FD_CLOEXEC);
    if (flg & SOCK_NONBLOCK)
        fcntl(ret, F_SETFL, O_NONBLOCK);
    return ret;
}