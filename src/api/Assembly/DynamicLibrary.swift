#if _WIN32
import WinSDK
typealias Handle = HINSTANCE
#elseif _OSX
typealias Handle = UnsafeMutableRawPointer
#endif


import Foundation

fileprivate class DynamicLibrary {
    var path: String
    var handle: Handle!

    init(at path: String) {
        self.path = path
        #if _OSX
        self.handle = dlopen(path, RTLD_NOW)
        #elseif _WIN32
        self.handle = LoadLibraryA(path)
        #endif
    }
    
    func function(named: String) throws -> Handle {
        #if _OSX
        return dlsym(self.handle, named)
        #endif
    }
}
