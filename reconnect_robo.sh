catkin_make clean
catkin_make rebuild_cache
catkin_make
catkin_make install
sudo modprobe can_dev
sudo modprobe can
sudo modprobe can_raw
sudo ip link set can0 type can bitrate 500000
sudo ifconfig can0 up
roslaunch cpr_robot mover6_setup_muti_robot.launch mover6_ns:=mover6_a_p
