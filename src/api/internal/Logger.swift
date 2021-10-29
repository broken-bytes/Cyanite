import WinSDK
import func WinSDK.MessageBoxW
import let WinSDK.MB_OK
import struct WinSDK.UINT
import Foundation

fileprivate typealias Log = @convention(c)([Int8], Int, UInt8) -> Void
fileprivate var logFunc: Log!
fileprivate let CP_UNICODE_8: DWORD = 65001


public enum LogLevel: UInt {
    case Verbose
    case Info
    case Warning
    case Error
    case FatalError
}

fileprivate var logLib: HINSTANCE!
fileprivate var console: HANDLE!

public func loggerInit() {
	AllocConsole()
        AttachConsole(0)
		SetConsoleTitleA("CYANITE");

        console = GetStdHandle(STD_OUTPUT_HANDLE)
    	SetConsoleMode(console, CP_UNICODE_8)
}

public func sysOut(message: String, with level: LogLevel) {
        let date = Date()
        let dateStr = date.description
        var written: DWORD = 0
        withUnsafePointer(to: message.count + dateStr.count + 4) { ptr in 
        	switch (level) {
	            case .Verbose:
		            SetConsoleTextAttribute(
			            console,
			            0x0F);
		break;
	case LogLevel.Info:
		SetConsoleTextAttribute(
			console,
			0x07);
		break;
	case LogLevel.Warning:
		SetConsoleTextAttribute(
			console,
			0x06);
		break;
	case LogLevel.Error:
		SetConsoleTextAttribute(
			console,
			0x04);
		break;
	case LogLevel.FatalError:
		SetConsoleTextAttribute(
			console,
			0x0D);
		break;
	}
              WriteConsoleA(
                    console,
		            Date().description + " | " + message + "\n",
		            UnsafeRawPointer(ptr).load(as: UInt32.self),
		            &written,
		            nil);
        }
    }
