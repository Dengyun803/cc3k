#include "controller.h"
#include <iostream>

int main(int argc, char *argv[]){
	Controller c;
	if (argc == 1) {
		c.play();
        } else {
		std::string f = argv[1];
        	c.testPlay(f);
        }
}
