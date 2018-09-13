#include "GoldMiner.h"
int retime = 30;

int main()
{
	startup();
	while (retime > 0)
	{
		updateWithoutInput();
		updateWithInput();
	}
	gameover();
	return 0;
}