#pragma once

#include "Event.h"

#include <list>

namespace SimpleEvents {

	class DependentEvent : public Event
	{
	public:
		DependentEvent(std::initializer_list<Event *> events);
		~DependentEvent();

	protected:
		virtual void on_nested_event_complete() = 0;

	private:
		void add_nested_event(Event & event);

	protected:
		std::list<Event *> nested_events_;
		std::list<CallbackHolder> callbacks_;

	}; // class DependentEvent

} // namespace SimpleEventes
