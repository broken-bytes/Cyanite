import WinSDK
import func WinSDK.MessageBoxW
import let WinSDK.MB_OK
import struct WinSDK.UINT
import Foundation

public class Logger {
    let logLib: HINSTANCE!

    init() {
        logLib = LoadLibraryA("C:\\Users\\Marcel\\Documents\\Cyanite\\build\\src\\engine\\Logging\\Debug\\Logging.dll")
        let startProc = GetProcAddress(HMODULE(logLib), "CreateLogger")
        startProc!()

        var logProc = GetProcAddress(HMODULE(logLib), "Test")

        typealias Log = Optional<(@convention(c) (Int, Int) -> Int64)>

        logProc!()

        //let test = logProc as! Log
    }


}
