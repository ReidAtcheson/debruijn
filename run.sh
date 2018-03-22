nx=1024;
ny=1024;
A=50.0;

./main $nx $ny $A
python3.6 plot_hs.py $nx $ny $A
