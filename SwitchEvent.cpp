#include "stdafx.h"
#include "SwitchEvent.h"

namespace SimpleEvents {

	SwitchEvent::SwitchEvent()
	{
	}


	SwitchEvent::~SwitchEvent()
	{
	}

	void SwitchEvent::complete()
	{
		on_complete();
	}

} // namespace SimpleEvents
