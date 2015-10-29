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

		class CallbackHolder
		{
		public:
			CallbackHolder(Event & event, CallbackId callback_id)
				: event_(event)
				, callback_id_(callback_id)
			{
			}

			CallbackHolder(CallbackHolder && rhs)
				: event_(rhs.event_)
				, callback_id_(rhs.callback_id_)
			{
				rhs.callback_id_ = 0;
			}

			~CallbackHolder()
			{
				if(callback_id_ != 0)
					event_.remove_callback(callback_id_);
			}
			
		private:
			Event & event_;
			CallbackId callback_id_;

		};

		CallbackHolder add_callback(CallbackT callback);
		void remove_callback(CallbackId callback_id);

	protected:
		void on_complete();

	private:
		bool is_active_;

		CallbackId callback_id_;

		std::map<CallbackId, CallbackT> callbacks_;
		
	};

} // namespace SimpleEvents
