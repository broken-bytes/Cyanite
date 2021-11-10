#if _WIN32
import WinSDK
typealias Handle = HMODULE
#endif

class DynamicLibrary {
    var path: String
    var handle: Handle!

    init(at path: String) {
        self.path = path
        #if _WIN32
        self.handle = LoadLibraryA(path)
        #endif
    }
    
    func function(named func: String) -> Int64 {
        return 0
    }
}
