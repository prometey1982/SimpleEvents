#pragma once
#include "Event.h"

namespace SimpleEvents {

	class SwitchEvent : public Event
	{
	public:
		SwitchEvent();
		~SwitchEvent();

		void complete();

	};

} // namespace SimpleEvents
