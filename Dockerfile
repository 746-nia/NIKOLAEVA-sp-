FROM ubuntu
MAINTAINER Nikolaeva
COPY var16.cpp /e/dir/lab3.cpp
RUN apt-get update
RUN apt-get install -y vim
RUN apt-get install -y binutils
RUN apt-get update
RUN apt-get install -y gcc-multilib
