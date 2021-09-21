#include <vector>

#include "EntitySet.hxx"
#include "Entity.hxx"
#include "Component.hxx"

namespace BrokenBytes::Cyanite::Engine {
	EntitySet::EntitySet(std::string name, std::vector<std::string> filter) {
		this->_name = name;
		this->_filter = filter;
	}

	auto EntitySet::Name() const -> std::string { return this->_name; }
	auto EntitySet::Entities() const -> std::vector<Entity> { return this->_entities; }
	
	auto EntitySet::operator==(const EntitySet& rhs) -> bool {
		return this->_name == rhs._name;
	}

	auto EntitySet::Register(Entity entity) -> void {
		this->_entities.push_back(entity);
	}

	auto EntitySet::Remove(Entity entity) -> void {
		std::remove(std::begin(_entities), std::end(_entities), entity);
	}
}
