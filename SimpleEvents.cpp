// SimpleEvents.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "AndEvent.h"
#include "SwitchEvent.h"

using namespace SimpleEvents;
using namespace std;

int main()
{

	SwitchEvent left_event;
	auto h1 = left_event.add_callback([] { cout << "left event complete" << endl; });
	
	SwitchEvent right_event;
	auto h2 = right_event.add_callback([] { cout << "right event complete" << endl; });

	AndEvent and_event(left_event, right_event);
	auto h3 = and_event.add_callback([] { cout << "And event complete" << endl;  });

	left_event.complete();
	right_event.complete();

	getchar();

    return 0;
}

