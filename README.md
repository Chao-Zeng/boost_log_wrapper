description
=======================================================
this is a server log module. implemented by wrapper boost log

feature
=======================================================
* write log to console and log file. can open/close console output.
* dynamic change log level.
* log to multi-file.(for monitor and statics)
* log rotate(size and time)
* thread safe

build
=======================================================
* debug

    cmake -DCMAKE_BUILD_TYPE=Debug ..

* release

    cmake -DCMAKE_BUILD_TYPE=Release ..