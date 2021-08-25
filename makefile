all:
	g++ -std=c++17 trial.cpp -o trial

invid:
	g++ -std=c++17 invidx_cons.cpp -o sol
 
run_invid:
	g++ -std=c++17 invidx_cons.cpp -o sol
	./sol
