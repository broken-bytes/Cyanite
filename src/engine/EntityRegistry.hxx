#pragma once

#include <mutex>

#include "Component.hxx"
#include "EntitySet.hxx"
#include <uuid/uuid.h>

namespace BrokenBytes::Cyanite::Engine {
	struct Entity;

	class EntityRegistry {
	public:
		EntityRegistry();
		[[nodiscard]] auto Create() -> Entity&;

		[[nodiscard]] auto CreateSet(std::string named, std::vector<std::string> filter)->EntitySet;
		[[nodiscard]] auto CreateExclusiveSet(std::string named, std::vector<std::string> filter)->EntitySet;
	private:
		std::vector<Entity> _entities;
		std::vector<EntitySet> _sets;
		std::mutex _mutex;
	};
}
