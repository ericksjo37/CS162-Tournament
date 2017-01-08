default: Main.cpp BabaYaga.cpp BabaYaga.hpp Barbarian.cpp Barbarian.hpp BlueMen.cpp BlueMen.hpp Creature.cpp Creature.hpp HarryPotter.cpp HarryPotter.hpp Medusa.cpp Medusa.hpp FightingQueue.cpp FightingQueue.hpp Loserpile.cpp Loserpile.hpp
	g++ -std=c++0x Main.cpp BabaYaga.cpp BabaYaga.hpp Barbarian.cpp Barbarian.hpp BlueMen.cpp BlueMen.hpp Creature.cpp Creature.hpp HarryPotter.cpp HarryPotter.hpp Medusa.cpp Medusa.hpp FightingQueue.cpp FightingQueue.hpp Loserpile.cpp Loserpile.hpp  -o Ass4
	rm -f $(PROGS) *.o *~
