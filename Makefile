CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = cc3kgame
OBJECTS = main.o controller.o textdisplay.o view.o game.o character.o cell.o player.o shade.o potion.o ba.o bd.o wa.o wd.o enemy.o dwarf.o drow.o elf.o goblin.o halfling.o human.o orc.o troll.o vampire.o merchant.o dragon.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

