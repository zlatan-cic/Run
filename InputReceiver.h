#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


class InputReceiver
{
private:
	vector<Event> m_Event;

public:
	void addEvent(Event event);
	vector<Event>& getEvent();
	void clearEvents();
};