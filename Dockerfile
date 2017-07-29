FROM edhana/gcc_7
WORKDIR /usr/src/app/build
COPY . /usr/src/app
COPY run_all_tests.sh /usr/src/app/build
RUN cmake ..
RUN make -j4 VERBOSE=1
RUN ls -la /usr/src/app/build
# I know it is ugly TODO: Make this execution better
RUN ./ex1
RUN ./ex2
RUN ./ex3
RUN ./ex4
RUN ./session3_files
