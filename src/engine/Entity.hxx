#pragma once

#include <iostream>
#include <uuid/uuid.h>
#include <inka>
#include <inja/inja.hpp>

#include "Component.hxx"

using namespace inja;

namespace BrokenBytes::Cyanite::Engine {
	class ComponentNotFoundException : std::exception {
	public:
		ComponentNotFoundException(std::string message):
		std::exception(message.c_str()){}
	private:
		std::string _name;
	};
	
#pragma pack(push, 1)
struct Entity {
public:
	[[nodiscard]] auto UUID() const -> const uuids::uuid;
	[[nodiscard]] auto Components() const-> const std::vector<Component>;
	template<
		typename C,
		typename = std::enable_if<std::is_base_of<Component, C>::value
		>>
	auto Add(C component) -> void {
		this->_components.push_back(component);
	}
	template<
		typename C,
		typename = std::enable_if<std::is_base_of<Component, C>::value
	>>
	auto Component()->const C& {
		std::cout << "Target: " << typeid(C).name() << std::endl;
		for(auto& comp: this->_components) {
			std::cout << "Found : " << comp.Name() << std::endl;

			if(comp.Name() == typeid(C).name()) {
				return reinterpret_cast<C&>(comp);
			}
		}
		auto msg = json();
		msg["name"] = typeid(C).name();
		msg["target"] = to_string(this->_uuid);
		
		throw ComponentNotFoundException(
			render(
				"Trying to access component {{ name }} which is not found on {{ target }}",
				msg)
		);
	}
	auto operator==(const Entity& rhs) -> bool;
private:
	uuids::uuid _uuid;
	std::vector <Engine::Component> _components;
	friend class EntityRegistry;
	friend struct EntitySet;
	
	Entity(uuids::uuid uuid);
};
#pragma pack(pop)
	
}
