#pragma once

#include <vector>
#include <uuid.h>


namespace BrokenBytes::Cyanite::Engine {
	class EntityRegistry;
	struct Entity;
	struct Component;
	struct EntitySet {
	public:
		EntitySet(std::string name, std::vector<std::string> filter);
		[[nodiscard]] auto Name() const->std::string;
		[[nodiscard]] auto Entities() const->std::vector<Entity>;
		auto operator==(const EntitySet& rhs) -> bool;
		
	private:
		std::string _name;
		std::vector<Entity> _entities;
		std::vector<std::string> _filter;
		friend class EntityRegistry;
		auto Register(Entity entity) -> void;
		auto Remove(Entity entity) -> void;
	};
}
