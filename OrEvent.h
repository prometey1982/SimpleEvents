#pragma once

#include "DependentEvent.h"

#include <set>

namespace SimpleEvents {

	class OrEvent : public DependentEvent
	{
	public:
		OrEvent(std::initializer_list<Event *> events);

	private:
		void on_nested_event_complete() override;

	};

} // namespace SimpleEventes
