import WinSDK
import SDL2

var engine: Engine!

public struct Event {
    var id: UInt64
    var value: UInt64
}


internal func createEngine(with window: HWND) {
    engine = Engine(with: window)
}

internal func addEvent(with data: Event) {
    sysOut(message: "\(data.id): \(data.value)", with: .Verbose)
}

internal func addEvent(of type: Int64, with data: Int64) {
    sysOut(message: "\(type): \(data)", with: .Verbose)
}

public class Engine {
    let window: HWND

    public init(with window: HWND) {
        self.window = window
        loggerInit()
        sysOut(message: "Engine initialized", with: .Verbose)
    }

    deinit {

    }
    
    func update() -> Void {

    }

}
