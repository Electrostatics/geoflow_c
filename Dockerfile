FROM ubuntu:20.04

ARG ENABLE_TESTS=false

SHELL ["/bin/bash", "-c"]

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
        build-essential \
        cmake \
        libeigen3-dev \
        libboost-dev \
        && \
    mkdir /src && \
    /bin/true

COPY examples /src/examples
COPY src /src/src
COPY test /src/test
COPY CMakeLists.txt /src/CMakeLists.txt

RUN cd /src && \
    mkdir build && \
    cd build && \
    cmake -DENABLE_TESTS=${ENABLE_TESTS} .. && \
    make install && \
    /bin/true
