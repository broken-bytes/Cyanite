#pragma once
#include <vector>
#include <deque>
#include <mutex>
#include <thread>

#include "Event.hxx"


namespace BrokenBytes::Cyanite::Engine::Events {

	class EventQueue {
	public:
		auto Push(Event* e) -> void;
		[[nodiscard]] auto Peek() const ->std::shared_ptr<Event>;
		[[nodiscard]] auto Pop()->std::shared_ptr<Event>;
		[[nodiscard]] auto Empty() const -> bool;

	private:
		std::deque<std::shared_ptr<Event>> _events;
		mutable std::mutex _mtx;
		
	};    
}
