
#include "Entity.hxx"
#include <uuid.h>

namespace BrokenBytes::Cyanite::Engine {
	auto Entity::UUID() const -> const uuids::uuid {
		return this->_uuid;
	}
	
	auto Entity::Components() const -> const std::vector<Engine::Component> {
		return this->_components;
	}

	auto Entity::operator==(const Entity& rhs) -> bool {
		return this->_uuid == rhs._uuid;
	}

	Entity::Entity(uuids::uuid uuid) {
		this->_uuid = uuid;
	}
}
