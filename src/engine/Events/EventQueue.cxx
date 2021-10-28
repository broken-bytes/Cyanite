#include "EventQueue.hxx"

namespace BrokenBytes::Cyanite::Engine::Events {
	auto EventQueue::Push(Event* e) -> void {
		_events.push_back(std::shared_ptr<Event>(e));
	}

	auto EventQueue::Peek() const -> std::shared_ptr<Event> {
		std::scoped_lock lock(_mtx);
		return std::shared_ptr<Event>(_events.front());
	}

	auto EventQueue::Pop() -> std::shared_ptr<Event> {
		std::scoped_lock lock( _mtx );
		auto element = std::shared_ptr<Event>(_events.front());
		_events.pop_front();
		return element;
	}

	auto EventQueue::Empty() const -> bool {
		return _events.empty();
	}
}
