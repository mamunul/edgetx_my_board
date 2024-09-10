cmake -DPCB=XETOZ -DPCBREV=Z1 \
 -DCMAKE_PREFIX_PATH=$QTDIR \
 -DARM_TOOLCHAIN_DIR=/Applications/ArmGNUToolchain/13.3.rel1/arm-none-eabi/bin/ \
 -DPYTHON_EXECUTABLE=/Users/pspace/.pyenv/shims/python3 ..


make -j4 firmware


cmake -DPCB=X10 -DPCBREV=TX16S \
 -DCMAKE_PREFIX_PATH=$QTDIR \
 -DARM_TOOLCHAIN_DIR=/Applications/ArmGNUToolchain/13.3.rel1/arm-none-eabi/bin/ \
 -DPYTHON_EXECUTABLE=/Users/pspace/.pyenv/shims/python3 ..

make -j4 firmware