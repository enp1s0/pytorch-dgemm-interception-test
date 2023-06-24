lib: src/main.cpp
	g++ -shared -fPIC -o libdgemm_intercept.so $<
