#include "InputReceiver.h"

void InputReceiver::addEvent(Event event)
{
	m_Event.push_back(event);
}

vector<Event>& InputReceiver::getEvent()
{
	return m_Event;
}

void InputReceiver::clearEvents()
{
	m_Event.clear();
}