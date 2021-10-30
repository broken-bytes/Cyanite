#include <uuid.h>
#include <vector>

#include "EntityRegistry.hxx"
#include "Entity.hxx"

namespace BrokenBytes::Cyanite::Engine {
	EntityRegistry::EntityRegistry() {
		
	}

	auto EntityRegistry::Create()-> Entity& {
		std::random_device rd;
		auto seed_data = std::array<int, std::mt19937::state_size> {};
		std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
		std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
		std::mt19937 generator(seq);
		uuids::uuid_random_generator gen{ generator };

		uuids::uuid uuid = gen();
		auto element = Entity(uuid);
		{
			std::scoped_lock lock{ _mutex };
			_entities.push_back(element);
		}
		return element;
	}

	auto EntityRegistry::CreateSet(std::string named, std::vector<std::string> filter) -> EntitySet {
		auto element = EntitySet(named, filter);
		_sets.push_back(element);
		return element;
	}
}
