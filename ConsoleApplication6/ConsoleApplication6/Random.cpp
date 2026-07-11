#include "Random.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void Random::generate() {
	srand((unsigned)time(NULL));

	for (int i = 0; i< 4; i++) {
		value_[i] = rand() % 10;

		//
		for (int j = 0; j < i; j++) {
			//‚±‚ê‚Ü‚Å‚ÉŽg‚í‚ê‚Ä‚¢‚éê‡ value_[i] ‚Í‚â‚è’¼‚³‚È‚¯‚ê‚Î‚È‚ç‚È‚¢
			if (value_[j] == value_[i]) {
				i--;
				break;
			}
		}
	}
}