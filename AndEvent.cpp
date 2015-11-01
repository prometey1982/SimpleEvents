#include "stdafx.h"
#include "AndEvent.h"

namespace SimpleEvents {

	AndEvent::AndEvent(std::initializer_list<Event *> events)
		: DependentEvent(events)
	{
	}

	void AndEvent::on_nested_event_complete()
	{
		bool completed = true;

		for (auto event : nested_events_)
			if (!event->completed())
				completed = false;

		if (completed)
			on_complete();
	}

} // namespace SimpleEvents
