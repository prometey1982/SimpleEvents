#pragma once
#include "DependentEvent.h"

namespace SimpleEvents {

	class AndEvent : public DependentEvent
	{
	public:
		AndEvent(std::initializer_list<Event *> events);

	private:
		void on_nested_event_complete() override;

	};

} // namespace SimpleEventes
