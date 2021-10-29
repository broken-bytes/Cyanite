import WinSDK

var engine: Engine!

public struct Event {
    var id: UInt64
    var value: UInt64
}


internal func createEngine(with window: HWND) {
    engine = Engine(with: window)
}

internal func addEvent(with data: Event) {
    engine.logger.log(message: "\(data.id): \(data.value)", with: .Verbose)
}

internal func addEvent(of type: Int64, with data: Int64) {
    engine.logger.log(message: "\(type): \(data)", with: .Verbose)
}

public class Engine {
    let window: HWND
    var logger: Logger

    public init(with window: HWND) {
        self.window = window
        logger = Logger()
        logger.log(message: "\(MemoryLayout<Event>.size)", with: .Error)
        logger.log(message: "\(MemoryLayout<Event>.stride)", with: .Error)
        logger.log(message: "\(MemoryLayout<Event>.alignment)", with: .Error)
    }

    deinit {

    }
    
    func update() -> Void {

    }

}
