#include "Main.hxx"
#include <CyaniteEngine.hxx>

int main(int argc, char** argv) {
	auto engine = BrokenBytes::Cyanite::Engine::CyaniteEngine(nullptr, 0, 0);
	engine.Run();
    return 0;
}
