HEAPsz = 0x10
wam.log: ./wam.exe wam.src
	./wam.exe < wam.src > $@ && tail $(TAIL) $@
./wam.exe: wam.cpp Makefile
	$(CXX) -DHEAPsz=$(HEAPsz) -o $@ $<	

log.log: ./exe.exe src.src
	./exe.exe < src.src > log.log && tail $(TAIL) log.log
C = cpp.cpp ypp.tab.cpp lex.yy.c
H = hpp.hpp ypp.tab.hpp
CXXFLAGS += -std=gnu++11
./exe.exe: $(C) $(H) Makefile
	$(CXX) $(CXXFLAGS) -o $@ $(C)
ypp.tab.cpp: ypp.ypp
	bison $<
lex.yy.c: lpp.lpp
	flex $<