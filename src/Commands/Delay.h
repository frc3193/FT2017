#ifndef DELAY_H
#define DELAY_H

#include "Commands/TimedCommand.h"

class Delay : public TimedCommand {
public:
	Delay(double timeout);
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
};

#endif
