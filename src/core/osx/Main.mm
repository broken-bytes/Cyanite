#include <CyaniteEngine.hxx>

int main(int argc, const char *argv[]) {
    auto ptr = nullptr;
    auto engine = new BrokenBytes::Cyanite::Engine::CyaniteEngine(ptr, 300, 300);
    engine->Run();
}
