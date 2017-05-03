
#include "log.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <iostream>

int main(int argc, char* argv[])
{
    logger::init_log("./log/log_file");

    LOGGER(info) << "PID: " << getpid() << "  TID: " << syscall(SYS_gettid);

    LOGGER(debug) << "A debug severity message";
    LOGGER(info) << "An informational severity message";
    LOGGER(warn) << "A warning severity message";
    LOGGER(error) << "An error severity message";
    LOGGER(fatal) << "A fatal severity message";

    logger::set_log_level(debug);
    LOGGER(info) << "set log level to debug";

    LOGGER(debug) << "A debug severity message";
    LOGGER(info) << "An informational severity message";
    LOGGER(warn) << "A warning severity message";
    LOGGER(error) << "An error severity message";
    LOGGER(fatal) << "A fatal severity message";

    logger::close_console_log();
    logger::set_log_level(info);
    LOGGER(debug) << "A log file debug severity message";
    LOGGER(info) << "An log file informational severity message";
    LOGGER(warn) << "A log file warning severity message";
    LOGGER(error) << "An log file error severity message";
    LOGGER(fatal) << "A log file fatal severity message";

    logger::set_log_level(debug);
    LOG(info, "start c style log");
    LOG(debug, "c style: A debug severity message %d, %s, %ld", 1, "test", 2);
    LOG(info, "c style: An informational severity %s", "message");
    LOG(warn, "c style: A warning severity %s", "message");
    LOG(error, "c style: An error %s message", "severity");
    LOG(fatal, "c style: A %s severity message", "fatal");

    int i;
    std::cin >> i;

    return 0;
}
