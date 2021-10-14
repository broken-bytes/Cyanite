import WinSDK
import func WinSDK.MessageBoxW
import let WinSDK.MB_OK
import struct WinSDK.UINT
import Foundation

fileprivate typealias Log = @convention(c)([Int8], Int, UInt8) -> Void
fileprivate var logFunc: Log!

public class Logger {
    fileprivate var logLib: HINSTANCE!

    
    init() {
        self.logLib = LoadLibraryA("C:\\Users\\Marcel\\Documents\\Cyanite\\build\\src\\engine\\Logging\\Debug\\Logging.dll")
        
        var startProc = GetProcAddress(HMODULE(logLib), "CreateLogger")
        withUnsafePointer(to: GetProcAddress(HMODULE(logLib), "Log")) { ptr in 
            let rawPtr = UnsafeRawPointer(ptr)
            logFunc = rawPtr.load(as: Log.self)
        }  
        startProc!()

        log(message: "123456", level: 2)
        log(message: "ABCDEF", level: 2)
    }
}


public func log(message: String, level: UInt8) {
        var cString = message.cString(using: .ascii)!
        
        logFunc(cString.reversed(),  message.count, 1)
}
