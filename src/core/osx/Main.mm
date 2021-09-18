#import <AppKit/NSApplication.h>
#include <Cocoa/Cocoa.h>

#include <CyaniteEngine.hxx>

int main(int argc, const char *argv[]) {
    NSWindow* window1 = [[[NSWindow alloc] initWithContentRect:NSMakeRect(100, 100, 300, 300) styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable backing:NSBackingStoreBuffered defer:NO] autorelease];
    [window1 setIsVisible:YES];
    [NSApplication sharedApplication];
    
    auto engine = new BrokenBytes::Cyanite::Engine::CyaniteEngine(window1, 300, 300);
    engine->Run();

    [NSApp run];
}
