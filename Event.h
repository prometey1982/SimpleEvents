#pragma once

#include <functional>
#include <map>

namespace SimpleEvents {

	class Event
	{
	public:
		Event();
		virtual ~Event();

		bool activate(bool active) { is_active_ = active; }
		bool is_active() const { return is_active_; }

		typedef std::function<void()> CallbackT;
		typedef unsigned CallbackId;

		CallbackId add_callback(CallbackT callback);
		void remove_callback(CallbackId callback_id);

	protected:
		void on_complete();

	private:
		bool is_active_;

		CallbackId callback_id_;

		std::map<CallbackId, CallbackT> callbacks_;
		
	};

} // namespace SimpleEvents
