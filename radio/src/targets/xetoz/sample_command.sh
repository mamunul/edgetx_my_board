export QTDIR=$(brew --prefix)/opt/qt@5
export QT_PLUGIN_PATH=$QTDIR/plugins



cmake -DPCB=XETOZ -DPCBREV=Xetoz1 \
 -DCMAKE_PREFIX_PATH=$QTDIR \
 -DARM_TOOLCHAIN_DIR=/Applications/ArmGNUToolchain/13.3.rel1/arm-none-eabi/bin/ \
 -DPYTHON_EXECUTABLE=/Users/pspace/.pyenv/shims/python3 ..

make -j4 firmware

make -j4 libsimulator

make -j4 simulator

make -j4 companion


cmake -DPCB=X10 -DPCBREV=TX16S \
 -DCMAKE_PREFIX_PATH=$QTDIR \
 -DARM_TOOLCHAIN_DIR=/Applications/ArmGNUToolchain/13.3.rel1/arm-none-eabi/bin/ \
 -DPYTHON_EXECUTABLE=/Users/pspace/.pyenv/shims/python3 ..

make -j4 firmware