import WinSDK
import func WinSDK.MessageBoxW
import let WinSDK.MB_OK
import struct WinSDK.UINT
import Foundation

fileprivate typealias Log = @convention(c)([Int32], Int, UInt8) -> Void

public class Logger {
    fileprivate var logLib: HINSTANCE!
    fileprivate var logFunc: Log!

    
    init() {
        self.logLib = LoadLibraryA("C:\\Users\\Marcel\\Documents\\Cyanite\\build\\src\\engine\\Logging\\Debug\\Logging.dll")
        
        var startProc = GetProcAddress(HMODULE(logLib), "CreateLogger")
        withUnsafePointer(to: GetProcAddress(HMODULE(logLib), "Log")) { ptr in 
            let rawPtr = UnsafeRawPointer(ptr)
            self.logFunc = rawPtr.load(as: Log.self)
        }  

        self.log(message: "Test", level: 1)
    }

    public func log(message: String, level: UInt8) {
        var data: [Int32] = []

        for c in message {
            withUnsafePointer(to: c)  { ptr in 
                data.append(UnsafeRawPointer(ptr).load(as: Int32.self))
            }
        }

        self.logFunc(data, message.count, 1)
    }
}
