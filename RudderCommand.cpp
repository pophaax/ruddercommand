#include "RudderCommand.h"
#include <math.h>


RudderCommand::RudderCommand() {
	m_steeringValue = 0;
}

RudderCommand::~RudderCommand() {
}

int RudderCommand::getCommand(double command) {
	//-1=portextreme, 0=midships, 1=starboardextreme
	int delta = m_extremeCommand - m_midshipsCommand;
	return m_midshipsCommand + delta * command;
}

void RudderCommand::setCommandValues(int starboardExtreme, int midships) {
	m_extremeCommand = starboardExtreme;
	m_midshipsCommand = midships;
}

int RudderCommand::getMidShipsCommand() {
	return m_midshipsCommand;
}
