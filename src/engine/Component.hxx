#pragma once
#include "EntityRegistry.hxx"
#include "EntitySet.hxx"


namespace BrokenBytes::Cyanite::Engine {
    struct Component {
        Component(std::string name) {
            this->_name = name;
        }
    protected:
        std::string _name;
    private:
        friend class EntityRegistry;
        friend struct EntitySet;
        friend struct Entity;

        auto Name() const->std::string {
            return this->_name;
        }
    };
}
