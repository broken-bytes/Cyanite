import WinSDK

var engine: Engine!


public func createEngine(with window: HWND) {
    engine = Engine(with: window)
}

public class Engine {
    let window: HWND
    var logger: Logger

    public init(with window: HWND) {
        self.window = window
        logger = Logger()        
    }

    deinit {
        
    }
    

    func update() -> Void {

    }

}
