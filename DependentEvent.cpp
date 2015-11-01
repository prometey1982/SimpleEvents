#include "stdafx.h"

#include "DependentEvent.h"

namespace SimpleEvents {

	DependentEvent::DependentEvent(std::initializer_list<Event *> events)
	{
		for each(auto & event in events)
			add_nested_event(*event);
	}

	DependentEvent::~DependentEvent()
	{
	}

	void DependentEvent::add_nested_event(Event & event)
	{
		nested_events_.push_back(&event);
		callbacks_.push_back(event.add_callback([this] { on_nested_event_complete(); }));
	}

} // namespace SimpleEvents
