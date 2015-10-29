#include "stdafx.h"
#include "Event.h"

namespace SimpleEvents {

	Event::Event()
		: is_active_(true)
		, callback_id_(0)
	{
	}


	Event::~Event()
	{
	}

	Event::CallbackHolder Event::add_callback(CallbackT callback)
	{
		callbacks_[++callback_id_] = callback;
		return CallbackHolder(*this, callback_id_);
	}

	void Event::remove_callback(CallbackId callback_id)
	{
		callbacks_.erase(callback_id);
	}

	void Event::on_complete()
	{
		if(is_active_)
			for each (auto callback in callbacks_)
			{
				callback.second();
			}
	}


} // namespace SimpleEvents
