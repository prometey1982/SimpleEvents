#include "stdafx.h"
#include "AndEvent.h"

namespace SimpleEvents {

	AndEvent::AndEvent(Event & lhs, Event & rhs)
		: lhs_(lhs)
		, rhs_(rhs)
		, lhs_callback_holder_(lhs.add_callback([this] { left_event_callback(); }))
		, rhs_callback_holder_(rhs.add_callback([this] { right_event_callback(); }))
		, left_complete_(false)
		, right_complete_(false)

	{
	}

	AndEvent::~AndEvent()
	{
	}

	void AndEvent::left_event_callback()
	{
		left_complete_ = true;

		check_complete();
	}

	void AndEvent::right_event_callback()
	{
		right_complete_ = true;

		check_complete();
	}

	void AndEvent::check_complete()
	{
		if (left_complete_ && right_complete_)
			on_complete();
	}

} // namespace SimpleEvents
