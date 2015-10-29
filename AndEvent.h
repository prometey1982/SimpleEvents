#pragma once
#include "Event.h"

namespace SimpleEvents {

	class AndEvent : public Event
	{
	public:
		AndEvent(Event & lhs, Event & rhs);
		~AndEvent();

	private:
		void left_event_callback();
		void right_event_callback();

		void check_complete();

	private:
		Event & lhs_;
		Event & rhs_;

		CallbackHolder lhs_callback_holder_;
		CallbackHolder rhs_callback_holder_;

		bool left_complete_;
		bool right_complete_;

	};

} // namespace SimpleEventes
