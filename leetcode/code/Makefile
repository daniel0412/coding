
lastModifiedTestFile=$(shell ls -alt *.t.cpp | head -n 1 | rev | cut -d' ' -f1 | rev)
build:
	$(info =================================)
	$(info Test: $(lastModifiedTestFile))
	$(info =================================)
	g++ -std=c++11 -lgtest -lgtest_main $(lastModifiedTestFile)
	./a.out
