#include "stdafx.h"
#include "OrEvent.h"

namespace SimpleEvents {

	OrEvent::OrEvent(std::initializer_list<Event *> events)
		: DependentEvent(events)
	{
	}

	void OrEvent::on_nested_event_complete()
	{
		on_complete();
	}

} // namespace SimpleEvents
